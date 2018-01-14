#ifndef SDX_HEADER_MACRO_UTILITY_CANNOT_COMPARE_CLASS_HPP
#define SDX_HEADER_MACRO_UTILITY_CANNOT_COMPARE_CLASS_HPP

#define SDX_CANNOT_COMPARE_CLASS(class_name)							\
public:																	\
	bool operator==(const class_name& class_name) const = delete;		\
	bool operator!=(const class_name& class_name) const = delete;		\

#endif