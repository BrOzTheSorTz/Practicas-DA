cmake_minimum_required(VERSION 3.24)
project(CaminosDijkstra C)

set(CMAKE_C_STANDARD 11)

add_executable(CaminosDijkstra
        main.c ivector.h ivector.c imatriz2d.c imatriz2d.h)
