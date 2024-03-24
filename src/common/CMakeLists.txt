cmake_minimum_required(VERSION 3.22)
project(libarch-utils)

add_library(libarch-utils common.hpp
        errorHandler.cpp errorHandler.hpp
        btrfsUtils.cpp btrfsUtils.hpp filePathDecoder.cpp filePathDecoder.hpp)

