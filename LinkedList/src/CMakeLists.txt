set(CMAKE_CXX_FLAGS "-g -Wall -std=c++14")

include_directories(${CMAKE_CURRENT_SOURCE_DIRECTORY})

add_executable(${PROJECT_NAME}
	main.cpp
)

