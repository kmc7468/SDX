#ifndef SDX_HEADER_POINT3_HPP
#define SDX_HEADER_POINT3_HPP

#include <cstdint>

namespace sdx
{
	template<typename element_>
	class basic_point3
	{
	public:
		using element_type = element_;

	private:
		using my_ = basic_point3<element_>;

	public:
		constexpr basic_point3() noexcept
			: x_(0), y_(0), z_(0)
		{}
		constexpr basic_point3(element_ x, element_ y, element_ z) noexcept
			: x_(x), y_(y), z_(z)
		{}
		constexpr basic_point3(const my_& point) noexcept
			: x_(point.x_), y_(point.y_), z_(point.z_)
		{}

	public:
		my_ & operator=(const my_& point) noexcept
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
		my_ & assign(const my_& point) noexcept
		{
			x_ = point.x_;
			y_ = point.y_;
			z_ = point.z_;
			return *this;
		}
		constexpr bool equal(const my_& point) const noexcept
		{
			return x_ == point.x_ && y_ == point.y_ && z_ == point.z_;
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
		constexpr element_ z() const noexcept
		{
			return z_;
		}
		element_ z(element_ new_z) noexcept
		{
			return z_ = new_z;
		}

	private:
		element_ x_;
		element_ y_;
		element_ z_;
	};

	using point3 = basic_point3<std::int32_t>;
	using point3f = basic_point3<float>;
}

#endif