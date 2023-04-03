cmake_minimum_required(VERSION 3.25)
project(serieStern C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(serieStern
        ivector.c
        ivector.h
        main.c)
