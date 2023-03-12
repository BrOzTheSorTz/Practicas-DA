cmake_minimum_required(VERSION 3.24)
project(centroUnion C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(centroUnion
        main.c ivector.c ivector.h)
