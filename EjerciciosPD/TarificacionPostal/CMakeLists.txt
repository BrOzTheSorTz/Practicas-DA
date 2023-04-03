cmake_minimum_required(VERSION 3.25)
project(TarificacionPostal C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TarificacionPostal
        main.c ivector.h ivector.c imatriz2d.c imatriz2d.h)
