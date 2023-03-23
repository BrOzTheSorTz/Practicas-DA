cmake_minimum_required(VERSION 3.24)
project(MatrizCosteMinimo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MatrizCosteMinimo main.c
        imatriz2d.c
        imatriz2d.h
        )
