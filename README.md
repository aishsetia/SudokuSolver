# SudokuSolver

A simple Sudoku solver implemented in C++ using a backtracking algorithm.

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Run tests

```bash
ctest
```

## Run the solver

```bash
./SudokuSolver
```

You can also run the solver with a custom board by passing a path to a file containing the board as a command line argument.

```bash
./SudokuSolver path/to/board.txt
```

## Board file format

The board file should contain 9 lines, each containing 9 space-separated integers. The integers should be between 0 and 9, where 0 represents an empty cell.

```bash
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
1 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

