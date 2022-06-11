cmake_minimum_required(VERSION 3.17)
project(mylib C)

set(CMAKE_C_STANDARD 99)

add_library(mylib SHARED library.c library.h)