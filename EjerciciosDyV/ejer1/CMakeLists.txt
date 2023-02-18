cmake_minimum_required(VERSION 3.24)
project(Ejercicio2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ejer1 main.c ivector.c ivector.h)
