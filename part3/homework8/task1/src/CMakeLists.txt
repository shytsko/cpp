cmake_minimum_required(VERSION 3.17)

add_executable(task1
    main.cpp
    player.cpp
    ${PRJ_INCLUDE_DIR}/player.h
    track.cpp
    ${PRJ_INCLUDE_DIR}/track.h
)

target_include_directories(task1 PUBLIC ${PRJ_INCLUDE_DIR})