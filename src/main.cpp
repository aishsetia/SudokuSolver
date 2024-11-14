#include "SudokuSolver.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> readBoardFromStdin() {
    vector<vector<int>> board(9, vector<int>(9, 0));
    cout << "Enter the Sudoku puzzle row by row, using 0 for empty cells:\n";
    for (int i = 0; i < 9; ++i) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        for (int j = 0; j < 9; ++j) {
            iss >> board[i][j];
        }
    }
    return board;
}

vector<vector<int>> readBoardFromFile(const string& filename) {
    vector<vector<int>> board(9, vector<int>(9, 0));
    ifstream infile(filename);
    if (!infile) {
        cerr << "Unable to open file: " << filename << '\n';
        return board;
    }
    for (int i = 0; i < 9 && infile; ++i) {
        for (int j = 0; j < 9 && infile; ++j) {
            infile >> board[i][j];
        }
    }
    return board;
}

int main(int argc, char* argv[]) {
    vector<vector<int>> board;
    if (argc > 1) {
        board = readBoardFromFile(argv[1]);
    } else {
        board = readBoardFromStdin();
    }

    SudokuSolver solver(board);
    if (solver.solve()) {
        cout << "Sudoku Solved:\n";
        solver.printBoard();
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }
    return 0;
}