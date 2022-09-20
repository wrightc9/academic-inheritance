cmake_minimum_required(VERSION 3.10)
project(school_inheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(school main.cpp date.h date.cpp person.h person.cpp student.h student.cpp professor.h
        professor.cpp)