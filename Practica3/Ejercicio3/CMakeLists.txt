cmake_minimum_required(VERSION 3.25)
project(Ejercicio3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio3
        main.c ivector.h ivector.c imatriz2d.c imatriz2d.h)
