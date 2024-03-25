cmake_minimum_required(VERSION 3.17)

project("Homework9 task2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(PRJ_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PRJ_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(task2
    ${PRJ_SRC_DIR}/main.cpp
    ${PRJ_INCLUDE_DIR}/coordinate.h
    ${PRJ_INCLUDE_DIR}/shape.h
    ${PRJ_SRC_DIR}/shape.cpp
    ${PRJ_INCLUDE_DIR}/circle.h
    ${PRJ_SRC_DIR}/circle.cpp
    ${PRJ_INCLUDE_DIR}/triangle.h
    ${PRJ_SRC_DIR}/triangle.cpp
    ${PRJ_INCLUDE_DIR}/rectangle.h
    ${PRJ_SRC_DIR}/rectangle.cpp
    ${PRJ_INCLUDE_DIR}/square.h
    ${PRJ_SRC_DIR}/square.cpp
)

target_include_directories(task2 PUBLIC ${PRJ_INCLUDE_DIR})