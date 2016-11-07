set(SUT_DIR ${CMAKE_SOURCE_DIR}/src)

find_package(GTest REQUIRED)

set(SUT_SRC
	${SUT_DIR}/
    )

set(TEST_SRC
)

add_executable(LinkedList_UT
	${TEST_SRC}
	${SUT_SRC}
)

include_directories(
	${SUT_DIR}
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(
	LinkedList_UT
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
	pthread
)

