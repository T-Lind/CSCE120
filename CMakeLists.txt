cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120 calculator/calculator.cpp calculator/functions.h calculator/functions.cpp)
