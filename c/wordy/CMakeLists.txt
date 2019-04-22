cmake_minimum_required(VERSION 3.13)

project(Wordy)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/wordy.c src/wordy.h src/wordy.c src/wordy.h src/wordy.c src/wordy.h src/wordy.c src/wordy.h)

add_executable(test_wordy src/wordy.c test/test_wordy.c test/vendor/unity.c)
