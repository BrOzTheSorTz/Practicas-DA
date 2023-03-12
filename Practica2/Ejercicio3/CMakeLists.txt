cmake_minimum_required(VERSION 3.24)
project(Ejercicio3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ejercicio3
        main.c disjoint.c disjoint.h ivector.c ivector.h imatriz2d.h imatriz2d.c vdin.h vdin.c)
