cmake_minimum_required(VERSION 3.13)

project(BinarySearch)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_binary_search src/binary_search.c test/test_binary_search.c test/vendor/unity.c)
