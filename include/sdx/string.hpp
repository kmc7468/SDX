#ifndef SDX_HEADER_STRING_HPP
#define SDX_HEADER_STRING_HPP

#include <sdx/encoding.hpp>

#include <cstdint>
#include <string>

namespace sdx
{
	class string
	{
	public:
		string() = default;
		string(const string& string);
		string(string&& string) noexcept;
		~string() = default;

	public:
		string& operator=(const string& string);
		string& operator=(string&& string) noexcept;
		bool operator==(const string& string) const;
		bool operator!=(const string& string) const;

	public:
		string& assign(const string& string);
		string& assign(string&& string) noexcept;
		bool equal(const string& string) const;

	private:
		std::basic_string<std::uint8_t> data_;
		encoding::ptr encoding_;
	};
}

#endif