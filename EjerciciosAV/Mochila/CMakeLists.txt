cmake_minimum_required(VERSION 3.24)
project(Mochila C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Mochila
        heap_aristas.c
        heap_aristas.h
        main.c depuracion.h depuracion.c ivector.c ivector.h)
