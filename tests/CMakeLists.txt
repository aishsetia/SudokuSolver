# tests/CMakeLists.txt

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(SudokuSolverTests SudokuSolverTests.cpp)

target_include_directories(SudokuSolverTests PUBLIC ../include)

# Link against the SudokuSolver library and Google Test
target_link_libraries(SudokuSolverTests PRIVATE SudokuSolverLib GTest::GTest GTest::Main)

# Add the following lines to use CTest's test discovery
include(GoogleTest)
gtest_discover_tests(SudokuSolverTests)

enable_testing()