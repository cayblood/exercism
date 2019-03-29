cmake_minimum_required(VERSION 3.13)

project(Leap)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_leap src/leap.c test/test_leap.c test/vendor/unity.c)
