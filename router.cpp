
#include <string>
#include <unistd.h>
#include <iostream>
#include <boost/format.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/make_shared.hpp>

#include <openssl/pem.h>
#include <openssl/x509.h>

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

static void async_acceptor(boost::asio::yield_context yielder, int port, RSA * privatekey)
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

const char * test_private_key_s =
"-----BEGIN RSA PRIVATE KEY-----\n\
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\n\
-----END RSA PRIVATE KEY-----";

int main()
{
	int port = 24950; // "av" = 0x6176 = 24950
	// 开启 av协议处理

	BIO * keyfile = BIO_new_mem_buf((void*)test_private_key_s, strlen(test_private_key_s));

	RSA * priv = PEM_read_bio_RSAPrivateKey(keyfile, 0, 0, 0);

	BIO_free(keyfile);

	boost::asio::spawn(io_service, boost::bind(&async_acceptor, _1, port, priv));

	// 无限睡眠，客户端的话就开始写客户端的逻辑吧
	io_service.run();
}
