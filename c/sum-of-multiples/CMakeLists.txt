cmake_minimum_required(VERSION 3.13)

project(SumOfMultiples)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_sum_of_multiples src/sum_of_multiples.c test/test_sum_of_multiples.c test/vendor/unity.c)
