cmake_minimum_required(VERSION 3.24)
project(MaximaNota C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MaximaNota
        main.c ivector.h ivector.c)
