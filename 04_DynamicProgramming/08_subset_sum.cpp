// Program: Subset Sum Problem (Dynamic Programming)
// What it does: Given a set of non-negative integers and a target sum,
//               determine if there EXISTS a SUBSET of those integers
//               whose elements add up to exactly the target sum.
//
// Example Input:
//   Set: 3 34 4 12 5 2
//   Target Sum: 9
// Expected Output: YES, subset {4, 5} or {3, 4, 2} adds up to 9

#include <iostream>
using namespace std;

// Function to solve Subset Sum using DP
void subsetSum(int arr[], int n, int targetSum) {
    // dp[i][s] = true if we can make sum 's' using first 'i' elements
    bool dp[n + 1][targetSum + 1];

    // Base case 1: If target sum is 0, answer is always TRUE (empty subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Base case 2: If no elements (i=0), we can't make any non-zero sum
    for (int s = 1; s <= targetSum; s++) {
        dp[0][s] = false;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= targetSum; s++) {
            // Option 1: Don't include element arr[i-1]
            // Can we make sum 's' without this element?
            dp[i][s] = dp[i - 1][s];

            // Option 2: Include element arr[i-1] (only if it fits in sum 's')
            if (arr[i - 1] <= s) {
                // Can we make (s - arr[i-1]) without this element?
                dp[i][s] = dp[i][s] || dp[i - 1][s - arr[i - 1]];
            }
        }
    }

    // Answer is in dp[n][targetSum]
    if (dp[n][targetSum]) {
        cout << "\nYES! A subset with sum " << targetSum << " EXISTS." << endl;

        // Trace back to find which elements form the subset
        cout << "Subset elements: { ";
        int s = targetSum;
        for (int i = n; i > 0; i--) {
            // If value changed from row i-1 to row i, element i was included
            if (dp[i][s] && !dp[i - 1][s]) {
                cout << arr[i - 1] << " ";
                s -= arr[i - 1];  // Reduce sum
            }
        }
        cout << "}" << endl;

    } else {
        cout << "\nNO! Cannot form a subset with sum " << targetSum << "." << endl;
    }
}

int main() {
    int n, targetSum;

    cout << "=== Subset Sum Problem (Dynamic Programming) ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    // Solve Subset Sum
    subsetSum(arr, n, targetSum);

    return 0;
}

/*
============================
Time Complexity:
  O(n * targetSum) -> Fill every cell in the n x targetSum table

Space Complexity: O(n * targetSum) -> For the 2D dp table
============================
*/
