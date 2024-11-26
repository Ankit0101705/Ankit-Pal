#include <stdio.h>
#include <stdbool.h>

#define SIZE 9 // Size of the Sudoku grid (9x9)

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if placing a number is valid
bool isValid(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }
    // Check column
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }
    // Check 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to find an empty cell
bool findEmptyCell(int grid[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve Sudoku using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;

    // If no empty cell is found, the Sudoku is solved
    if (!findEmptyCell(grid, &row, &col)) {
        return true;
    }

    // Try numbers 1-9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the rest of the grid
            if (solveSudoku(grid)) {
                return true;
            }

            // Undo the move (backtrack)
            grid[row][col] = 0;
        }
    }

    return false; // Trigger backtracking
}

// Main function
int main() {
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original Sudoku puzzle:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku puzzle:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}
