cmake_minimum_required(VERSION 3.0.2)

project(BullsAndCowsGame)

if (MSVC)
	add_definitions(/W4)
	add_compile_options(/EHa)
elseif (GNU)
	set(CMAKE_CXX_STANDARD 11)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
	add_compile_options(-std=c++11)
else ()
	message("Unknown compiler")
endif ()

add_subdirectory(modules/bnclib)
