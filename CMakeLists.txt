cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_nth_root.cpp test_helpers.h nth_root.cpp nth_root.h)