cmake_minimum_required(VERSION 3.13)
project(Acronym)
include_directories(src test/vendor)
add_executable(test_acronym src/acronym.c test/test_acronym.c test/vendor/unity.c)