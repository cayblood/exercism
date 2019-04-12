cmake_minimum_required(VERSION 3.13)

project(SecretHandshake)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/secret_handshake.c src/secret_handshake.h)

add_executable(test_secret_handshake src/secret_handshake.c test/test_secret_handshake.c test/vendor/unity.c)
