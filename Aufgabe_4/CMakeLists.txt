cmake_minimum_required(VERSION 3.16)
project(4_Aufgabe)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(4_Aufgabe
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
