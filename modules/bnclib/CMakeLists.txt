cmake_minimum_required(VERSION 3.0.2)

project(bnclib)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        include/Rules.h
        include/Utils.h)

set(SOURCE_FILES
        src/Rules.cpp
        src/Utils.cpp)

include_directories(include)

add_library(bnclib STATIC
        ${HEADER_FILES}
        ${SOURCE_FILES}
        )
