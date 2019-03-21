cmake_minimum_required(VERSION 3.13)

project(BeerSong)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/beer_song.c src/beer_song.h)

add_executable(test_beer_song src/beer_song.c test/test_beer_song.c test/vendor/unity.c)
