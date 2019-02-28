cmake_minimum_required(VERSION 3.13)

project(Pangram)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_pangram src/pangram.c test/test_pangram.c test/vendor/unity.c)