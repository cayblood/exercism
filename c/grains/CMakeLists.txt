cmake_minimum_required(VERSION 3.13)

project(Grains)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_grains src/grains.c test/test_grains.c test/vendor/unity.c)