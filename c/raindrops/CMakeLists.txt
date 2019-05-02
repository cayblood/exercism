cmake_minimum_required(VERSION 3.13)

project(Raindrops)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/raindrops.c src/raindrops.h src/raindrops.c src/raindrops.h src/raindrops.c src/raindrops.h src/raindrops.c src/raindrops.h src/raindrops.c src/raindrops.h)

add_executable(test_raindrops src/raindrops.c test/test_raindrops.c test/vendor/unity.c)
