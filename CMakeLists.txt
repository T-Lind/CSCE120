cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

set(SFML_ROOT "C:/Users/tenant/Downloads/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/lib/cmake/SFML-2.6.1")
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

add_executable(CSCE120 linear_transformations/main.cpp)


target_link_libraries(CSCE120 sfml-graphics sfml-window sfml-system)
