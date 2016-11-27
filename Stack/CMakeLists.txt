cmake_minimum_required(VERSION 2.8)

project(Stack)

set(PROJECT_NAME Stack)

add_subdirectory(src)

if (BUILD_TESTS)
	add_subdirectory(test)
endif (BUILD_TESTS)
