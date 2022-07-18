cmake_minimum_required(VERSION 3.16)
project(Vorbereitung)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Vorbereitung main.cpp motor.cpp motor.h sensor.cpp sensor.h sensor_types.cpp sensor_types.h robot.h robot.cpp exceptions.h)
