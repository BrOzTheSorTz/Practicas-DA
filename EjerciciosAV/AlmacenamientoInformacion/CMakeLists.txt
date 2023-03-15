cmake_minimum_required(VERSION 3.24)
project(AlmacenamientoInformacion C)

set(CMAKE_C_STANDARD 11)

add_executable(AlmacenamientoInformacion
        main.c ivector.h ivector.c vdin.h vdin.c)
