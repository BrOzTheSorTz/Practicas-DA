cmake_minimum_required(VERSION 3.24)
project(Ejercicio1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio1
        main.c ivector.c ivector.h)
