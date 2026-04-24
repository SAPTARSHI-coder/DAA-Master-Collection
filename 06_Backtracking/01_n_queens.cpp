// Program: N-Queens Problem (Backtracking)
// What it does: Place N chess queens on an N x N board such that
//               NO two queens threaten each other.
//               (No two queens share same row, column, or diagonal)
// Approach: Try placing queens column by column; if conflict, BACKTRACK.
//
// Example Input: N = 4
// Expected Output:
//   Solution 1:
//   . Q . .
//   . . . Q
//   Q . . .
//   . . Q .

#include <iostream>
using namespace std;

int board[20][20];  // Chess board (1 = queen placed, 0 = empty)
int N;              // Size of board (N x N)
int totalSolutions = 0;  // Count of total solutions found

// Function to check if placing a queen at (row, col) is SAFE
// We only need to check the left side (queens already placed in previous columns)
bool isSafe(int row, int col) {
    // Check the same row to the LEFT
    for (int c = 0; c < col; c++) {
        if (board[row][c] == 1) return false;
    }

    // Check upper-left diagonal
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 1) return false;
    }

    // Check lower-left diagonal
    for (int r = row + 1, c = col - 1; r < N && c >= 0; r++, c--) {
        if (board[r][c] == 1) return false;
    }

    return true;  // Position is safe!
}

// Function to display the current board configuration
void displayBoard() {
    totalSolutions++;
    cout << "\nSolution " << totalSolutions << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << " Q ";  // Queen
            else
                cout << " . ";  // Empty
        }
        cout << endl;
    }
}

// Recursive backtracking function to place queens column by column
// 'col' = current column we are trying to place a queen in
void solveNQueens(int col) {
    // Base case: If all queens are placed (we've filled all columns), display solution
    if (col == N) {
        displayBoard();
        return;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < N; row++) {
        // Check if placing queen at (row, col) is safe
        if (isSafe(row, col)) {
            board[row][col] = 1;  // Place the queen

            // Recursively try to place queens in next column
            solveNQueens(col + 1);

            // BACKTRACK: Remove the queen and try next row
            board[row][col] = 0;
        }
    }
}

int main() {
    cout << "=== N-Queens Problem (Backtracking) ===" << endl;
    cout << "Enter the value of N (size of the board): ";
    cin >> N;

    // Initialize board to all zeros (no queens placed)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    // Start solving from the first column (column 0)
    solveNQueens(0);

    if (totalSolutions == 0)
        cout << "No solution exists for N = " << N << endl;
    else
        cout << "\nTotal solutions found: " << totalSolutions << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(N!) -> In the worst case, tries all permutations

Space Complexity: O(N^2) -> For the board array

Key Concept: Backtracking tries all possibilities and abandons (backtracks)
             when a partial solution can't lead to a complete valid solution.
============================
*/
