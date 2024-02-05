cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120
        paris_olympics/main.cpp
        paris_olympics/parallel_tracks.cpp
        paris_olympics/parallel_tracks.h)