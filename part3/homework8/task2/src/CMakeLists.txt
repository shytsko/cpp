cmake_minimum_required(VERSION 3.17)

add_executable(task2
    main.cpp
    phone_number.cpp
    ${PRJ_INCLUDE_DIR}/phone_number.h
    phone_book.cpp
    ${PRJ_INCLUDE_DIR}/phone_book.h
    phone.cpp
    ${PRJ_INCLUDE_DIR}/phone.h
)

target_include_directories(task2 PUBLIC ${PRJ_INCLUDE_DIR})