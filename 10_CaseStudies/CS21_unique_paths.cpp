// ============================================================
// CASE STUDY 21: Unique Paths in a Grid
// ============================================================
//
// PROBLEM STATEMENT:
//   A robot is at the top-left corner of an M x N grid.
//   It can only move RIGHT or DOWN.
//   Count the total number of UNIQUE PATHS to reach
//   the bottom-right corner.
//
// REAL-LIFE: Robot navigation, counting delivery routes on a grid map.
//
// PATTERN: "Count all ways" + "Only 2 directions" + "Grid"
//          -> DYNAMIC PROGRAMMING (Grid paths)
//
// DP DEFINITION:
//   dp[i][j] = Number of unique paths to reach cell (i, j)
//   dp[i][j] = dp[i-1][j] + dp[i][j-1]
//              (came from above OR came from left)
//   Base case: First row and first column -> all 1s (only one way)
//
// ============================================================

#include <iostream>
using namespace std;

#define MAX 15

void uniquePaths(int M, int N) {
    // dp[i][j] = number of unique paths to reach (i,j)
    long long dp[MAX][MAX];

    // Base case: First row (can only come from left)
    for (int col = 0; col < N; col++) dp[0][col] = 1;

    // Base case: First column (can only come from above)
    for (int row = 0; row < M; row++) dp[row][0] = 1;

    // Fill for all other cells
    for (int row = 1; row < M; row++) {
        for (int col = 1; col < N; col++) {
            // Either came from above (row-1, col) or from left (row, col-1)
            dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
        }
    }

    cout << "\nGrid of unique paths (dp table):" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) cout << dp[i][j] << "\t";
        cout << endl;
    }

    cout << "\nTotal unique paths from (0,0) to (" << M-1 << "," << N-1 << "): "
         << dp[M-1][N-1] << endl;

    // Mathematical formula: C(M+N-2, M-1)
    // (Choose M-1 downward moves from M+N-2 total moves)
}

int main() {
    int M, N;
    cout << "=== CASE STUDY 21: Unique Paths (DP) ===" << endl;
    cout << "Enter grid dimensions M (rows) and N (cols): ";
    cin >> M >> N;
    uniquePaths(M, N);
    return 0;
}

/*
============================
Time:  O(M * N)
Space: O(M * N) for table [O(N) if optimized to 1D]

SIMILAR: Unique Paths II (with obstacles), Minimum Cost Path (CS06)
FORMULA: C(M+N-2, M-1) = (M+N-2)! / [(M-1)! * (N-1)!]
============================
*/
