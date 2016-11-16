cmake_minimum_required(VERSION 2.8)

project(LinkedList)

set(PROJECT_NAME LinkedList)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++14")

add_subdirectory(src)

if (BUILD_TESTS)
	add_subdirectory(test)
endif (BUILD_TESTS)
