cmake_minimum_required(VERSION 3.17)

add_executable(task1 main.cpp  surgeon.cpp point.cpp ${PRJ_INCLUDE_DIR}/point.h ${PRJ_INCLUDE_DIR}/surgeon.h)

target_include_directories(task1 PUBLIC ${PRJ_INCLUDE_DIR})