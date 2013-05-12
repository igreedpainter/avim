// Copyright 2006 Nemanja Trifunovic
// Copyright 2011 Jack.arain
/*
Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/


#ifndef UTF8_FOR_CPP_2675DCD0_9480_4C0C_B92A_CC14C027B731
#define UTF8_FOR_CPP_2675DCD0_9480_4C0C_B92A_CC14C027B731

#include <string>
#include <boost/version.hpp>

#if BOOST_VERSION >= 104800

#include <boost/locale.hpp>
#include <boost/locale/utf.hpp>

inline std::string wide_utf8( const std::wstring &source )
{
	return boost::locale::conv::utf_to_utf<char>( source );
}

inline std::wstring utf8_wide( std::string const &source )
{
	return boost::locale::conv::utf_to_utf<wchar_t>( source );
}

#else

#include <stdint.h>
#include <wchar.h>

#include "./utf/unchecked.h"

inline std::string wide_utf8( const std::wstring &source )
{
	std::string result;

	if( sizeof( wchar_t ) == 32 )
		utf8::unchecked::utf32to8<>( source.begin(), source.end(), result.begin() );
	else if( sizeof( wchar_t ) == 16 )
		utf8::unchecked::utf16to8( source.begin(), source.end(), result.begin() );

	return result;
}

inline std::wstring utf8_wide( std::string const &source )
{
	std::wstring result;

	if( sizeof( wchar_t ) == 32 )
		utf8::unchecked::utf8to32( source.begin(), source.end(), result.begin() );
	else if( sizeof( wchar_t ) == 16 )
		utf8::unchecked::utf8to16( source.begin(), source.end(), result.begin() );

	return result;
}

#endif

#endif // UTF8_FOR_CPP_2675DCD0_9480_4C0C_B92A_CC14C027B731
