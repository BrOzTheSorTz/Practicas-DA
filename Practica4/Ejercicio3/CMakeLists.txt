cmake_minimum_required(VERSION 3.25)
project(Ejercicio3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio3
        ivector.c
        ivector.h
        main.c)
