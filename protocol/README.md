protocol
====

协议相关

这里存放　protobuf 定义文件，构建的时候自动生成　.cc .hpp 文件。

.cc 文件为自动生成的消息序列化和反序列化代码，并不是真正的协议实现。 

要实现协议，还要写 TCP/SSL 连接处理相关的代码。这个交给 client/server 各自实现。



自动生成的 .cc .h 文件博士已经提交，请直接使用吧。

====

# avimbase 协议解释

avimbase 协议是一个分布式的高可靠消息路由协议. avimbase 采取的策略就是让 avim-server 充当路由器. avim-server 负责认证自己名下的客户端. 认证后的客户端就拥有了向全世界的 avim 发送消息的能力. 当然, 类似邮件, 也会有垃圾消息的问题, avim-server 可以设置垃圾过滤解决问题.

avimbase 是个基于消息而不是流的协议. avimbase另外有一个流模式. 通常用于执行文件传输和多媒体数据.



