// Program: Knight's Tour Problem (Backtracking)
// What it does: A chess knight must visit EVERY square of an N x N board
//               EXACTLY ONCE. Find such a tour (if it exists).
//               The knight moves in an "L-shape": 2 squares in one direction
//               and 1 square perpendicular (or vice versa).
//               Uses BACKTRACKING: try each of 8 possible L-moves; undo if stuck.
//
// Example Input: Board size N = 5
// Expected Output: A board showing the sequence of knight moves

#include <iostream>
using namespace std;

#define MAX 8

int board[MAX][MAX];  // board[i][j] = move number when knight visited this cell
int N;                // Board size (NxN)

// All 8 possible L-shaped moves for a knight
int rowMoves[] = { 2,  2, -2, -2,  1,  1, -1, -1 };
int colMoves[] = { 1, -1,  1, -1,  2, -2,  2, -2 };

// Check if position (row, col) is valid and not yet visited
bool isSafe(int row, int col) {
    return (row >= 0 && row < N &&    // Within row bounds
            col >= 0 && col < N &&    // Within column bounds
            board[row][col] == -1);   // Not yet visited
}

// Recursive backtracking function
// row, col    = current position of the knight
// moveNumber  = which move number we are placing (1 = first move, N*N = last)
bool solveKnightsTour(int row, int col, int moveNumber) {
    // BASE CASE: All N*N squares are visited
    if (moveNumber == N * N + 1) {
        return true;  // Complete tour found!
    }

    // Try all 8 possible L-shaped moves from current position
    for (int move = 0; move < 8; move++) {
        int nextRow = row + rowMoves[move];
        int nextCol = col + colMoves[move];

        // Check if this next position is valid
        if (isSafe(nextRow, nextCol)) {
            // Make the move: place move number on the next cell
            board[nextRow][nextCol] = moveNumber;

            // Recursively try to complete the tour from next position
            if (solveKnightsTour(nextRow, nextCol, moveNumber + 1)) {
                return true;  // Tour complete!
            }

            // BACKTRACK: This move didn't work, undo it (mark as unvisited)
            board[nextRow][nextCol] = -1;
        }
    }

    return false;  // No valid move from current position -> backtrack
}

// Display the completed board
void displayBoard() {
    cout << "\nKnight's Tour (move sequence):" << endl;
    cout << "+";
    for (int j = 0; j < N; j++) cout << "-----+";
    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << "|";
        for (int j = 0; j < N; j++) {
            cout << "  ";
            if (board[i][j] < 10) cout << " ";
            cout << board[i][j] << "  |";
        }
        cout << endl;
        cout << "+";
        for (int j = 0; j < N; j++) cout << "-----+";
        cout << endl;
    }
}

int main() {
    cout << "=== Knight's Tour Problem (Backtracking) ===" << endl;
    cout << "Enter board size N (e.g., 5 for 5x5 board): ";
    cin >> N;

    // Initialize all cells as unvisited (-1)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    // Start the knight at position (0, 0), move number = 1
    board[0][0] = 1;

    cout << "\nFinding Knight's Tour starting at (0, 0)..." << endl;
    cout << "(May take a moment for larger boards)" << endl;

    if (solveKnightsTour(0, 0, 2)) {
        cout << "SOLUTION FOUND!" << endl;
        displayBoard();
    } else {
        cout << "No complete Knight's Tour exists from (0, 0) on a "
             << N << "x" << N << " board." << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(8^(N^2)) -> Worst case: 8 choices at each of N^2 cells
  However, backtracking with Warnsdorff's heuristic reduces this significantly.
  For N >= 5, a tour always exists.

Space Complexity: O(N^2) -> For the board array + O(N^2) recursion stack

Practical Note:
  For N <= 5: Fast with backtracking alone
  For N = 6 or larger: May use Warnsdorff's rule (heuristic) for O(N^2) solution:
  "Always move to the cell with the FEWEST onward moves next."
============================
*/
