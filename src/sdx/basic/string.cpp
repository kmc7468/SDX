#include <sdx/string.hpp>

#include <utility>

namespace sdx
{
	string::string(const string& string)
		: data_(string.data_), encoding_(string.encoding_)
	{}
	string::string(string&& string) noexcept
		: data_(std::move(string.data_)), encoding_(std::move(string.encoding_))
	{}

	string& string::operator=(const string& string)
	{
		return assign(string);
	}
	string& string::operator=(string&& string) noexcept
	{
		return assign(std::move(string));
	}
	bool string::operator==(const string& string) const
	{
		return equal(string);
	}
	bool string::operator!=(const string& string) const
	{
		return !equal(string);
	}

	string& string::assign(const string& string)
	{
		data_ = string.data_;
		encoding_ = string.encoding_;
		return *this;
	}
	string& string::assign(string&& string) noexcept
	{
		data_ = std::move(string.data_);
		encoding_ = std::move(string.encoding_);
		return *this;
	}
	bool string::equal(const string& string) const
	{
		return data_ == string.data_ && encoding_->equal(string.encoding_);
	}
}