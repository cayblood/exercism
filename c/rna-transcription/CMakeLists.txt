cmake_minimum_required(VERSION 3.13)

project(RNATranscription)

include_directories(src test/vendor)

add_library(STATIC test/vendor/unity.c src/rna_transcription.c src/rna_transcription.h src/rna_transcription.c src/rna_transcription.h)

add_executable(test_rna_transcription src/rna_transcription.c test/test_rna_transcription.c test/vendor/unity.c)
