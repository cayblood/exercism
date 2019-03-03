cmake_minimum_required(VERSION 3.13)

project(Hamming)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_hamming src/hamming.c test/test_hamming.c test/vendor/unity.c)