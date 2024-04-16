cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120
        image_manipulation/Pixel.h
        image_manipulation/Pixel.cpp
        image_manipulation/manip.cpp
        image_manipulation/Image.cpp
        image_manipulation/functions.cpp

)
