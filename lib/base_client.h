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

#include <protocol/avim-base.pb.h>

namespace avim {
namespace base{

typedef avim::proto::base::avID avid;

// -------------------------------------------------------
//
// 这是一个基础类，用于实现avim基础协议。avim 的基础协议用于执行：
//	1 - 客户端认证
//	2 - 消息的可靠转发
//
// avim-im 协议将利用可靠的基础协议实现即使聊天功能.
class client
{
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
		// TODO
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
