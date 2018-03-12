#ifndef SDX_HEADER_MATH_NUMERIC_ALLOCATOR_HPP
#define SDX_HEADER_MATH_NUMERIC_ALLOCATOR_HPP

#include <cstddef>

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
			bool is_allocated() const noexcept
			{
				return true;
			}
			std::size_t size() const noexcept
			{
				return Size_;
			}

		private:
			Block_ data_[Size_];
		};

		template<typename Block_>
		class numeric_allocator<Block_, 0>
		{
		public:
			using block_type = Block_;

		public:
			static constexpr std::size_t size_constant = 0;
			static constexpr bool is_dynamic = true;

		public:
			bool is_allocated() const noexcept
			{
				return data_ != nullptr;
			}
			std::size_t size() const noexcept
			{
				return size_;
			}

		private:
			Block_* data_ = nullptr;
			std::size_t size_ = 0;
		};
	}
}

#endif