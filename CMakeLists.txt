cmake_minimum_required(VERSION 3.27)
project(CSCE120)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSCE120
        state_parks/StatePark.h
        state_parks/StatePark.cpp
        state_parks/Passport.cpp
        state_parks/Driver.cpp
        state_parks/Database.cpp

        #        crazy_8s/Player.h
#        crazy_8s/Player.h
#        crazy_8s/main.cpp
#        crazy_8s/Game.cpp
#        crazy_8s/Card.cpp
#        crazy_8s/Player.cpp
)
