cmake_minimum_required(VERSION 3.20)
project(arch-utils)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

add_executable(arch-utils gennrand.cpp)
set_target_properties(arch-utils PROPERTIES OUTPUT_NAME "genrand")
