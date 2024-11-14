#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>

using namespace std;

class SudokuSolver {
public:
    SudokuSolver(const std::vector<std::vector<int>>& board);
    bool solve();
    void printBoard() const;
    const std::vector<std::vector<int>>& getBoard() const;

private:
    bool isSafe(int row, int col, int num) const;
    bool findUnassigned(int& row, int& col) const;
    std::vector<std::vector<int>> board_;
};

#endif // SUDOKUSOLVER_H 