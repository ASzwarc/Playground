find_package(GTest REQUIRED)

set(SUT_DIR
    ${CMAKE_SOURCE_DIR}/src
    )

add_executable(Stack_UT
)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${SUT_DIR}
)

target_link_libraries(
    Stack_UT
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
	pthread
)

