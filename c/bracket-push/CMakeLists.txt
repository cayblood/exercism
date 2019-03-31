cmake_minimum_required(VERSION 3.13)

project(BracketPush)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_bracket_push src/bracket_push.c test/test_bracket_push.c test/vendor/unity.c)
