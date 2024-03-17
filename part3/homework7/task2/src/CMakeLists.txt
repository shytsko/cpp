cmake_minimum_required(VERSION 3.17)

add_executable(task1
    main.cpp
    cpu.cpp
    ${PRJ_INCLUDE_DIR}/cpu.h
    ram.cpp
    ${PRJ_INCLUDE_DIR}/ram.h
    disk.cpp
    ${PRJ_INCLUDE_DIR}/disk.h
    gpu.cpp
    ${PRJ_INCLUDE_DIR}/gpu.h
    kbd.cpp
    ${PRJ_INCLUDE_DIR}/kbd_.h
)

target_include_directories(task1 PUBLIC ${PRJ_INCLUDE_DIR})