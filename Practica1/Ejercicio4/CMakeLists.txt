cmake_minimum_required(VERSION 3.24)
project(Ejercicio4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio4
        main.c ivector.h ivector.c)
