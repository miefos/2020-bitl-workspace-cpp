cmake_minimum_required(VERSION 3.17)
project(ex06_shapes)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex06_shapes
        Transformation.h
        ShapeStack.cpp
        ShapeStack.h
        Group.cpp
        Group.h
        Circle.cpp
        Circle.h
        Polygon.cpp
        Polygon.h
        Matrix.h
        Shape.h
        ShapesMain.cpp)
