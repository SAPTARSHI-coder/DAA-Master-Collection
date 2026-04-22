// Program: 0/1 Knapsack Problem (Dynamic Programming)
// What it does: Given items with weights and values, and a knapsack with
//               limited capacity, find the maximum value you can carry.
//               UNLIKE Fractional Knapsack, you CANNOT take partial items.
//               Each item is either taken fully (1) or not taken at all (0).
// Approach: Build a 2D table where dp[i][w] = max value using first i items
//            with knapsack capacity w.
//
// Example Input:
//   Capacity = 50
//   Items:  Weight  Value
//     1:      10     60
//     2:      20     100
//     3:      30     120
// Expected Output: Max Value = 220 (Items 2 and 3)

#include <iostream>
using namespace std;

// Function to solve 0/1 Knapsack using Dynamic Programming
void knapsack01(int weight[], int value[], int n, int capacity) {
    // Create a 2D DP table
    // dp[i][w] = Maximum value achievable using first i items with capacity w
    int dp[n + 1][capacity + 1];

    // Step 1: Initialize base cases
    // dp[0][w] = 0 (no items -> no value)
    // dp[i][0] = 0 (no capacity -> no value)
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int w = 0; w <= capacity; w++)
        dp[0][w] = 0;

    // Step 2: Fill the DP table row by row
    for (int i = 1; i <= n; i++) {           // For each item
        for (int w = 1; w <= capacity; w++) { // For each capacity

            // Option A: Don't include item i
            // Value = same as without this item
            int notTaken = dp[i - 1][w];

            // Option B: Include item i (only if it fits in current capacity)
            int taken = 0;
            if (weight[i - 1] <= w) {
                // Value = value of item i + best value with remaining capacity
                taken = value[i - 1] + dp[i - 1][w - weight[i - 1]];
            }

            // Take the maximum of both options
            dp[i][w] = max(notTaken, taken);
        }
    }

    // The answer is in the bottom-right cell
    cout << "\nMaximum Value in Knapsack: " << dp[n][capacity] << endl;

    // Step 3: Trace back to find which items were selected
    cout << "\nItems selected:" << endl;
    cout << "---------------" << endl;
    int w = capacity;
    for (int i = n; i > 0; i--) {
        // If the value changed, it means item i was included
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i
                 << " -> Weight: " << weight[i - 1]
                 << ", Value: " << value[i - 1] << endl;
            w -= weight[i - 1];  // Reduce capacity by this item's weight
        }
    }
}

int main() {
    int n, capacity;

    cout << "=== 0/1 Knapsack Problem (Dynamic Programming) ===" << endl;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int weight[n], value[n];

    cout << "\nEnter weight and value for each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " -> Weight: ";
        cin >> weight[i];
        cout << "Item " << i + 1 << " -> Value: ";
        cin >> value[i];
    }

    // Solve 0/1 Knapsack
    knapsack01(weight, value, n, capacity);

    return 0;
}

/*
============================
Time Complexity:
  O(n * W) -> n = number of items, W = knapsack capacity
  Fills every cell in the n x W table

Space Complexity: O(n * W) -> For the 2D dp table
============================
*/
