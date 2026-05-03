// ============================================================
// CASE STUDY 06: Minimum Cost Path in a Grid
// ============================================================
//
// PROBLEM STATEMENT:
//   Given an M x N grid where each cell has a COST, find the path
//   from the TOP-LEFT cell (0,0) to the BOTTOM-RIGHT cell (M-1, N-1)
//   with the MINIMUM TOTAL COST.
//   You can only move RIGHT or DOWN at each step.
//
// REAL-LIFE INTERPRETATION:
//   - Robot navigation: minimize energy to reach destination.
//   - GPS routing: minimize toll/traffic cost on a city grid.
//   - Game: minimize damage taken while crossing a map.
//   - Supply chain: route goods through minimum cost checkpoints.
//
// ============================================================
// PATTERN RECOGNITION: WHY DYNAMIC PROGRAMMING?
// ============================================================
//
//  Can we use GREEDY?  --> NO!
//    Greedy: At each step, pick the cheaper neighbor.
//    FAILS: A locally cheap step may lead to expensive cells later.
//    Example:
//      1  100
//      1    1
//    Greedy picks right (100) from start -> 1+100+1 = 102
//    Correct: Down -> Right down -> 1+1+1 = 3
//
//  CAN WE USE RECURSION?  --> Yes, but overlapping subproblems!
//    minCost(i, j) = grid[i][j] + min(minCost(i-1, j), minCost(i, j-1))
//    Many cells are recomputed -> Exponential time.
//
//  DP FIX: Build a table where dp[i][j] = min cost to reach cell (i,j).
//
//  PATTERN: "Min/Max total" + "can only go right or down" -> GRID DP
//
// CATEGORY: DYNAMIC PROGRAMMING (Bottom-Up Tabulation on 2D Grid)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: dp[0][0] = grid[0][0] (start cost = grid cost)
//  Step 2: First row: can only come from the LEFT
//           dp[0][j] = dp[0][j-1] + grid[0][j]
//  Step 3: First column: can only come from ABOVE
//           dp[i][0] = dp[i-1][0] + grid[i][0]
//  Step 4: All other cells: min of coming from LEFT or ABOVE
//           dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
//  Step 5: Answer is dp[M-1][N-1]
//
// Example:
//   Grid:     dp table:
//    1 3 1     1 4 5
//    1 5 1  => 2 7 6
//    4 2 1     6 8 7
//   Minimum cost = 7
//
// ============================================================

#include <iostream>
using namespace std;

#define MAX 10

// Function to find the minimum cost path in a grid
void minimumCostPath(int grid[][MAX], int rows, int cols) {
    // Create DP table
    int dp[MAX][MAX];

    // Step 1: Start at top-left
    dp[0][0] = grid[0][0];

    // Step 2: Fill first row (can only come from left)
    for (int col = 1; col < cols; col++) {
        dp[0][col] = dp[0][col - 1] + grid[0][col];
    }

    // Step 3: Fill first column (can only come from above)
    for (int row = 1; row < rows; row++) {
        dp[row][0] = dp[row - 1][0] + grid[row][0];
    }

    // Step 4: Fill rest of the grid
    for (int row = 1; row < rows; row++) {
        for (int col = 1; col < cols; col++) {
            // Cost = grid cost + minimum of (coming from above OR from left)
            int fromAbove = dp[row - 1][col];   // Cost if we came from the cell above
            int fromLeft  = dp[row][col - 1];   // Cost if we came from the cell to left

            dp[row][col] = grid[row][col] + min(fromAbove, fromLeft);
        }
    }

    // Display the grid and DP table
    cout << "\nOriginal Cost Grid:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << grid[i][j] << "\t";
        cout << endl;
    }

    cout << "\nDP Table (min cost to reach each cell):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << dp[i][j] << "\t";
        cout << endl;
    }

    // Step 5: Answer is bottom-right cell
    cout << "\nMinimum Cost to reach (" << rows-1 << ", " << cols-1
         << "): " << dp[rows-1][cols-1] << endl;

    // Trace back the path
    cout << "\nOptimal Path (traced backwards):" << endl;
    int r = rows - 1, c = cols - 1;
    string pathSteps = "(" + to_string(r) + "," + to_string(c) + ")";
    while (r > 0 || c > 0) {
        if (r == 0) {
            c--;
        } else if (c == 0) {
            r--;
        } else if (dp[r-1][c] < dp[r][c-1]) {
            r--;
        } else {
            c--;
        }
        pathSteps = "(" + to_string(r) + "," + to_string(c) + ") -> " + pathSteps;
    }
    cout << pathSteps << endl;
}

int main() {
    int rows, cols;

    cout << "============================================================" << endl;
    cout << " CASE STUDY 06: Minimum Cost Path in Grid (Dynamic Programming)" << endl;
    cout << "============================================================" << endl;
    cout << "\nEnter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int grid[MAX][MAX];

    cout << "\nEnter the cost grid row by row:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    minimumCostPath(grid, rows, cols);

    return 0;
}

/*
============================
Time Complexity:
  O(M * N) -> Fill every cell in the M x N grid once

Space Complexity: O(M * N) -> For the 2D DP table

SIMILAR PROBLEMS (Same Grid DP Pattern):
  1. Unique Paths           -> Count paths (no costs, just counting)
  2. Triangle Minimum Path  -> Min cost path in triangular grid (top to bottom)
  3. Dungeon Game           -> Min health to survive going from (0,0) to (M,N)
  4. Cherry Pickup          -> Two robots, maximize cherries collected
  5. Minimum Falling Path Sum -> Min sum path from top to bottom row

KEY DIFFERENCES:
  - This problem: ONLY right/down moves -> simple DP
  - Rat in Maze (Backtracking): blocked cells + all 4 dirs -> backtracking
  - Shortest Path (BFS): all 4 directions + unweighted -> BFS
============================
*/
