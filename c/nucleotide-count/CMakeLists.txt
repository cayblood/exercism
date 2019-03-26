cmake_minimum_required(VERSION 3.13)

project(NucleotideCount)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c)

add_executable(test_nucleotide_count src/nucleotide_count.c test/test_nucleotide_count.c test/vendor/unity.c)