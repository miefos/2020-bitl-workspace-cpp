cmake_minimum_required(VERSION 3.17)
project(ex07_aliens)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex07_aliens
        Alien.cpp
        Alien.h
        AliensMain.cpp
        BinaryTree.cpp
        BinaryTree.h
        LinkedList.cpp
        LinkedList.h)
