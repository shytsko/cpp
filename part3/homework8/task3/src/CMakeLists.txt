cmake_minimum_required(VERSION 3.17)

add_executable(task3
    main.cpp
    ${PRJ_INCLUDE_DIR}/display.h
    display.cpp
    ${PRJ_INCLUDE_DIR}/window.h
    window.cpp
    ${PRJ_INCLUDE_DIR}/vector2D.h
    vector2D.cpp
)

target_include_directories(task3 PUBLIC ${PRJ_INCLUDE_DIR})