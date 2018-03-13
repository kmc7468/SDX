#ifndef SDX_HEADER_MATH_NUMERIC_ALLOCATOR_HPP
#define SDX_HEADER_MATH_NUMERIC_ALLOCATOR_HPP

#include <array>
#include <cstddef>
#include <stdexcept>

namespace sdx
{
	namespace math
	{
		template<typename Block_, std::size_t Size_>
		class numeric_allocator
		{
		public:
			using block_type = Block_;

		public:
			static constexpr std::size_t size_constant = Size_;
			static constexpr bool is_dynamic = false;

		public:
			const block_type& operator[](std::size_t index) const noexcept
			{
				return data_[index];
			}
			block_type& operator[](std::size_t index) noexcept
			{
				return data_[index];
			}

		public:
			const block_type& at(std::size_t index) const
			{
				if (index >= size_constant)
					throw std::out_of_range("'index' is out of range.");

				return operator[](index);
			}
			block_type& at(std::size_t index)
			{
				if (index >= size_constant)
					throw std::out_of_range("'index' is out of range.");

				return operator[](index);
			}

		public:
			bool allocated() const noexcept
			{
				return true;
			}
			bool reallocatable() const noexcept
			{
				return false;
			}

		public:
			std::size_t size() const noexcept
			{
				return size_constant;
			}

		private:
			Block_ data_[size_constant];
		};

		template<typename Block_>
		class numeric_allocator<Block_, 0>
		{
			// TODO
		};
	}
}

#endif