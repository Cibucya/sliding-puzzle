add_executable(unit_tests test_puzzle.cpp)

target_link_libraries(unit_tests
	PRIVATE
		sliding_logic
		GTest::gtest_main
)

# CTest runner
include(GoogleTest)
gtest_discover_tests(unit_tests)
