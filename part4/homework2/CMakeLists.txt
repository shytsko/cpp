cmake_minimum_required(VERSION 3.17)

project(matches VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(app)
add_subdirectory(game)

add_dependencies(app game)