#include "SudokuSolver.h"
#include <iostream>

using namespace std;

SudokuSolver::SudokuSolver(const vector<vector<int>>& board) : board_(board) {}

bool SudokuSolver::solve() {
    int row, col;
    if (!findUnassigned(row, col))
        return true; // Puzzle solved

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(row, col, num)) {
            board_[row][col] = num;
            if (solve())
                return true;
            board_[row][col] = 0; // Backtrack
        }
    }
    return false; // Trigger backtracking
}

void SudokuSolver::printBoard() const {
    for (const auto& row : board_) {
        for (const auto& num : row) {
            cout << num << ' ';
        }
        cout << '\n';
    }
}

const vector<vector<int>>& SudokuSolver::getBoard() const {
    return board_;
}

bool SudokuSolver::isSafe(int row, int col, int num) const {
    // Check row and column
    for (int i = 0; i < 9; ++i) {
        if (board_[row][i] == num || board_[i][col] == num)
            return false;
    }
    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board_[startRow + i][startCol + j] == num)
                return false;
    return true;
}

bool SudokuSolver::findUnassigned(int& row, int& col) const {
    for (row = 0; row < 9; ++row)
        for (col = 0; col < 9; ++col)
            if (board_[row][col] == 0)
                return true;
    return false;
}