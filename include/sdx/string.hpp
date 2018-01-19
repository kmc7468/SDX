#ifndef SDX_HEADER_STRING_HPP
#define SDX_HEADER_STRING_HPP

#include <string>

namespace sdx
{
	class string :
#if !defined(_UNICODE) && !defined(UNICODE)
		public std::string
#else
		public std::wstring
#endif
	{};

	using char_t = string::value_type;
}

#endif