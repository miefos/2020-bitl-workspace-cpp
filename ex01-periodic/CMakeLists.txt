cmake_minimum_required(VERSION 3.17)
project(periodic_strings)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(periodic_strings
        Periodic.cpp
        Periodic.h
        PeriodicMain.cpp)
