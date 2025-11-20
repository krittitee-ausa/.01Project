cmake_minimum_required(VERSION 4.0)
project(_01Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(_01Project
        func1.c
        main_c.c
        structure.h
)
