#ifndef SDX_HEADER_MATH_NUMERIC_ALLOCATOR_HPP
#define SDX_HEADER_MATH_NUMERIC_ALLOCATOR_HPP

#include <algorithm>
#include <array>
#include <cstddef>
#include <iterator>
#include <stdexcept>

namespace sdx
{
	namespace details
	{
		namespace math
		{
			template<typename Block_>
			class numeric_allocator_iterator_
			{
				template<typename Block_>
				friend numeric_allocator_iterator_<Block_> operator+(typename numeric_allocator_iterator_<Block_>::difference_type value,
					const numeric_allocator_iterator_<Block_>& iterator) noexcept;

			public:
				using difference_type = std::ptrdiff_t;
				using value_type = Block_;
				using pointer = value_type*;
				using reference = value_type&;
				using iterator_category = std::random_access_iterator_tag;

			private:
				using my_ = numeric_allocator_iterator_<Block_>;
				using const_pointer_ = const value_type*;
				using const_reference_ = const value_type&;

			public:
				numeric_allocator_iterator_() = default;
				numeric_allocator_iterator_(const my_& iterator) noexcept
					: data_(iterator.data_)
				{}
				numeric_allocator_iterator_(my_&& iterator) noexcept
					: data_(iterator.data_)
				{}
				~numeric_allocator_iterator_() = default;
				
			private:
				numeric_allocator_iterator_(value_type* data) noexcept
					: data_(data)
				{}

			public:
				my_& operator=(const my_& iterator) noexcept
				{
					data_ = iterator.data_;
					return *this;
				}
				my_& operator=(my_&& iterator) noexcept
				{
					data_ = iterator.data_;
					return *this;
				}
				bool operator==(const my_& iterator) const noexcept
				{
					return data_ == iterator.data_;
				}
				bool operator!=(const my_& iterator) const noexcept
				{
					return data_ != iterator.data_;
				}
				bool operator>(const my_& iterator) const noexcept
				{
					return data_ > iterator.data_;
				}
				bool operator>=(const my_& iterator) const noexcept
				{
					return data_ >= iterator.data_;
				}
				bool operator<(const my_& iterator) const noexcept
				{
					return data < iterator.data_;
				}
				bool operator<=(const my_& iterator) const noexcept
				{
					return data <= iterator.data_;
				}
				my_ operator+(difference_type value) const noexcept
				{
					difference_type rhs = value * sizeof(value_type);

					return reinterpret_cast<value_type*>(reinterpret_cast<std::uintptr_t>(data_) + rhs);
				}
				my_ operator-(const my_& iterator) const noexcept
				{
					return (reinterpret_cast<std::uintptr_t>(data_) - reinterpret_cast<std::uintptr_t>(iterator.data_)) / sizeof(value_type);
				}
				my_ operator-(difference_type value) const noexcept
				{
					difference_type rhs = value * sizeof(value_type);

					return reinterpret_cast<value_type*>(reinterpret_cast<std::uintptr_t>(data_) + rhs);
				}
				my_& operator+=(difference_type value) noexcept
				{
					difference_type rhs = value * sizeof(value_type);
					data_ = reinterpret_cast<value_type*>(reinterpret_cast<std::uintptr_t>(data_) + rhs);

					return *this;
				}
				my_& operator-=(difference_type value) noexcept
				{
					difference_type rhs = value * sizeof(value_type);
					data_ = reinterpret_cast<value_type*>(reinterpret_cast<std::uintptr_t>(data_) - rhs);

					return *this;
				}
				const_reference_ operator[](difference_type index) const noexcept
				{
					return data_[index];
				}
				reference operator[](difference_type index) noexcept
				{
					return data_[index];
				}
				const_pointer_ operator->() const noexcept
				{
					return data_;
				}
				pointer operator->() noexcept
				{
					return data_;
				}
				my_& operator++() noexcept
				{
					++data_;
					return *this;
				}
				my_ operator++(int) const noexcept
				{
					my_ result = *this;
					return ++result;
				}
				my_& operator--() noexcept
				{
					--data_;
					return *this;
				}
				my_ operator--(int) const noexcept
				{
					my_ result = *this;
					return --result;
				}
				const_reference_ operator*() const noexcept
				{
					return *data_;
				}
				reference operator*() noexcept
				{
					return *data_;
				}

			private:
				value_type* data_ = nullptr;
			};

			template<typename Block_>
			numeric_allocator_iterator_<Block_> operator+(typename numeric_allocator_iterator_<Block_>::difference_type value,
				const numeric_allocator_iterator_<Block_>& iterator) noexcept
			{
				decltype(value) rhs = value * sizeof(Block_);

				return reinterpret_cast<Block_*>(reinterpret_cast<std::uintptr_t>(iterator.data_) + rhs);
			}
		}
	}

	namespace math
	{
		template<typename Block_, std::size_t Size_>
		class numeric_allocator
		{
		public:
			using value_type = Block_;
			using iterator = details::math::numeric_allocator_iterator_<Block_>;
			using const_iterator = const iterator;

		private:
			using my_ = numeric_allocator<Block_, Size_>;

		public:
			static constexpr std::size_t size_constant = Size_;
			static constexpr bool is_dynamic = false;

		public:
			numeric_allocator() = default;
			numeric_allocator(const my_& allocator)
			{
				allocator.copy_to(*this);
			}
			numeric_allocator(my_&& allocator) noexcept
			{
				allocator.move_to(*this);
			}
			~numeric_allocator() = default;

		public:
			my_& operator=(const my_& allocator)
			{
				allocator.copy_to(*this);

				return *this;
			}
			my_& operator=(my_&& allocator) noexcept
			{
				allocator.move_to(*this);

				return *this;
			}
			const value_type& operator[](std::size_t index) const noexcept
			{
				return data_[index];
			}
			value_type& operator[](std::size_t index) noexcept
			{
				return data_[index];
			}

		public:
			const value_type& at(std::size_t index) const
			{
				if (index >= size_constant)
					throw std::out_of_range("'index' is out of range.");

				return operator[](index);
			}
			value_type& at(std::size_t index)
			{
				if (index >= size_constant)
					throw std::out_of_range("'index' is out of range.");

				return operator[](index);
			}

		public:
			void allocate(std::size_t)
			{}
			void reallocate(std::size_t)
			{}
			void deallocate()
			{}
			void fill_zero()
			{
				std::fill(data_, data_ + size_constant, 0);
			}
			void copy_to(my_& allocator) const
			{
				move_to(allocator);
			}
			void move_to(my_&& allocator) noexcept
			{
				for (std::size_t i = 0; i < size_constant; ++i)
				{
					allocator.data_[i] = data_[i];
				}
			}
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
			value_type data_[size_constant];
		};

		template<typename Block_>
		class numeric_allocator<Block_, 0>
		{
			// TODO
		};
	}
}

#endif