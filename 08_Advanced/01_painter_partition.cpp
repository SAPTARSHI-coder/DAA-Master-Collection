// Program: Painter's Partition Problem (Binary Search + Greedy)
// What it does: Given N boards with different lengths and K painters,
//               each painter can only paint CONTIGUOUS boards.
//               Find the MINIMUM amount of time to paint all boards
//               when all painters work simultaneously.
// Approach: Binary Search on the answer (minimum time).
//            Check if a given "time limit" allows K or fewer painters.
//
// Example Input:
//   Boards: 10 20 30 40
//   Number of painters: 2
// Expected Output: Minimum time = 60 (painter 1: 10+20+30, painter 2: 40)

#include <iostream>
using namespace std;

// Function to check if boards can be painted in 'maxTime' by at most 'k' painters
// Returns true if possible, false otherwise
bool canPaint(int boards[], int n, int k, int maxTime) {
    int paintersRequired = 1;  // Start with one painter
    int currentTime      = 0;  // Current painter's assigned work time

    for (int i = 0; i < n; i++) {
        // If a single board is longer than maxTime, it's impossible
        if (boards[i] > maxTime) return false;

        // If adding this board exceeds maxTime, assign to a new painter
        if (currentTime + boards[i] > maxTime) {
            paintersRequired++;  // Need one more painter
            currentTime = boards[i];  // New painter starts with this board

            // If we need more painters than available, this maxTime is too small
            if (paintersRequired > k) return false;
        } else {
            currentTime += boards[i];  // Add board to current painter's work
        }
    }
    return true;  // Possible within k painters
}

// Function to find the minimum time using Binary Search
int painterPartition(int boards[], int n, int k) {
    // Binary search range:
    // Low  = max board length (minimum possible answer - one board per painter)
    // High = sum of all boards (maximum possible answer - one painter does all)
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];  // Max single board
        high += boards[i];                      // Sum of all boards
    }

    int result = high;

    // Binary search on the answer
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Try this as the maximum allowed time

        if (canPaint(boards, n, k, mid)) {
            result = mid;     // This time works, try to minimize further
            high   = mid - 1; // Search left half
        } else {
            low = mid + 1;    // This time is too small, search right half
        }
    }

    return result;
}

int main() {
    int n, k;

    cout << "=== Painter's Partition Problem (Binary Search) ===" << endl;
    cout << "Enter the number of boards: ";
    cin >> n;

    int boards[n];

    cout << "Enter the length of each board: ";
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }

    cout << "Enter the number of painters: ";
    cin >> k;

    // Find and display the minimum time
    int minTime = painterPartition(boards, n, k);

    cout << "\nMinimum time to paint all boards: " << minTime << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(n * log(sum)) -> Binary search on answer (log(sum)), validate in O(n) each time
  sum = total sum of all board lengths

Space Complexity: O(1)

Key Concept: Binary Search on the Answer - search space is the possible answer range.
============================
*/
