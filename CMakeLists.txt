cmake_minimum_required(VERSION 2.8.4)
project(test2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(c-test ${SOURCE_FILES} Vector.cpp Vector.h Container.h VectorContainer.cpp VectorContainer.h)