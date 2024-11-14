cmake_minimum_required(VERSION 3.10)
project(SudokuSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add library
add_library(SudokuSolverLib STATIC
    src/SudokuSolver.cpp
    include/SudokuSolver.h
)

# Include directories for the library
target_include_directories(SudokuSolverLib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# Add executable and link it to the library
add_executable(SudokuSolver src/main.cpp)
target_link_libraries(SudokuSolver PRIVATE SudokuSolverLib)

# Add tests
add_subdirectory(tests)

enable_testing() 