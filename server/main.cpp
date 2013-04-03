#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp>

int main(int argc, char **argv)
{
	boost::asio::io_service io_service;
    std::cout << "Hello, world!" << std::endl;

    unsigned int num_of_cpus =  boost::thread::hardware_concurrency();

    io_service.run();
    return 0;
}
