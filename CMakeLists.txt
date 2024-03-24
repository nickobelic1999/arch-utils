cmake_minimum_required(VERSION 3.22)
project(arch-utils)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(./arch_utils_common)

add_executable(genrand genrand.cpp)
add_executable(popcorn popcorn.cpp)
add_executable(toggle_caps_lock toggle_caps_lock.cpp)
add_executable(usercheck usercheck.cpp)
add_executable(btrfs_example btrfs_api_example.cpp)

add_executable(btrfs_tests btrfs_test.cpp
        arch_utils_common/btrfsUtils.cpp arch_utils_common/btrfsUtils.hpp btrfs_test.cpp
        arch_utils_common/errorHandler.cpp arch_utils_common/errorHandler.hpp)


target_link_libraries(toggle_caps_lock X11)
target_link_libraries(btrfs_example btrfs)

