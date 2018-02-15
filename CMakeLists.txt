cmake_minimum_required(VERSION 3.1.0)
project(SDX)

set(USE_ONLY_CPP14_FEATURES OFF CACHE BOOL "If enabled, SDX will use only C++14 features when compile.")
set(COMPILE_INTO_DYNAMIC_LIBRARY OFF CACHE BOOL "If enabled, SDX will compile into dynamic(or shared) library.")

add_subdirectory(src/sdx/basic)
add_subdirectory(src/sdx/graphics2)

file(GLOB HEADER_LIST ${INCLUDE_DIR}/sdx/*.hpp)
install(FILES ${HEADER_LIST} DESTINATION include/sdx)