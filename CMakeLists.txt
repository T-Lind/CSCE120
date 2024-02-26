cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120 seam_carving/seamcarving.cpp seam_carving/functions.cpp seam_carving/functions.h)