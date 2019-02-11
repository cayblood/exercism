cmake_minimum_required(VERSION 3.13)

project(Isogram)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_isogram src/isogram.c test/test_isogram.c test/vendor/unity.c)