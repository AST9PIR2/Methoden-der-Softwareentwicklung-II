cmake_minimum_required(VERSION 3.16)
project(5_Aufgabe)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(5_Aufgabe
        main.cpp
        item.h
        item.cpp
        character.cpp
        character.h
        npc.cpp
        npc.h
        sorcerer.cpp
        sorcerer.h
        fighter.cpp
        fighter.h
        hero.h
        hero.cpp)
