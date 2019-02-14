cmake_minimum_required(VERSION 3.13)
project(WordCount)
include_directories(src test/vendor)
add_executable(test_word_count src/word_count.c test/test_word_count.c test/vendor/unity.c)