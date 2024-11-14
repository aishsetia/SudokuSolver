#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>

using namespace std;

class SudokuSolver {
public:
    SudokuSolver(const vector<vector<int>>& board);
    bool solve();
    void printBoard() const;
    const vector<vector<int>>& getBoard() const;

private:
    bool isSafe(int row, int col, int num) const;
    bool findUnassigned(int& row, int& col) const;
    vector<vector<int>> board_;
};

#endif // SUDOKUSOLVER_H 