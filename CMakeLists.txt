cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120
        dungeon_crawler/logic.h
        dungeon_crawler/logic.cpp
        dungeon_crawler/dungeoncrawler.cpp
        dungeon_crawler/helper.cpp)
