cmake_minimum_required(VERSION 3.19)
project(linux9_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(linux9_1 client.c server.c)