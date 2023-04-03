cmake_minimum_required(VERSION 3.25)
project(Ejercicio4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio4
        main.c imatriz2d.h imatriz2d.c ivector.c ivector.h)
