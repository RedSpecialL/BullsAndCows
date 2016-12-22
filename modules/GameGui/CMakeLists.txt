cmake_minimum_required(VERSION 3.0.2)

project(BullsAndCowsGameGui)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 14)

# Widgets finds its own dependencies (QtGui and QtCore).
find_package(Qt5Widgets REQUIRED)

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS})

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(HEADERS
	include/MainWindow.h
	)

set(SOURCES
	src/Main.cpp
	src/MainWindow.cpp
	)

set(UI
	ui/Mainwindow.ui
	)

qt5_wrap_ui(UI_moc ${UI})

set(AutoMocCppFile ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_automoc.cpp)
set_source_files_properties(${AutoMocCppFile} PROPERTIES GENERATED TRUE)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})
source_group("" FILES ${MISC})
source_group("Ui" FILES ${UI})

include_directories(
	include
	../bnclib/include
	${Qt5Widgets_INCLUDES}
	)

add_executable(${PROJECT_NAME} WIN32
	${HEADERS}
	${SOURCES}
	${UI}
	${UI_moc}
	)

target_link_libraries(${PROJECT_NAME}
	bnclib
	${Qt5Widgets_LIBRARIES}
	)

add_dependencies(${PROJECT_NAME} 
	libnb
	)
