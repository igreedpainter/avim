/**
 * main.cpp
 * 
 * 简单命令行版的纯文字聊天实现
 * 
 */

#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <protocol/avim-base.pb.h>
#include <protocol/avim-im.pb.h>

#include <lib/base_client.h>

static void login_handler(const boost::system::error_code & ec)
{
	if (!ec){
		// 从 avim::base::client 建立 avim::im::client
	}
}

int main()
{
	boost::asio::io_service io_service;

	boost::asio::signal_set signal_set(io_service);
	signal_set.add(SIGINT);
	signal_set.add(SIGTERM);
#ifdef SIGHUP
	signal_set.add(SIGHUP);
#endif
	signal_set.async_wait(boost::bind(&boost::asio::io_service::stop, boost::ref(io_service)));

	// 创建一下 client 类
	avim::base::client	client_base(io_service);

	client_base.async_login("testuser", "testpasswd", login_handler );

	io_service.run();
    return 0;
}