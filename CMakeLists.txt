cmake_minimum_required(VERSION 3.19)
project(graphs_lol)

set(CMAKE_CXX_STANDARD 20)

# Compiler flags
set(GCC_WARNING_FLAGS "-Wall -Wextra") # Enable all warnings in GCC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_WARNING_FLAGS}")

add_executable(graphs_lol main.cpp graph.h)