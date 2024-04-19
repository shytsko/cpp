cmake_minimum_required(VERSION 3.17)

project(game VERSION 1.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED
    include/player.h
    src/player.cpp
    include/human_player.h
    src/human_player.cpp
    include/ai_player.h
    src/ai_player.cpp
    include/game.h
    src/game.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/out)
