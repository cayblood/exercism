cmake_minimum_required(VERSION 3.13)

project(Meetup)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_meetup src/meetup.c test/test_meetup.c test/vendor/unity.c)