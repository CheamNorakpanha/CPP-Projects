#include <iostream>
using namespace std;

// Define the size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed in a given position
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is not present in the current row and column
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    // Check if the number is not present in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N]) {
    // Find an empty position in the grid
    int row, col;
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If no empty position is found, the Sudoku is solved
    if (!isEmpty) {
        return true;
    }

    // Try placing numbers 1 to 9 in the empty position
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Place the number if it's safe
            grid[row][col] = num;

            // Recursively solve the rest of the Sudoku
            if (solveSudoku(grid)) {
                return true;
            }

            // If placing the number leads to an invalid solution, backtrack
            grid[row][col] = 0;
        }
    }

    // If no number can be placed in the current position, backtrack
    return false;
}

int main() {
    // Example Sudoku grid (0 represents empty cells)
    int grid[N][N] = {
        {0, 0, 4, 2, 9, 0, 0, 8, 0},
        {5, 8, 0, 0, 0, 0, 7, 3, 0},
        {0, 0, 1, 0, 0, 7, 0, 0, 6},
        {0, 0, 0, 6, 0, 0, 0, 0, 0},
        {0, 2, 7, 0, 3, 0, 1, 0, 0},
        {8, 0, 0, 0, 0, 5, 0, 2, 9},
        {9, 0, 0, 1, 0, 0, 3, 0, 0},
        {3, 0, 0, 0, 0, 6, 0, 0, 5},
        {0, 0, 0, 0, 7, 4, 0, 9, 0}
    };

    // Solve the Sudoku
    if (solveSudoku(grid)) {
        cout << "Sudoku solution:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
