cmake_minimum_required(VERSION 3.17)

project("Homework12 task2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(PRJ_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

add_executable(task2
    ${PRJ_SRC_DIR}/main.cpp
)

target_link_libraries(task2 PRIVATE cpr::cpr)