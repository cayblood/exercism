cmake_minimum_required(VERSION 3.13)

project(TwoFer)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/two_fer.c src/two_fer.h src/two_fer.c src/two_fer.h src/two_fer.c src/two_fer.h src/two_fer.c src/two_fer.h src/two_fer.c src/two_fer.h src/two_fer.c src/two_fer.h)

add_executable(test_two_fer src/two_fer.c test/test_two_fer.c test/vendor/unity.c)
