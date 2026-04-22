// Program: Longest Increasing Subsequence (LIS) - Dynamic Programming
// What it does: Finds the length of the longest subsequence in an array
//               such that all elements are in STRICTLY INCREASING order.
//               (Elements don't need to be contiguous in the original array)
//
// Example Input: 10 9 2 5 3 7 101 18
// Expected Output: LIS Length = 4, LIS = 2 3 7 101 (or 2 5 7 101)

#include <iostream>
using namespace std;

// Function to find the Longest Increasing Subsequence using DP
void longestIncreasingSubsequence(int arr[], int n) {
    // dp[i] = Length of LIS ending at index i (including arr[i])
    int dp[n];

    // parent[i] = Index of previous element in LIS ending at i
    // Used for tracing back the actual subsequence
    int parent[n];

    // Initialize: every single element is an LIS of length 1
    for (int i = 0; i < n; i++) {
        dp[i]     = 1;
        parent[i] = -1;  // No parent initially
    }

    // Step: For each element, find the best previous element to extend from
    for (int i = 1; i < n; i++) {
        // Look at all previous elements
        for (int j = 0; j < i; j++) {
            // If arr[j] is smaller than arr[i], we can extend the LIS
            if (arr[j] < arr[i]) {
                // If extending from j gives a longer LIS at i, update
                if (dp[j] + 1 > dp[i]) {
                    dp[i]     = dp[j] + 1;
                    parent[i] = j;  // Record that j comes before i in LIS
                }
            }
        }
    }

    // Find the index where LIS ends (maximum value in dp array)
    int maxLength = 0;
    int endIndex  = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            endIndex  = i;
        }
    }

    cout << "\nLIS Length: " << maxLength << endl;

    // Trace back to find the actual LIS elements
    int lis[maxLength];
    int idx = maxLength - 1;
    int current = endIndex;

    while (current != -1) {
        lis[idx] = arr[current];  // Store element
        idx--;
        current = parent[current];  // Go to previous element
    }

    cout << "LIS Elements: ";
    for (int i = 0; i < maxLength; i++) {
        cout << lis[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;

    cout << "=== Longest Increasing Subsequence (Dynamic Programming) ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find and display LIS
    longestIncreasingSubsequence(arr, n);

    return 0;
}

/*
============================
Time Complexity:
  O(n^2) -> Two nested loops

Space Complexity: O(n) -> For dp and parent arrays
============================
*/
