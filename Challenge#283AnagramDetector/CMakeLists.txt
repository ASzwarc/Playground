cmake_minimum_required(VERSION 3.5)
project(AnagramDetector)

include_directories(src)

file(GLOB SOURCES "src/*.cpp")

set( PROJ_NAME AnagramDetector )
add_executable(${PROJ_NAME} ${SOURCES})
set_property(TARGET ${PROJ_NAME} PROPERTY CXX_STANDARD 14)