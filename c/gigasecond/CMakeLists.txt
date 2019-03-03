cmake_minimum_required(VERSION 3.13)

project(Gigasecond)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_gigasecond src/gigasecond.c test/test_gigasecond.c test/vendor/unity.c)