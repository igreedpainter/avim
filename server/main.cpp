
#include "lib/config.hpp"

#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <protocol/avim-base.pb.h>
#include <protocol/avim-im.pb.h>

#include "acceptor_server.hpp"

namespace avserver {
	// 协程，用于执行用户登录验证.
	//TODO 作为一个 demo ,  先不使用 avdb， 默认全部接受客户认证
	class async_client_auth
	{
	public:
		template<class Handler>
		async_client_auth(socketptr socket, Handler handler){}

		void operator()()
		{
			// handler();
		}

	};
}

class avim_server : public boost::enable_shared_from_this<avim_server>
{
	using boost::enable_shared_from_this<avim_server>::enable_shared_from_this;
	socketptr m_socket;
public:
	avim_server(socketptr socket)
	  : m_socket(socket){}
public:
	void start()
	{
		avserver::async_client_auth(m_socket, boost::bind(&avim_server::handle_client_auth, shared_from_this(), _1));
	}

	void handle_client_auth(boost::system::error_code ec)
	{

	}
};

// 创建 avim::im::server 对象咯.
static void avim_server_accept_new_client(socketptr socket)
{
	// TODO
	boost::make_shared<avim_server>(socket)->start();
}

int main(int argc, char **argv)
{
	boost::asio::io_service io_service;

	boost::asio::signal_set signal_set(io_service);
	signal_set.add(SIGINT);
	signal_set.add(SIGTERM);
#ifdef SIGHUP
	signal_set.add(SIGHUP);
#endif
	signal_set.async_wait(boost::bind(&boost::asio::io_service::stop, boost::ref(io_service)));

	unsigned int num_of_cpus =  boost::thread::hardware_concurrency();
	for (int i=0 ; i < num_of_cpus-1 ; i++)
		boost::thread(boost::bind(&boost::asio::io_service::run, boost::ref(io_service)));

	std::cout << "Hello, world!" << std::endl;

	boost::acceptor_server(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v6(), 8090), avim_server_accept_new_client);

	io_service.run();
    return 0;
}
