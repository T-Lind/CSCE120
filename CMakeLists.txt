cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120 grade_calculator/grade_calculator.cpp
        boolean_functions_lab/boolean_functions.cpp
        boolean_functions_lab/boolean.cpp)
