cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120
        op_overload/add_operator_overload.cpp
        op_overload/vector.h
        op_overload/vector.cpp)
