cmake_minimum_required(VERSION 3.13)

project(PigLatin)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/pig_latin.c src/pig_latin.h)

add_executable(test_pig_latin src/pig_latin.c test/test_pig_latin.c test/vendor/unity.c)
