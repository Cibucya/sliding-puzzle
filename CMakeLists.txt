cmake_minimum_required(VERSION 3.10)
project(sliding VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(sliding_logic
	src/Board.cpp
	src/Puzzle.cpp
)

target_include_directories(sliding_logic PUBLIC include)

add_executable(sliding src/main.cpp)
target_link_libraries(sliding PRIVATE sliding_logic)

add_subdirectory(tests)
