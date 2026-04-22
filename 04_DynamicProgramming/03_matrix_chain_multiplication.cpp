// Program: Matrix Chain Multiplication (MCM) - Dynamic Programming
// What it does: Given a sequence of matrices, find the MOST EFFICIENT way
//               to multiply them (i.e., the order that minimizes the total
//               number of scalar multiplications).
//               The parenthesization matters! Multiplication is ASSOCIATIVE
//               but different orders can give drastically different costs.
//
// Example Input:
//   4 matrices: A(10x30), B(30x5), C(5x60), D(?) 
//   Dimensions array: 10 30 5 60
//   (Matrix i has dimensions p[i-1] x p[i])
// Expected Output: Minimum multiplications = 27000

#include <iostream>
using namespace std;

// Function to solve Matrix Chain Multiplication using DP
void matrixChainMultiplication(int dimensions[], int n) {
    // n = number of matrices
    // dimensions array has n+1 values
    // Matrix i has dimensions: dimensions[i-1] x dimensions[i]

    // dp[i][j] = Minimum cost to multiply matrices from index i to j
    int dp[n][n];

    // split[i][j] = The split point k that gave minimum cost for matrices i..j
    int split[n][n];

    // Step 1: Initialize diagonal (single matrix has 0 cost)
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Step 2: Fill for chains of increasing length
    // 'len' is the length of the chain being considered
    for (int len = 2; len <= n; len++) {

        // 'i' is the starting matrix index of the chain
        for (int i = 0; i < n - len + 1; i++) {

            // 'j' is the ending matrix index
            int j = i + len - 1;

            dp[i][j] = INT_MAX;  // Start with infinity

            // Try all possible split points k between i and j
            for (int k = i; k < j; k++) {
                // Cost = cost of left part + cost of right part + cost of multiplying them
                // Cost of multiplying matrix(i..k) with matrix(k+1..j):
                //   = rows of matrix i * cols of matrix k * cols of matrix j
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];

                // Update if this split gives lower cost
                if (cost < dp[i][j]) {
                    dp[i][j]    = cost;
                    split[i][j] = k;  // Record the best split point
                }
            }
        }
    }

    // The answer is in dp[0][n-1] (all n matrices)
    cout << "\nMinimum number of multiplications: " << dp[0][n - 1] << endl;

    // Print the optimal parenthesization
    // (We use a simple recursive approach to print the split)
    cout << "\nDP Table (dp[i][j] = min cost for matrices i to j):" << endl;
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j)
                cout << "  -  \t";  // Lower triangle is not used
            else
                cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "=== Matrix Chain Multiplication (Dynamic Programming) ===" << endl;
    cout << "Enter the number of matrices: ";
    cin >> n;

    // For n matrices, we need n+1 dimensions
    int dimensions[n + 1];

    cout << "\nEnter " << n + 1 << " values representing matrix dimensions:" << endl;
    cout << "(Matrix i has dimensions: dim[i-1] x dim[i])" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "Dimension[" << i << "]: ";
        cin >> dimensions[i];
    }

    // Solve Matrix Chain Multiplication
    matrixChainMultiplication(dimensions, n);

    return 0;
}

/*
============================
Time Complexity:
  O(n^3) -> Three nested loops (chain length, start index, split point)

Space Complexity: O(n^2) -> For the 2D dp and split tables

Key Concept: The order of matrix multiplication affects efficiency drastically.
             DP finds the optimal parenthesization.
============================
*/
