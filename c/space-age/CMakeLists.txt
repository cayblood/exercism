cmake_minimum_required(VERSION 3.13)

project(SpaceAge)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_space_age src/space_age.c test/test_space_age.c test/vendor/unity.c)