#ifndef SDX_HEADER_GRAPHICS2_CONTROL_HPP
#define SDX_HEADER_GRAPHICS2_CONTROL_HPP

#include <sdx/string.hpp>

namespace sdx
{
	namespace graphics2
	{
		class control
		{
		public:
			control() = default;
			control(const control& control) = delete;
			control(control&& control) noexcept = delete;
			virtual ~control() = default;

		public:
			control& operator=(const control& control) = delete;
			control& operator=(control&& control) noexcept = delete;
			bool operator==(const control& control) const = delete;
			bool operator!=(const control& control) const = delete;

		private:
			void* handle_ = nullptr;
			sdx::string name_;
		};
	}
}

#endif