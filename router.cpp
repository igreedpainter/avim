
#include <string>
#include <unistd.h>
#include <boost/format.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/make_shared.hpp>

#include <avtcpif.hpp>
#include <avproto.hpp>

static boost::asio::io_service io_service;

avkernel avcore(io_service);

// 路由器接受用户地址后，每次都生成一个新的随机地址的
static std::string  get_new_radom_address()
{
	static int t = 0;

	return boost::str( boost::format("avrouter_%1@avplayer.org") % t ++ );
}

// 处理客户端
static void process_client(boost::asio::yield_context yielder, boost::shared_ptr<boost::asio::ip::tcp::socket> client_sock)
{
	boost::system::error_code ec;

	// TODO rsa key 加载
	RSA * rsa_key = NULL; // RSA_new();
	X509 * x509_cert = NULL;
	// 生成一个新的 av地址
	std::string me_addr = get_new_radom_address();

	// 创建一个 tcp 的 avif 设备，然后添加进去, TODO, 证书也应该传进去
	boost::shared_ptr<avtcpif> avinterface;

	avinterface.reset(new avtcpif(client_sock, me_addr, rsa_key, x509_cert) );

	avinterface->async_master_handshake(1, yielder[ec]);

	avcore.add_interface(avinterface);

	// 添加路由表
	avcore.add_route(avinterface->remote_addr(), me_addr, avinterface->get_ifname());
}

static void async_acceptor(boost::asio::yield_context yielder, int port)
{
	// 创建 tcp 端口，进入监听
	boost::asio::ip::tcp::acceptor listen_sock(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v6(), port));

	while(true)
	{
		boost::system::error_code ec;
		boost::shared_ptr<boost::asio::ip::tcp::socket> client_sock(new boost::asio::ip::tcp::socket(io_service));
		listen_sock.async_accept(*client_sock, yielder[ec]);

		// 进入 client 处理
		if(!ec)
			boost::asio::spawn(io_service, boost::bind(&process_client, _1, client_sock));
	}
}

int main()
{
	int port = 24950; // "av" = 0x6176 = 24950
	// 开启 av协议处理

	boost::asio::spawn(io_service, boost::bind(&async_acceptor, _1, port));

	// 无限睡眠，客户端的话就开始写客户端的逻辑吧
	io_service.run();
}
