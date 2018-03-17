#ifndef SDX_HEADER_MATH_WHOLE_NUMBER_HPP
#define SDX_HEADER_MATH_WHOLE_NUMBER_HPP

#include <sdx/math/numeric_allocator.hpp>

#include <cstdint>

namespace sdx
{
	namespace math
	{
		template<typename Allocator_>
		class basic_whole_number
		{
		public:
			using allocator_type = Allocator_;

		private:
			using my_ = basic_whole_number<Allocator_>;

		public:
			basic_whole_number() = default;
			basic_whole_number(const my_& number)
			{
				number.allocator_.copy_to(this->allocator_);
			}
			basic_whole_number(my_&& number) noexcept
			{
				number.allocator_.move_to(this->allocator_);
			}
			~basic_whole_number()
			{
				allocator_.deallocate();
			}

		public:
			my_& operator=(const my_& number)
			{
				number.allocator_.copy_to(this->allocator_);
				return *this;
			}
			my_&& operator=(my_&& number) noexcept
			{
				number.allocator_.move_to(this->allocator_);
				return *this;
			}

		private:
			allocator_type allocator_;
		};

		using whole_number = basic_whole_number<numeric_allocator<std::uint32_t, 0>>;
		using whole_number32 = basic_whole_number<numeric_allocator<std::uint8_t, 4>>;
		using whole_number64 = basic_whole_number<numeric_allocator<std::uint8_t, 8>>;
		using whole_number128 = basic_whole_number<numeric_allocator<std::uint8_t, 16>>;
		using whole_number256 = basic_whole_number<numeric_allocator<std::uint8_t, 32>>;
		using whole_number512 = basic_whole_number<numeric_allocator<std::uint8_t, 64>>;
		using whole_number1024 = basic_whole_number<numeric_allocator<std::uint8_t, 128>>;
	}
}

#endif