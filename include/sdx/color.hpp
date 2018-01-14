#ifndef SDX_HEADER_COLOR_HPP
#define SDX_HEADER_COLOR_HPP

#include <cstdint>
#include <limits>

namespace sdx
{
	template<typename element_>
	class basic_color
	{
	public:
		using element_type = element_;

	private:
		using my_ = basic_color<element_>;

	public:
		constexpr basic_color() noexcept
			: r_(std::numeric_limits<element_>::max()), g_(std::numeric_limits<element_>::max()),
			b_(std::numeric_limits<element_>::max()), a_(std::numeric_limits<element_>::max())
		{}
		constexpr basic_color(element_ r, element_ g, element_ b) noexcept
			: r_(r), g_(g), b_(b), a_(std::numeric_limits<element_>::max())
		{}
		constexpr basic_color(element_ r, element_ g, element_ b, element_ a) noexcept
			: r_(r), g_(g), b_(b), a_(a)
		{}
		constexpr basic_color(const my_& color) noexcept
			: r_(color.r_), g_(color.g_), b_(color.b_), a_(color.a_)
		{}

	public:
		my_& operator=(const my_& color) noexcept
		{
			return assign(color);
		}
		constexpr bool operator==(const my_& color) const noexcept
		{
			return equal(color);
		}
		constexpr bool operator!=(const my_& color) const noexcept
		{
			return !equal(color);
		}

	public:
		my_& assign(const my_& color) noexcept
		{
			r_ = color.r_;
			g_ = color.g_;
			b_ = color.b_;
			a_ = color.a_;
			return *this;
		}
		constexpr bool equal(const my_& color) const noexcept
		{
			return r_ == color.r_ && g_ == color.g_ && b_ == color.b_ && a_ == color.a_;
		}

	public:
		constexpr element_ r() const noexcept
		{
			return r_;
		}
		element_ r(element_ new_r) noexcept
		{
			return r_ = new_r;
		}
		constexpr element_ g() const noexcept
		{
			return g_;
		}
		element_ g(element_ new_g) noexcept
		{
			return g_ = new_g;
		}
		constexpr element_ b() const noexcept
		{
			return b_;
		}
		element_ b(element_ new_b) noexcept
		{
			return b_ = new_b;
		}
		constexpr element_ a() const noexcept
		{
			return a_;
		}
		element_ a(element_ new_a) noexcept
		{
			return a_ = new_a;
		}

	private:
		element_ r_;
		element_ g_;
		element_ b_;
		element_ a_;
	};

	using color8 = basic_color<std::uint8_t>;
}

#endif