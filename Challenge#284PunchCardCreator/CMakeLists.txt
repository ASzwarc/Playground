cmake_minimum_required(VERSION 3.5)
project(PunchCardCreator)

include_directories(src)

file(GLOB SOURCES "src/*.cpp")

set( PROJ_NAME punchCardCreator )
add_executable(${PROJ_NAME} ${SOURCES})
set_property(TARGET ${PROJ_NAME} PROPERTY CXX_STANDARD 14)