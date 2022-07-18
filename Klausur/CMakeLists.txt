cmake_minimum_required(VERSION 3.16)
project(Klausur)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Klausur main.cpp exceptions.h product.cpp product.h machine.cpp machine.h factory.cpp factory.h)