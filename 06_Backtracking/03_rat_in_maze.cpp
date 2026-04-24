// Program: Rat in a Maze (Backtracking)
// What it does: Find all paths for a rat to reach from the TOP-LEFT corner
//               (0,0) to the BOTTOM-RIGHT corner (N-1, N-1) of a maze.
//               The rat can move RIGHT or DOWN only (or all 4 directions).
//               1 = open cell, 0 = blocked cell.
//
// Example Input (4x4 maze):
//   1 0 0 0
//   1 1 0 1
//   0 1 0 0
//   1 1 1 1
// Expected Output: Path found: (0,0)->(1,0)->(1,1)->(2,1)->(3,1)->(3,2)->(3,3)

#include <iostream>
using namespace std;

#define MAX 10

int maze[MAX][MAX];   // Maze grid (1=open, 0=blocked)
int solution[MAX][MAX]; // Solution path (1=part of path, 0=not)
int N;                 // Size of maze (N x N)
int totalPaths = 0;

// Direction arrays for moving: Right and Down (can extend to 4 directions)
int rowMove[] = {0, 1};  // Row changes: Right=no change, Down=+1
int colMove[] = {1, 0};  // Col changes: Right=+1, Down=no change

// Function to check if position (row, col) is valid to move to
bool isSafe(int row, int col) {
    return (row >= 0 && row < N &&   // Within bounds (row)
            col >= 0 && col < N &&   // Within bounds (col)
            maze[row][col] == 1 &&   // Cell is open
            solution[row][col] == 0); // Not already visited in current path
}

// Function to display the current solution path
void displaySolution() {
    totalPaths++;
    cout << "\nSolution Path " << totalPaths << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

// Recursive backtracking function to find all paths
void solveMaze(int row, int col) {
    // Base case: Reached the destination (bottom-right corner)
    if (row == N - 1 && col == N - 1) {
        solution[row][col] = 1;  // Mark destination as part of path
        displaySolution();
        solution[row][col] = 0;  // Unmark for other paths (backtrack)
        return;
    }

    // Try moving in each allowed direction (Right and Down)
    for (int dir = 0; dir < 2; dir++) {
        int nextRow = row + rowMove[dir];
        int nextCol = col + colMove[dir];

        // Check if the next position is valid
        if (isSafe(nextRow, nextCol)) {
            solution[row][col] = 1;    // Mark current cell as part of path

            solveMaze(nextRow, nextCol); // Move to next cell

            solution[row][col] = 0;    // BACKTRACK: Unmark current cell
        }
    }
}

int main() {
    cout << "=== Rat in a Maze (Backtracking) ===" << endl;
    cout << "Enter the size of the maze (N x N): ";
    cin >> N;

    cout << "\nEnter the maze (1=open, 0=blocked):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
            solution[i][j] = 0;  // Initialize solution as empty
        }
    }

    // Check if start position is accessible
    if (maze[0][0] == 0) {
        cout << "Start position is blocked! No path possible." << endl;
        return 0;
    }

    // Start solving from top-left corner
    solveMaze(0, 0);

    if (totalPaths == 0)
        cout << "\nNo path exists from (0,0) to (" << N-1 << "," << N-1 << ")!" << endl;
    else
        cout << "\nTotal paths found: " << totalPaths << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(2^(N^2)) -> At each cell, 2 choices (right or down), N^2 cells total
  More practically, much better due to blocked cells and backtracking

Space Complexity: O(N^2) -> For solution array and recursive call stack
============================
*/
