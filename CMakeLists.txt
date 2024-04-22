cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120
        temperature/TemperatureDatabase.h
        temperature/TemperatureData.h
        temperature/Node.h
        temperature/main.cpp
        temperature/LinkedList.cpp
        temperature/Node.cpp
        temperature/TemperatureDatabase.cpp
        temperature/TemperatureData.cpp
)
