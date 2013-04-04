/*
    <one line to give the library's name and an idea of what it does.>
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


#ifndef _AVIM_BASE_SERVER_H
#define _AVIM_BASE_SERVER_H

#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

#include <protocol/avim-base.pb.h>

namespace avim{
namespace base{

typedef avim::proto::base::avID avid;

class server {
	boost::shared_ptr<boost::asio::ip::tcp::socket> m_socket;
	// TODO, 解决多线程访问冲突问题. 最好是将 avdb 封装到一个类中.
	boost::shared_ptr<boost::asio::ip::tcp::socket> avdb_socket;
public:
	server(boost::shared_ptr<boost::asio::ip::tcp::socket> client_socket,
		boost::shared_ptr<boost::asio::ip::tcp::socket> avdb_socket);

	// ---------------------
	//
	// async_accept 用于异步接受客户端的登录.
	// avim::base::server 将于 avim-db 进行通信以认证账户信息.
	// async_accept 对于没有在指定的时间内发送登录包的 “伪” 客户端踢掉，节约服务器端资源.
	// 执行过 认证后， base_server 变成一个传输代理，使用 async_read/async_write
	// 执行数据包收发即可
	//
	// handler 的类型为
	// void accept_handler(const boost::system::error_code & ec, const avim::base::avid & avid_connected);
	template<class Handle>
	void async_accept(Handle handle);

	// --------------------
	// 异步读取客户端传来的信息
	// avim::base::server 内部会处理掉一些内部协议，只有 avim-base protocol
	// 暴露给上层的消息才从这里读取的到.
	//
	// buffer 是一个可写的缓冲区，调用者保留所有权，因此必须保证整个操作期间buffer保持有效
	// 可以使用 boost::asio::buffer, 参考 boost::asio::async_read
	//
	// handler 类型是
	// void read_handler(const boost::system::error_code & ec, // 操作结果
	// 					 std::size_t bytes_transfered // 消息的字节数
	//					 const std::vector<avim::base::avid>	& rcpts // 消息目的地 )
	// {
	//		if (ec){
	//			// 错误处理
	//		}
	// }

	template<class MutableBuffers, class Handler>
	void async_read_some(MutableBuffers & buffer, BOOST_ASIO_MOVE_ARG(Handler) handler);

	// ---------------------
	// 异步发送一个 avim 消息包给客户端
	// avim::base::server 内部会处理掉消息重发等细节
	//
	// buffer 是待发送的消息，调用者保留所有权，因此必须保证整个操作期间buffer保持有效. 请参考 boost::asio::async_write
	// handler 格式为
	// void write_handler( const boost::system::error_code & ec, /*操作结果*/)
	// {
	//
	// }
	//
	template<class ConstBuffers, class Handler>
	void async_write_some(ConstBuffers buffer, BOOST_ASIO_MOVE_ARG(Handler) handler)
	{
	}

};

} // namespace base
} // namespace avim
#endif // _AVIM_BASE_SERVER_H
