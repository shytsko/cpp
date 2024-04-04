cmake_minimum_required(VERSION 3.17)

project("Homework14 task2" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

set(PRJ_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git  GIT_TAG 1.10.5)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json GIT_REPOSITORY https://github.com/nlohmann/json GIT_TAG v3.11.3)
FetchContent_MakeAvailable(json)

add_executable(task2
    ${PRJ_SRC_DIR}/main.cpp
)

target_link_libraries(task2 PRIVATE cpr::cpr)
target_link_libraries(task2 PRIVATE nlohmann_json::nlohmann_json)