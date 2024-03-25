cmake_minimum_required(VERSION 3.17)

project("Homework9 task1" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

set(PRJ_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PRJ_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(task1
    ${PRJ_SRC_DIR}/main.cpp
    ${PRJ_INCLUDE_DIR}/elf.h
    ${PRJ_SRC_DIR}/elf.cpp
    ${PRJ_INCLUDE_DIR}/branch.h
    ${PRJ_SRC_DIR}/branch.cpp
    ${PRJ_INCLUDE_DIR}/forest.h
    ${PRJ_SRC_DIR}/forest.cpp
)

target_include_directories(task1 PUBLIC ${PRJ_INCLUDE_DIR})