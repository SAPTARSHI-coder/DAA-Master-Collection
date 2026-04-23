// Program: 0/1 Knapsack (Recursive + Memoization) - Alternative approach
// What it does: Same as 0/1 Knapsack but using TOP-DOWN memoization
//               approach (Recursion + Cache). Shows recursive thinking.
// Every item is either included (1) or excluded (0).
//
// Example Input: Capacity=10, Items: (wt=2,val=6), (wt=2,val=10), (wt=3,val=12)
// Expected Output: Max Value = 28

#include <iostream>
using namespace std;

#define MAX 100
int memo[MAX][MAX];  // Memoization table, -1 = not computed yet

// Recursive function to find max value
// n = items remaining to consider, capacity = remaining capacity
int knapsackRecursive(int weight[], int value[], int n, int capacity) {
    // Base case: No items left or no capacity
    if (n == 0 || capacity == 0) return 0;

    // Check if already computed (memoization lookup)
    if (memo[n][capacity] != -1) return memo[n][capacity];

    // Option 1: Don't include item n (skip it)
    int notTaken = knapsackRecursive(weight, value, n - 1, capacity);

    // Option 2: Include item n (only if its weight fits)
    int taken = 0;
    if (weight[n - 1] <= capacity) {
        taken = value[n - 1] +
                knapsackRecursive(weight, value, n - 1, capacity - weight[n - 1]);
    }

    // Store result in memo table and return maximum
    memo[n][capacity] = max(notTaken, taken);
    return memo[n][capacity];
}

int main() {
    int n, capacity;

    cout << "=== 0/1 Knapsack (Memoization / Top-Down DP) ===" << endl;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int weight[n], value[n];

    cout << "\nEnter weight and value for each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " -> Weight: "; cin >> weight[i];
        cout << "Item " << i + 1 << " -> Value: ";  cin >> value[i];
    }

    // Initialize memo table to -1 (nothing computed yet)
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= capacity; j++)
            memo[i][j] = -1;

    int maxValue = knapsackRecursive(weight, value, n, capacity);
    cout << "\nMaximum Value in Knapsack: " << maxValue << endl;

    return 0;
}

/*
============================
Time Complexity:  O(n * W) -> Same as tabulation; each subproblem solved once
Space Complexity: O(n * W) -> Memo table + recursive call stack

Note: Memoization (top-down) vs Tabulation (bottom-up) both achieve same
      complexity, but memoization is more intuitive as it follows natural recursion.
============================
*/
