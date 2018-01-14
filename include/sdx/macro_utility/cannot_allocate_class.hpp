#ifndef SDX_HEADER_MACRO_UTILITY_CANNOT_ALLOCATE_CLASS_HPP
#define SDX_HEADER_MACRO_UTILITY_CANNOT_ALLOCATE_CLASS_HPP

#define SDX_HEADER_MACRO_UTILITY_CANNOT_ALLOCATE_CLASS_HPP(class_name)	\
public:																	\
	class_name() = delete;												\
	class_name(const class_name& class_name) = delete;					\
	class_name(class_name&& class_name) noexcept = delete;				\
																		\
public:																	\
	class_name& operator=(const class_name& class_name) = delete;		\
	class_name& operator=(class_name&& class_name) noexcept = delete;	\

#endif