/*
    <one line to give the library's name and an idea of what it does.>
    Copyright (C) 2013  microcai <microcai@fedoraproject.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef _AVIM_BASE_SERVER_H
#define _AVIM_BASE_SERVER_H

#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

namespace avim{
namespace base{

class server {
	boost::shared_ptr<boost::asio::ip::tcp::socket> m_socket;
public:
	server(boost::shared_ptr<boost::asio::ip::tcp::socket> socket);
};

} // namespace base
} // namespace avim
#endif // _AVIM_BASE_SERVER_H
