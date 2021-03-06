
#include <openssl/dh.h>
#include <openssl/x509.h>
#include <boost/bind.hpp>

#include "serialization.hpp"

#include "avjackif.hpp"
#include "avproto.hpp"

#include "avim_proto/message.pb.h"
#include "avim_proto/user.pb.h"

/*
 * 这个类呢，是用来实现和 JACK 实现的那个 AVROUTER 对接的。也就是 JACK 版本的 AV NETWORK SERVICE PROVIDER
 */
void avjackif::set_pki(boost::shared_ptr<RSA> _key, boost::shared_ptr<X509> cert)
{
    _rsa = _key;
	_x509 = cert;

	unsigned char * CN = NULL;

	auto cert_name = X509_get_subject_name(cert.get());
	auto cert_entry = X509_NAME_get_entry(cert_name,
		X509_NAME_get_index_by_NID(cert_name, NID_commonName, 0)
	);
	ASN1_STRING *entryData = X509_NAME_ENTRY_get_data( cert_entry );
	auto strlengh = ASN1_STRING_to_UTF8(&CN, entryData);
	printf("%s\n",CN);
	std::string commonname((char*)CN, strlengh);
	m_local_addr.reset(new proto::avAddress(av_address_from_string(commonname)));
	OPENSSL_free(CN);
}

// av地址可以从证书里获取，所以外面无需传递进来
avjackif::avjackif(boost::shared_ptr<boost::asio::ip::tcp::socket> _sock)
	: m_sock(_sock)
{
}

avjackif::~avjackif()
{
}

static std::string i2d_X509(X509 * x509)
{
	unsigned char * out = NULL;
	int l = i2d_X509(x509, & out);
	std::string ret((char*)out, l);
	OPENSSL_free(out);
	return ret;
}

bool avjackif::async_handshake(boost::asio::yield_context yield_context)
{
	proto::client_hello client_hello;
	client_hello.set_client("avim");
	client_hello.set_version(0001);

	unsigned char to[512];

	auto dh = DH_new();
	DH_generate_parameters_ex(dh,64,DH_GENERATOR_5,NULL);
	DH_generate_key(dh);

	// 把 g,p, pubkey 传过去
	client_hello.set_random_g((const void*)to, BN_bn2bin(dh->g, to));
	client_hello.set_random_p((const void*)to, BN_bn2bin(dh->p, to));
	client_hello.set_random_pub_key((const void*)to, BN_bn2bin(dh->pub_key, to));

	auto tobesend = av_router::encode(client_hello);

	boost::asio::async_write(*m_sock, boost::asio::buffer(tobesend), yield_context);

	std::uint32_t l;
	boost::asio::async_read(*m_sock, boost::asio::buffer(&l, sizeof(l)), boost::asio::transfer_exactly(4), yield_context);
	auto hostl = htonl(l);
	std::string  buf;

	buf.resize(hostl + 4);
	memcpy(&buf[0], &l, 4);
	hostl = boost::asio::async_read(*m_sock, boost::asio::buffer(&buf[4], hostl),
		boost::asio::transfer_exactly(hostl), yield_context);

	// 解码
	boost::scoped_ptr<proto::server_hello> server_hello((proto::server_hello*)av_router::decode(buf));

	m_remote_addr.reset(new proto::avAddress(
		av_address_from_string(server_hello->server_av_address())));

	auto server_pubkey = BN_bin2bn((const unsigned char *) server_hello->random_pub_key().data(),
		server_hello->random_pub_key().length(), NULL);

	m_shared_key.resize(DH_size(dh));
	// 密钥就算出来啦！
	DH_compute_key(&m_shared_key[0], server_pubkey, dh);
	BN_free(server_pubkey);

    std::printf("key = 0x");
    for (int i=0; i<DH_size(dh); ++i) {
        std::printf("%x%x", (m_shared_key[i] >> 4) & 0xf, m_shared_key[i] & 0xf);
    }
    std::printf("\n");
	DH_free(dh);

	// 接着私钥加密 随机数
	auto singned = RSA_private_encrypt(_rsa.get(), server_hello->random_pub_key());

	proto::login login_packet;
	login_packet.set_user_cert( i2d_X509(_x509.get()) );
	login_packet.set_encryped_radom_key(singned);

	boost::asio::async_write(*m_sock, boost::asio::buffer(av_router::encode(login_packet)),
		yield_context);

	// 读取回应
	boost::asio::async_read(*m_sock, boost::asio::buffer(&l, sizeof(l)),
		boost::asio::transfer_exactly(hostl), yield_context);

	hostl = htonl(l);
	buf.resize(htonl(l) + 4);
	memcpy(&buf[0], &l, 4);
	boost::asio::async_read(*m_sock, boost::asio::buffer(&buf[4], htonl(l)),
		boost::asio::transfer_exactly(hostl), yield_context);
	// 解码
	boost::scoped_ptr<proto::login_result> login_result((proto::login_result*)av_router::decode(buf));

	return login_result.get()->result() == proto::login_result_login_result_code_LOGIN_SUCCEED;
}

#include <boost/thread.hpp>

bool avjackif::handshake()
{
	boost::mutex m;
	boost::condition_variable ready;
	boost::unique_lock<boost::mutex> l(m);
 	boost::asio::spawn(get_io_service(), [&,this](boost::asio::yield_context ctx){
		this->async_handshake(ctx);
		ready.notify_all();
	});
	ready.wait(l);
    return true;
}

void avjackif::async_register_new_user(std::string user_name)
{

}

boost::asio::io_service& avjackif::get_io_service() const
{
	return m_sock->get_io_service();
}

std::string avjackif::get_ifname() const
{
	static unsigned t = 0;
	return boost::str(boost::format("avjack%d") % t++);
}

const proto::avAddress* avjackif::if_address() const
{
	return m_local_addr.get();
}

const proto::avAddress* avjackif::remote_address() const
{
	return m_remote_addr.get();
}

RSA* avjackif::get_rsa_key()
{
	return _rsa.get();
}

X509* avjackif::get_cert()
{
	return _x509.get();
}

boost::shared_ptr<proto::avPacket> avjackif::async_read_packet(boost::asio::yield_context yield_context)
{
	std::string buf;
	std::uint32_t l;
	boost::asio::async_read(*m_sock, boost::asio::buffer(&l, sizeof(l)), yield_context);

	auto hostl = htonl(l);
	buf.resize(htonl(l) + 4);
	memcpy(&buf[0], &l, 4);
	boost::asio::async_read(*m_sock, boost::asio::buffer(&buf[4], htonl(l)),
		boost::asio::transfer_exactly(hostl), yield_context);

	return boost::shared_ptr<proto::avPacket>(dynamic_cast<proto::avPacket*>(av_router::decode(buf)));
}

bool avjackif::async_write_packet(proto::avPacket* pkt, boost::asio::yield_context yield_context)
{
	boost::system::error_code ec;
	boost::asio::async_write(*m_sock, boost::asio::buffer(av_router::encode(*pkt)), yield_context[ec]);
	return !ec;
}

