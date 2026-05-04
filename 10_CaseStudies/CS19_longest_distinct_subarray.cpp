// ============================================================
// CASE STUDY 19: Longest Subarray with Distinct Elements
// ============================================================
//
// PROBLEM STATEMENT:
//   Given an array of integers, find the LENGTH of the LONGEST
//   CONTIGUOUS SUBARRAY that contains all DISTINCT elements (no repetition).
//
// REAL-LIFE INTERPRETATION:
//   - Finding the longest period without repeated security access codes.
//   - Network: longest sequence of unique packet IDs (no duplicate transmission).
//   - Text analysis: longest window of unique characters in a string.
//   - Game: longest streak of different moves without repeating.
//
// ============================================================
// PATTERN RECOGNITION: WHY SLIDING WINDOW (Variable Size)?
// ============================================================
//
//  NAIVE APPROACH: Check every subarray -> O(n^2) or O(n^3).
//
//  KEY INSIGHT (Variable Size Sliding Window):
//    Maintain a window [left, right] where ALL elements are DISTINCT.
//    - Expand right whenever the new element is unique in the window.
//    - If duplicate found: SHRINK the window from the LEFT until
//      the duplicate is removed.
//    - At each step, track the MAXIMUM window size seen.
//
//  HOW TO SPOT VARIABLE SLIDING WINDOW:
//    1. "Longest/shortest subarray/substring"
//    2. Subject to a CONDITION on the window's content
//    3. The window GROWS and SHRINKS based on whether the condition is met
//    -> Variable Size Sliding Window
//
//  DIFFERENCE FROM FIXED WINDOW (CS16):
//    Fixed Window: Size K is constant, just slide right.
//    Variable Window: Shrink from left when condition is violated.
//
// CATEGORY: SLIDING WINDOW (Variable Size) + HASH / FREQUENCY TRACKING
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Use: left pointer, right pointer, frequency count array
//
//  Step 1: Start with left = right = 0.
//  Step 2: Move right pointer forward.
//  Step 3: If arr[right] is already in window (count > 0):
//            -> Shrink window from LEFT until duplicate is removed.
//  Step 4: Mark arr[right] as present, update max length.
//  Step 5: Repeat until right reaches end.
//
// Example:
//   Array: 1 2 1 3 4 2 3
//   Window: [1,2] -> add 1 (dup!) -> shrink left -> [2,1] ... -> [3,4,2,3]?
//   Max length = 4 (subarray [1,3,4,2] or [3,4,2,3])
//
// ============================================================

#include <iostream>
using namespace std;

#define MAX_VALUE 10000  // Assuming elements are within this range

// Function to find longest subarray with all distinct elements
void longestDistinctSubarray(int arr[], int n) {
    // Frequency count: how many times each element appears in current window
    int count[MAX_VALUE + 1];
    for (int i = 0; i <= MAX_VALUE; i++) count[i] = 0;

    int left      = 0;  // Left boundary of the window
    int maxLength = 0;  // Maximum length of valid window found
    int maxStart  = 0;  // Starting index of the best window

    cout << "\nSliding Window Trace:" << endl;
    cout << "---------------------" << endl;

    // Move right pointer from 0 to n-1
    for (int right = 0; right < n; right++) {
        // Expand: mark arr[right] as inside the window
        count[arr[right]]++;

        // If arr[right] appears MORE than ONCE in the window -> shrink from left
        while (count[arr[right]] > 1) {
            // Remove arr[left] from the window (shrink from left)
            count[arr[left]]--;
            left++;  // Move left boundary forward
        }

        // Current window [left, right] has all distinct elements
        int currentLength = right - left + 1;

        cout << "Window [" << left << " to " << right << "]: length = "
             << currentLength << ", elements = { ";
        for (int i = left; i <= right; i++) cout << arr[i] << " ";
        cout << "}" << endl;

        // Update maximum length
        if (currentLength > maxLength) {
            maxLength = currentLength;
            maxStart  = left;
        }
    }

    // Display result
    cout << "\nLongest subarray with distinct elements:" << endl;
    cout << "  Length: " << maxLength << endl;
    cout << "  Subarray: [ ";
    for (int i = maxStart; i < maxStart + maxLength; i++) cout << arr[i] << " ";
    cout << "]" << endl;
    cout << "  Starting index: " << maxStart << endl;
}

int main() {
    int n;

    cout << "================================================================" << endl;
    cout << " CASE STUDY 19: Longest Subarray with Distinct Elements" << endl;
    cout << "         (Variable Size Sliding Window)" << endl;
    cout << "================================================================" << endl;
    cout << "\nEnter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements (positive integers up to " << MAX_VALUE << "): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    longestDistinctSubarray(arr, n);

    return 0;
}

/*
============================
Time Complexity:
  O(n) -> Left and right pointers each move at most n times total

Space Complexity: O(MAX_VALUE) -> For frequency/count array
                  O(n) if using a hash map

SIMILAR PROBLEMS (Same Variable Sliding Window Pattern):
  1. Longest Substring Without Repeating Chars  -> Classic string version of this
  2. Longest Subarray with Sum <= K             -> Shrink when sum exceeds K
  3. Minimum Window Substring                   -> Find smallest window containing all chars
  4. Max Consecutive Ones III                   -> Flip at most K zeros

SLIDING WINDOW VARIANTS:
  Fixed Size K: sum/average of window of size K
  Variable (expand-shrink): longest/shortest with condition on content
============================
*/
