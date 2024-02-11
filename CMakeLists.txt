cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120 debugging_craps_game/craps.cpp
        debugging/debugging.cpp
        debugging/functions.cpp)