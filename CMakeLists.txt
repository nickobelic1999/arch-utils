cmake_minimum_required(VERSION 3.20)
project(arch-utils)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

add_executable(genrand genrand.cpp)
add_executable(popcorn popcorn.cpp)
add_executable(toggle_caps_lock toggle_caps_lock.cpp)

target_link_libraries(toggle_caps_lock X11)
