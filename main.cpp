
#include <string>
#include <unistd.h>
#include <boost/concept_check.hpp>

#include <avproto.hpp>

int main()
{
	// 开启 av协议处理
	av_start();

	av_config("一个 RSA 私钥", "和一个 RSA 公钥构成的av证书");

	// 无限睡眠，客户端的话就开始写客户端的逻辑吧
	sleep(-1);
}
