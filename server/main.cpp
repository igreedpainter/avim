#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

// 创建 avim::im::server 对象咯.
static void avim_server_accept_new_client(boost::shared_ptr<boost::asio::ip::tcp::socket> socket)
{
	// TODO
}

int main(int argc, char **argv)
{
	boost::asio::io_service io_service;
	boost::asio::io_service::work work(io_service);
    unsigned int num_of_cpus =  boost::thread::hardware_concurrency();
	for (int i=0 ; i <num_of_cpus ; i++)
		boost::thread(boost::bind(&boost::asio::io_service::run, boost::ref(io_service)));

	std::cout << "Hello, world!" << std::endl;

    boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v6(), 8090));

    for (;;){
		typedef boost::asio::ip::tcp::socket Socket;

		boost::shared_ptr<Socket> socket(new Socket(io_service));
		acceptor.accept(*socket);
		// 用接受的socket创建 server
		avim_server_accept_new_client(socket);
	}

    return 0;
}
