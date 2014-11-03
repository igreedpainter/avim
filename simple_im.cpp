
#include <string>
#include <unistd.h>
#include <boost/format.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/make_shared.hpp>

#include <avtcpif.hpp>
#include <avproto.hpp>

#include <openssl/x509.h>
#include <openssl/pem.h>

// 一个非常非常简单的 IM 实现，测试用途

static boost::asio::io_service io_service;

avkernel avcore(io_service);

int main(int argv, char * argc[])
{
	// TODO, 加载 ~/.avim/id_rsa.key 和 ~/.avim/id_rsa.cert

	extern const char * pem_private_key_s;

	BIO * keyfile = BIO_new_mem_buf((void*)pem_private_key_s, strlen(pem_private_key_s));

	RSA * rsa_key = PEM_read_bio_RSAPrivateKey(keyfile, 0, 0, 0);

	BIO_free(keyfile);

	X509 * x509_cert = NULL;

	// 连接到 im.avplayer.org:24950

	boost::asio::ip::tcp::resolver resolver(io_service);

	boost::shared_ptr<boost::asio::ip::tcp::socket> avserver( new boost::asio::ip::tcp::socket(io_service));

	// 连接到 im.avplayer.org:24950
	boost::asio::connect(*avserver, resolver.resolve(boost::asio::ip::tcp::resolver::query("im.avplayer.org", "24950")));

	// TODO 修正登录过程

	std::string me_addr = "test@avplayer.org";

	// 构造 avtcpif
	// 创建一个 tcp 的 avif 设备，然后添加进去, TODO, 证书也应该传进去
	boost::shared_ptr<avtcpif> avinterface;

	avinterface.reset(new avtcpif(avserver, me_addr, rsa_key, x509_cert) );

	avinterface->slave_handshake(0);

	avcore.add_interface(avinterface);

	// 添加路由表
	avcore.add_route(".+@.+", me_addr, avinterface->get_ifname());

	// 进入 IM 过程，发送一个 test  到 test2@avplayer.org
	avcore.sendto("test2@avplayer.org", "test");

	io_service.run();
}

const char * pem_private_key_s =
"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEpAIBAAKCAQEA570CsPq7QOi17mVOHYzpESSYwTabs416JzGH9RbbsJY0lnDz\n\
zmX7YwalHT+VQBJMDuWjl1qnSTrDof7wYvx7OCV84tuSurejF387rotopn99SEnb\n\
5YwJ3vAGsKLzLK05o1i7VZNCPG/Jnsw8XOQjiSFRj+pd5HfZWCvdKFS6Du1IoKIN\n\
4MNM0HMF7sLlZoUR7xzLxRhhNfXjAorjOCdmCXYtINVCC9Xe5UPH9BOhhhXgelif\n\
QJ7fqGLiOOt5RCP8juheFYotw6UEzbuVKf9P14Km55RPTUVG/Od09aw5HoT3Wtba\n\
dSw8UNdBEKSxbZqGFStTKhPwM6Hk7w7xeFSeTQIDAQABAoIBAQDKHghi48y+aDmF\n\
m8Xt8CC3WvwASOi0SgjodkLmePFTqy5iqFF9C2WekQUh5Xr/TvYXaCKut9p//Ej0\n\
2a5AJ4YxCkFKe8gWImSU8dvT+LNlxHw4uHKaWvGhCChNl1IQ/WTwG0wI708t9zIa\n\
1ncvbauwxuakZv1Nb1qZlGhn7L36lUF7xibITZz7xhUvCrDRPE0XoLDDGU8Ay1JO\n\
Xblpzv2Vhl+XxvlYAa5S4D6vQdgBcgMVEPyoNROtPkDY89us7m0Sjbrf9A0sGYIc\n\
OvCZqdyYeXPPiXOeMAhKj/Ev6lUh7MyR06b9eu31U66WvIaD8U+GgkaQt+LTiWh+\n\
q6btM8rhAoGBAPewgfrlFVFbAhnloj8mMt/RFvHupm3HYSfUp/vgmf5OLoPCZQdx\n\
ExQctQwJxqPWp/T3uZCa0bsFjQp1EaF6JwX0qtQZ0ozqf5G0SsUS46vMjhM2Pw9h\n\
oa5pBOKewwrhO/1tFJQmKA8N14SDCffKUadavsztWLCAlYTrVl5OhVG7AoGBAO+D\n\
fh1PEgeZQbHcoM+wKDYc0IkGlyHbdKZtMk1iw95OYIo91xb1gLr/hqpcc0u05vd7\n\
OOZ6S/9BeoXKkNaIDYsTFHRRI5g/n7T/3y5fSvqhsqHE6HU8auvC9rDd3Se8OC3Z\n\
+urChW7vgmySSLlrttmtVpL6oicIlvHNrAJx9SuXAoGADVZi2WjGihf1eAGGiBH9\n\
gVHYA3UPXy/ySlvII+cHQ8tf89Ze7FSpa1bUZO6N1Lq1VpqUUnYTvxdgbeS561ER\n\
kt+G517wmIf0EJt9vzjyK4kbSWuNX72pICQlkDJuXEKeoVnjVsrrM0xSg58uxToO\n\
xY08YvqQ4Qg7hOnLP87InQsCgYBkhjm+L1uP2ODbt4++215lJ77WY++2hBb3ask7\n\
9YHjod2e58mIl02KLojko5y4X5q4r/z3rsiKv36e/J/BiqS0hDOHhi58TefH3cRc\n\
AB7GBmukvbIa0lrFzLQhE10oujSR+fT35uB96QRCcTsYp3686aV2Vr8Lxu0jW4Eg\n\
HZgazQKBgQCpPESX3KeFyJ0ay11l1sKsrD+PpL7fFX1BuziRllzecapsMLoQwIyX\n\
SSQN/on7e20iJ9afasxp1ey5FC5CpiOc0J4QrlHQbVU8LWkX5sQZqPkktyBLztfF\n\
lbB0MWPCd137wh6j2xVEgRtCkqDJmDB7yzw9b6yGOe+/udtee9IPVQ==\n\
-----END RSA PRIVATE KEY-----";
