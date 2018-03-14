cmake_minimum_required(VERSION 3.1.0)
project(SDX)

set(USE_ONLY_CPP14_FEATURES OFF CACHE BOOL "If enabled, SDX will use only C++14 features when compile.")
set(COMPILE_INTO_DYNAMIC_LIBRARY OFF CACHE BOOL "If enabled, SDX will compile into dynamic(or shared) library.")
set(USE_ONLY_MULTIBYTE_STRINGS OFF CACHE BOOL "If enabled, SDX will use only multibyte strings.")

add_subdirectory(src/sdx/basic)
add_subdirectory(src/sdx/graphics2)
add_subdirectory(src/sdx/math)