cmake_minimum_required(VERSION 3.17)

project("Homework13 task3" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(PRJ_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PRJ_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(task3
    ${PRJ_SRC_DIR}/main.cpp
    ${PRJ_INCLUDE_DIR}/igraph.h
    ${PRJ_SRC_DIR}/igraph.cpp
    ${PRJ_INCLUDE_DIR}/list_graph.h
    ${PRJ_SRC_DIR}/list_graph.cpp
    ${PRJ_INCLUDE_DIR}/matrix_graph.h
    ${PRJ_SRC_DIR}/matrix_graph.cpp
)

target_include_directories(task3 PUBLIC ${PRJ_INCLUDE_DIR})