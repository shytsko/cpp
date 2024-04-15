cmake_minimum_required(VERSION 3.17)

project("matches" VERSION 1.0 LANGUAGES CXX)

set(PRJ_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PRJ_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME}
    ${PRJ_SRC_DIR}/main.cpp
    ${PRJ_INCLUDE_DIR}/player.h
    ${PRJ_SRC_DIR}/player.cpp
    ${PRJ_INCLUDE_DIR}/human_player.h
    ${PRJ_SRC_DIR}/human_player.cpp
    ${PRJ_INCLUDE_DIR}/ai_player.h
    ${PRJ_SRC_DIR}/ai_player.cpp
    ${PRJ_INCLUDE_DIR}/game.h
    ${PRJ_SRC_DIR}/game.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} PUBLIC ${PRJ_INCLUDE_DIR})