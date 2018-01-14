#include <sdx/encoding.hpp>

namespace sdx
{
	bool encoding::operator==(const encoding& encoding) const noexcept
	{
		return equal(encoding);
	}
	bool encoding::operator==(const ptr& encoding) const noexcept
	{
		return equal(encoding);
	}
	bool encoding::operator!=(const encoding& encoding) const noexcept
	{
		return !equal(encoding);
	}
	bool encoding::operator!=(const ptr& encoding) const noexcept
	{
		return equal(encoding);
	}

	bool encoding::equal(const encoding& encoding) const noexcept
	{
		return codepage() == encoding.codepage();
	}
	bool encoding::equal(const ptr& encoding) const noexcept
	{
		return codepage() == encoding->codepage();
	}
}