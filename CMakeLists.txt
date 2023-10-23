cmake_minimum_required(VERSION 3.26)
project(text_manipulation_c C)

set(CMAKE_C_STANDARD 11)

add_executable(text_manipulation_c main.c
        bench.c)
