cmake_minimum_required(VERSION 3.13)

project(Bob)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/bob.c src/bob.h src/bob.c src/bob.h src/bob.c src/bob.h)

add_executable(test_bob src/bob.c test/test_bob.c test/vendor/unity.c)
