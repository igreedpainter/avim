
#include <string>
#include <unistd.h>
#include <boost/format.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/make_shared.hpp>

#include <avif.hpp>
#include <avproto.hpp>

static boost::asio::io_service io_service;

// 路由器接受用户地址后，每次都生成一个新的随机地址的
static std::string  get_new_radom_address()
{
	static int t = 0;

	return boost::str( boost::format("avrouter_%1@avplayer.org") % t ++ );
}

// 处理客户端，现在 暂时不处理登录，直接接受
// TODO, 修正 tcp 模式的登录协议
// TODO, 登录过程要交换证书
// TODO  服务器要验证客户端正式确实来自 avplayer.org 签发
static void process_client(boost::asio::yield_context yielder, boost::shared_ptr<boost::asio::ip::tcp::socket> client_sock)
{
	boost::asio::streambuf buf;
	boost::system::error_code ec;

	// 接收用户的 av地址
	int len = boost::asio::async_read_until(*client_sock, buf, "\r\n", yielder[ec]);

	if( ec)
		return;

	std::string useraddr; useraddr.resize(len);

	buf.sgetn(&useraddr[0], len);

	// 生成一个新的 av地址
	std::string me_addr = get_new_radom_address();

	// 返回服务器地址
	boost::asio::async_write(*client_sock, boost::asio::buffer(me_addr), yielder[ec]);
	if( ec )
		return;

	// 创建一个 tcp 的 avif 设备，然后添加进去, TODO, 证书也应该传进去
	boost::shared_ptr<avtcpif> avinterface;

	avinterface.reset(new avtcpif(client_sock, me_addr, useraddr) );

	av_if_handover(avinterface);

	// 添加路由表
	av_route(AVROUTE_ADD, useraddr, me_addr, avinterface->get_ifname());
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
	av_start(&io_service);

	int port = 24950; // "av" = 0x6176 = 24950
	// 开启 av协议处理

	boost::asio::spawn(io_service, boost::bind(&async_acceptor, _1, port));

	// 无限睡眠，客户端的话就开始写客户端的逻辑吧
	io_service.run();
}
