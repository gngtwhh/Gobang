cmake_minimum_required(VERSION 3.25)
project(五子棋)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES
        sources/*.cpp
        )
file(GLOB HEADERS
        headers/*.h
        )

#add_executable(gomoku sources/main.cpp headers/GameControl.h headers/System.h headers/Board.h sources/Board.cpp sources/Player.cpp headers/Player.h sources/System.cpp sources/GameControl.cpp)
add_executable(gomoku ${SOURCES} ${HEADERS})