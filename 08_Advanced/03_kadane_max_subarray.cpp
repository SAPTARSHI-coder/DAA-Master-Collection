// Program: Maximum Subarray Sum - Kadane's Algorithm
// What it does: Finds the contiguous subarray within a 1D array of numbers
//               that has the LARGEST SUM.
//               Uses a simple greedy/DP approach in a single pass.
//
// Example Input: -2 1 -3 4 -1 2 1 -5 4
// Expected Output: Maximum sum = 6, Subarray = [4, -1, 2, 1]

#include <iostream>
using namespace std;

// Kadane's Algorithm to find maximum subarray sum
void kadane(int arr[], int n) {
    int currentSum = arr[0];    // Sum of current subarray being considered
    int maxSum     = arr[0];    // Maximum sum found so far

    int currentStart = 0;  // Start index of current subarray
    int bestStart    = 0;  // Start index of best subarray found
    int bestEnd      = 0;  // End index of best subarray found

    for (int i = 1; i < n; i++) {
        // Decision: Should we extend the current subarray or start a new one?
        if (currentSum + arr[i] > arr[i]) {
            // It's better to extend the current subarray
            currentSum = currentSum + arr[i];
        } else {
            // It's better to START FRESH from this element
            currentSum   = arr[i];
            currentStart = i;  // New subarray starts here
        }

        // Update maximum if current sum is better
        if (currentSum > maxSum) {
            maxSum    = currentSum;
            bestStart = currentStart;
            bestEnd   = i;
        }
    }

    cout << "\nMaximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray: [ ";
    for (int i = bestStart; i <= bestEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    cout << "Starting index: " << bestStart << ", Ending index: " << bestEnd << endl;
}

int main() {
    int n;

    cout << "=== Maximum Subarray Sum - Kadane's Algorithm ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements (can be negative): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find Maximum Subarray Sum using Kadane's Algorithm
    kadane(arr, n);

    return 0;
}

/*
============================
Time Complexity:
  O(n) -> Single pass through the array

Space Complexity: O(1) -> Only a few variables used

Key Idea: At each step, decide to extend existing subarray or start fresh.
          Keep tracking maximum seen so far.
============================
*/
