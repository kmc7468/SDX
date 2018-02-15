#ifndef SDX_HEADER_ENCODING_HPP
#define SDX_HEADER_ENCODING_HPP
#include <sdx/config.hpp>

#include <sdx/string.hpp>

#include <cstdint>
#include <memory>

namespace sdx
{
	class SDX_EXPORT encoding
	{
	public:
		using ptr = std::shared_ptr<encoding>;

	public:
		encoding() = delete;
		encoding(const encoding& encoding) = delete;
		encoding(encoding&& encoding) noexcept = delete;
		virtual ~encoding() = default;

	public:
		encoding& operator=(const encoding& encoding) = delete;
		encoding& operator=(encoding&& encoding) noexcept = delete;
		bool operator==(const encoding& encoding) const noexcept;
		bool operator==(const ptr& encoding) const noexcept;
		bool operator!=(const encoding& encoding) const noexcept;
		bool operator!=(const ptr& encoding) const noexcept;

	public:
		bool equal(const encoding& encoding) const noexcept;
		bool equal(const ptr& encoding) const noexcept;

	public:
		virtual string name() const = 0;
		virtual std::uint16_t codepage() const noexcept = 0;
	};
}

#endif