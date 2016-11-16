find_package(GTest REQUIRED)

set(SUT_DIR
    ${CMAKE_SOURCE_DIR}/src
    )

add_executable(LinkedList_UT
    LinkedListTests.cpp
)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${SUT_DIR}
)

target_link_libraries(
	LinkedList_UT
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
	pthread
)

