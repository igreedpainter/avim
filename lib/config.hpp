#pragma once

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socketptr;
