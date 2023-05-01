cmake_minimum_required(VERSION 3.25)
project(Ejercicio2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio2
        imatriz2d.c
        imatriz2d.h
        ivector.c
        ivector.h
        main.c)
