/*
    a client library to access avim-server
    Copyright (C) 2013  microcai <microcai@fedoraproject.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef _AVIM_CLIENT_H
#define _AVIM_CLIENT_H

#include <string>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include <boost/type_traits.hpp>
#include <boost/utility/enable_if.hpp>

#include "avproxy.hpp"

#include <protocol/avim-base.pb.h>

#include "boost/coro/yield.hpp"

namespace avim {
namespace base{

typedef avim::proto::base::avID avid;

namespace detail{

template<class AsioStream, class Handler>
struct  client_login_op : boost::coro::coroutine {
	boost::asio::streambuf	&m_sendbuf;
	boost::asio::streambuf	&m_recvbuf;
	AsioStream & m_stream;
	Handler handler;

	client_login_op(AsioStream & _s, boost::asio::streambuf &_sendbuf,
			boost::asio::streambuf	&_recvbuf,
			avid & m_self_src, const std::string & passwd,
			Handler _handler, bool auto_regeister = false)
			  : m_stream(_s), m_sendbuf(_sendbuf), m_recvbuf(_recvbuf), handler(_handler)
	{
		avim::proto::base::avimPacket pkt;
		avid *  src =  m_self_src.New();
		src->CopyFrom(m_self_src);
		pkt.set_allocated_src(src);
		avim::proto::base::avClientControl * avctl = new avim::proto::base::avClientControl;
		// FIXME
		avctl->set_type(avim::proto::base::avClientControl_controltype_LOGIN);
		avctl->set_digest("TEST DIGEST");
		pkt.set_allocated_avctl(avctl);

		// 好，序列化到 streambuf 里.

		std::ostream obuf(&m_sendbuf);
		int32_t l = htonl(pkt.ByteSize());
		obuf.write(reinterpret_cast<char*>(&l), 4);
		pkt.SerializeToOstream(&obuf);

		// 进入 operator 协程过程.
		using namespace boost::asio::ip;
		avproxy::async_connect(m_stream, tcp::resolver::query(m_self_src.domain(), "8090"), *this);
	}

	void operator()(boost::system::error_code ec, std::size_t bytes_transfered = 0)
	{
		int l;
		if (ec){
			m_stream.get_io_service().post(
				boost::asio::detail::bind_handler(handler, ec));
		}
		CORO_REENTER(this)
		{
			// 发送登录包.
			_yield boost::asio::async_write(m_stream, m_sendbuf, *this);
			// 读取
			_yield boost::asio::async_read(m_stream, m_recvbuf.prepare(4), *this);
			m_recvbuf.commit(bytes_transfered);
			// 获取大小
			m_recvbuf.sgetn(reinterpret_cast<char*>(&l), 4);
			_yield boost::asio::async_read(m_stream, m_recvbuf.prepare(l), *this);
			m_recvbuf.commit(bytes_transfered);
			// 反序列化
			process();
		}
	}

	void process()
	{
		std::istream is ( &m_recvbuf );
		avim::proto::base::avimPacket pkt;
		pkt.ParseFromIstream ( is );
		if ( pkt.has_avctl() )
		{
			if (pkt.avctl().type() == 0)
			{
				handler(boost::system::errc::make_error_code(0));
				return ;
			}
			handler(boost::system::errc::make_error_code(0));
		}
	}
};

}

// -------------------------------------------------------
//
// 这是一个基础类，用于实现avim基础协议。avim 的基础协议用于执行：
//	1 - 客户端认证
//	2 - 消息的可靠转发
//
// avim-im 协议将利用可靠的基础协议实现即使聊天功能.
class client : boost::noncopyable
{
	avim::proto::base::avID m_self_src;
	boost::asio::ip::tcp::socket m_socket;
	boost::asio::streambuf	m_sendbuf;
	boost::asio::streambuf	m_recvbuf;

public:
	client(boost::asio::io_service & io_service, const std::string & avimserver = std::string("avim.avplayer.org:8090"), const std::string & application = "avim");

	// -------------------
	// 设置 CA 检查函数 // TODO, 类型？.
	void set_ca_check();

	// -------------------
	// 执行异步登录到 avimserver, 如果用户不存在，就注册一个.
	// handler 的类型是 
	// 
	// void login_handler(const boost::system::error_code & ec, /* 操作结果*/)
	// {
	//		if (ec){
	//			// 错误处理
	//		}
	// }
 
 	template<class Handler>
 	void async_login(const std::string & username, const std::string & passwd,
 				Handler handler, bool auto_regeister = false)
	{
		m_self_src.set_username(username);
		m_self_src.set_resource("test");
		m_self_src.set_useragent("avim-simple-client");
		m_self_src.set_domain("test");
		detail::client_login_op<boost::asio::ip::tcp::socket, Handler>(m_socket, m_sendbuf, m_recvbuf, m_self_src, passwd, handler, auto_regeister);
	}

	// --------------------
	// 开始异步获取服务器传来的信息
	// avim-client 内部会处理掉一些内部协议，只有 avim-base protocol 
	// 暴露给上层的消息才从这里读取的到.
	//
	// buffer 是一个可写的缓冲区，调用者保留所有权，因此必须保证整个操作期间buffer保持有效
	// 可以使用 boost::asio::buffer, 参考 boost::asio::async_read
	//
	// handler 类型是
	// void read_handler(const boost::system::error_code & ec, // 操作结果
	// 					 std::size_t bytes_transfered // 消息的字节数
	//					 const avim::base::avid	& sender_avid	// 消息发送方 )
	// {
	//		if (ec){
	//			// 错误处理
	//		}
	// }

 	template<class MutableBuffers, class Handler>
 	void async_read_some(MutableBuffers & buffer, BOOST_ASIO_MOVE_ARG(Handler) handler);

	// ---------------------
	// 异步发送一个 avim 消息包
	// avim-client 内部会处理掉消息重发等细节
	//
	// rcpts 是一个 avid 的数组. 
	// (注意， 因为使用了模板，所以只要是数组就可以，不管是数组容器还是C形式的数组)
	//
	// buffer 是待发送的消息，调用者保留所有权，因此必须保证整个操作期间buffer保持有效. 请参考 boost::asio::async_write 
	// handler 格式为
	// void write_handler( const boost::system::error_code & ec, // 操作结果
	// 					 const std::vector<avim::base::avid>	& offlined_rcpt // 被离线存储的接收方
	//					 const std::vector<avim::base::avid>	& failed_rcpt // 消息没有成功的接收方 )
	// {
	//	
	// }
	// 
 	template<typename ReciverArray, class ConstBuffers, class Handler>
		typename boost::enable_if<typename boost::is_array<ReciverArray>, void>::type 
	async_write_some(ReciverArray rcpts, ConstBuffers buffer, BOOST_ASIO_MOVE_ARG(Handler) handler)
	{
		// 确保 Reciver  是 avid 的数组
		{avid * T = & rcpts[0];}
	}

	// ---------------------
	// 异步发送一个 avim 消息包
	// avim-client 内部会处理掉消息重发等细节
	//
	// rcptto 是一个 avid , 表示接收方。
	// 
 	template<class ConstBuffers, class Handler>
	void async_write_some(const avid & rcptto, ConstBuffers buffer, BOOST_ASIO_MOVE_ARG(Handler) handler)
	{
		// 确保 Reciver  是 avid 的数组
		avid rcpts[1] = {rcptto};
		async_write_some(rcpts, buffer, handler);
	}
private:
	boost::asio::io_service & m_io_service;
	std::string	m_avimserver;
	std::string m_application;
};

} // namespace base
} // namespace avim

#endif // CLIENT_H
