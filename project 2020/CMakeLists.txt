cmake_minimum_required(VERSION 3.15)
project(project_2020 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wextra")
add_executable(project_2020 main.c arvore.c arvore.h ficheiro.c)