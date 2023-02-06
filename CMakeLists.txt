cmake_minimum_required(VERSION 3.20)
project(arch-utils)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

set(COMMON arch_util_common.hpp)

add_executable(genrand genrand.cpp ${COMMON})
add_executable(popcorn popcorn.cpp ${COMMON})
add_executable(toggle_caps_lock toggle_caps_lock.cpp ${COMMON})
add_executable(usercheck usercheck.cpp ${COMMON})
add_executable(btrfs_example btrfs_api_example.cpp ${COMMON})


target_link_libraries(toggle_caps_lock X11)
target_link_libraries(btrfs_example btrfs)
