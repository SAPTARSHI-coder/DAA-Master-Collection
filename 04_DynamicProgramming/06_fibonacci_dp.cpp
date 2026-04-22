// Program: Fibonacci using Dynamic Programming (Memoization and Tabulation)
// What it does: Computes the Nth Fibonacci number using DP.
//               AVOIDS recalculating the same subproblems that happen in
//               naive recursion (which is exponentially slow).
//
// Fibonacci sequence: 0 1 1 2 3 5 8 13 21 34 ...
// F(0)=0, F(1)=1, F(n) = F(n-1) + F(n-2)
//
// Example Input: N = 10
// Expected Output: F(10) = 55

#include <iostream>
using namespace std;

// Method 1: TABULATION (Bottom-Up DP)
// Build the solution from smallest subproblem to largest
long long fibonacciTabulation(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // dp[i] = Fibonacci of i
    long long dp[n + 1];

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Fill table from bottom up
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Method 2: MEMOIZATION (Top-Down DP with cache)
// Recursive but stores results to avoid re-computation
long long memo[1000];  // Cache to store computed values (-1 = not computed yet)

long long fibonacciMemoization(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // If already computed, return stored value (avoid recomputation)
    if (memo[n] != -1) return memo[n];

    // Compute and store result in memo array
    memo[n] = fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2);

    return memo[n];
}

int main() {
    int n;

    cout << "=== Fibonacci using Dynamic Programming ===" << endl;
    cout << "Enter the value of N: ";
    cin >> n;

    // Initialize memo array to -1 (nothing computed yet)
    for (int i = 0; i <= n; i++) memo[i] = -1;

    cout << "\n--- Method 1: Tabulation (Bottom-Up) ---" << endl;
    cout << "F(" << n << ") = " << fibonacciTabulation(n) << endl;

    cout << "\n--- Method 2: Memoization (Top-Down) ---" << endl;
    cout << "F(" << n << ") = " << fibonacciMemoization(n) << endl;

    // Display Fibonacci sequence up to N
    cout << "\nFibonacci sequence F(0) to F(" << n << "):" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "F(" << i << ") = " << fibonacciTabulation(i) << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  Naive Recursion:   O(2^n)   -> Exponential (without DP)
  Memoization:       O(n)     -> Each subproblem solved ONCE
  Tabulation:        O(n)     -> Fill table once

Space Complexity:
  Memoization:   O(n) -> memo array + recursive call stack
  Tabulation:    O(n) -> dp array
  Optimized:     O(1) -> Only keep last 2 values (not shown here)
============================
*/
