/*
    a client library to access avim-server
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


#ifndef _AVIM_CLIENT_H
#define _AVIM_CLIENT_H

#include <boost/asio.hpp>

namespace avim {

class client
{
public:
	client(boost::asio::io_service & io_service);

private:
	boost::asio::io_service & m_io_service;
};

} // namespace avim

#endif // CLIENT_H
