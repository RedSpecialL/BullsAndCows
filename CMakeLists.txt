cmake_minimum_required(VERSION 3.6)

project(BullsAndCows)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        include/Rules.h)

set(SOURCE_FILES
        src/Rules.cpp)

include_directories(include)

add_library(bncrules STATIC
        ${HEADER_FILES}
        ${SOURCE_FILES}
        )