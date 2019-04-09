cmake_minimum_required(VERSION 3.13)

project(DifferenceOfSquares)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/difference_of_squares.c src/difference_of_squares.h src/difference_of_squares.c src/difference_of_squares.h)

add_executable(test_difference_of_squares src/difference_of_squares.c test/test_difference_of_squares.c test/vendor/unity.c)
