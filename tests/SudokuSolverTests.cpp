#include "../include/SudokuSolver.h"
#include <gtest/gtest.h>

using namespace std;

TEST(SudokuSolverTest, SolverSolvesValidPuzzle) {
    vector<vector<int>> board = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    SudokuSolver solver(board);
    EXPECT_TRUE(solver.solve());
    const auto& solved = solver.getBoard();
    // Check a few cells
    EXPECT_EQ(solved[0][2], 4);
    EXPECT_EQ(solved[4][4], 5);
    EXPECT_EQ(solved[8][6], 1);
}

TEST(SudokuSolverTest, SolverDetectsNoSolution) {
    vector<vector<int>> board = {
        {5,5,0,0,7,0,0,0,0}, // Invalid: two 5's in the first row
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    SudokuSolver solver(board);
    EXPECT_FALSE(solver.solve());
} 