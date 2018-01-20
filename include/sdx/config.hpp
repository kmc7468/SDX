#ifndef SDX_HEADER_CONFIG_HPP
#define SDX_HEADER_CONFIG_HPP

#ifdef SDX_COMPILE_INTO_DYNAMIC_LIBRARY
#ifdef _MSC_VER
#ifdef SDX
#define SDX_EXPORT __declspec(dllexport)
#else
#define SDX_EXPORT __declspec(dllimport)
#endif
#else
#define SDX_EXPORT
#endif
#else
#define SDX_EXPORT
#endif

#endif