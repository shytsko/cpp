cmake_minimum_required(VERSION 3.17)

project(app VERSION 1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/game/include)
target_link_libraries(${PROJECT_NAME} game)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/out)