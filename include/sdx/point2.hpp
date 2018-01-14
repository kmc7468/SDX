#ifndef SDX_HEADER_POINT2_HPP
#define SDX_HEADER_POINT2_HPP

#include <cstdint>

namespace sdx
{
	template<typename element_>
	class basic_point2
	{
	public:
		using element_type = element_;

	private:
		using my_ = basic_point2<element_>;

	public:
		constexpr basic_point2() noexcept
			: x_(0), y_(0)
		{}
		constexpr basic_point2(element_ x, element_ y) noexcept
			: x_(x), y_(y)
		{}
		constexpr basic_point2(const my_& point) noexcept
			: x_(point.x_), y_(point.y_)
		{}

	public:
		my_& operator=(const my_& point) noexcept
		{
			return assign(point);
		}
		constexpr bool operator==(const my_& point) const noexcept
		{
			return equal(point);
		}
		constexpr bool operator!=(const my_& point) const noexcept
		{
			return !equal(point);
		}
		
	public:
		my_& assign(const my_& point) noexcept
		{
			x_ = point.x_;
			y_ = point.y_;
			return *this;
		}
		constexpr bool equal(const my_& point) const noexcept
		{
			return x_ == point.x_ && y_ == point.y_;
		}

	public:
		constexpr element_ x() const noexcept
		{
			return x_;
		}
		element_ x(element_ new_x) noexcept
		{
			return x_ = new_x;
		}
		constexpr element_ y() const noexcept
		{
			return y_;
		}
		element_ y(element_ new_y) noexcept
		{
			return y_ = new_y;
		}

	private:
		element_ x_;
		element_ y_;
	};

	using point2 = basic_point2<std::int32_t>;
	using point2f = basic_point2<float>;
}

#endif