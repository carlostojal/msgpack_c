cmake_minimum_required(VERSION 3.31)
project(msgpack_c C)

set(CMAKE_C_STANDARD 17)

add_library(msgpack_c STATIC library.c)
