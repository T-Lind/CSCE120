cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120 hw_mountains_valleys/mountains_valleys.cpp
        hw_mountains_valleys/functions.h
        hw_mountains_valleys/functions.cpp)
