cmake_minimum_required(VERSION 3.13)

project(ComplexNumbers)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_complex_numbers src/complex_numbers.c test/test_complex_numbers.c test/vendor/unity.c)
