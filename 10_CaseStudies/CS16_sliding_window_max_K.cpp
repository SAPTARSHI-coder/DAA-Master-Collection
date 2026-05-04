// ============================================================
// CASE STUDY 16: Maximum Sum Subarray of Size K (Sliding Window)
// ============================================================
//
// PROBLEM STATEMENT:
//   Given an array and an integer K, find the MAXIMUM SUM of any
//   CONTIGUOUS subarray of EXACTLY SIZE K.
//
// REAL-LIFE INTERPRETATION:
//   - Stock market: find the K-day period with maximum average return.
//   - Network monitoring: find the K-second window with max data throughput.
//   - Weather: find the K-day stretch with highest total rainfall.
//   - Exam: find K consecutive questions with maximum total marks.
//
// ============================================================
// PATTERN RECOGNITION: WHY SLIDING WINDOW?
// ============================================================
//
//  NAIVE APPROACH: For each starting position, sum K elements -> O(n*k).
//
//  KEY INSIGHT (Sliding Window):
//    When we "slide" the window one step to the right:
//      NEW sum = OLD sum - (element leaving window) + (element entering window)
//    So each slide costs only O(1), not O(k)!
//
//  HOW TO SPOT SLIDING WINDOW:
//    1. "Contiguous subarray/substring of FIXED size"
//    2. "Maximum/Minimum/Sum of elements in a window"
//    3. The window "slides" to the right one by one
//    -> FIXED SIZE SLIDING WINDOW
//
//  VARIATIONS:
//    Fixed Window:    Window size is constant K -> this problem
//    Variable Window: Window size changes based on condition -> Two Pointers
//
// CATEGORY: SLIDING WINDOW (Fixed Size)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Compute sum of the FIRST window (first K elements).
//  Step 2: maxSum = firstWindowSum.
//  Step 3: Slide the window one step at a time:
//            currentSum = currentSum - arr[outgoing element] + arr[incoming element]
//  Step 4: Update maxSum if currentSum > maxSum.
//  Step 5: Return maxSum.
//
// Example:
//   Array: 2 1 5 1 3 2  ,  K = 3
//   Window 1: 2+1+5 = 8
//   Window 2: 1+5+1 = 7  (slide: remove 2, add 1)
//   Window 3: 5+1+3 = 9  (slide: remove 1, add 3)
//   Window 4: 1+3+2 = 6  (slide: remove 5, add 2)
//   Maximum Sum = 9
//
// ============================================================

#include <iostream>
using namespace std;

// Function to find maximum sum subarray of size K using Sliding Window
void maxSumSubarrayK(int arr[], int n, int k) {
    if (k > n) {
        cout << "K is larger than array size!" << endl;
        return;
    }

    // Step 1: Compute sum of first window (first K elements)
    int currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }

    int maxSum      = currentSum;   // Initialize max sum with first window
    int maxStart    = 0;            // Starting index of max sum window

    cout << "\nSliding Window Trace:" << endl;
    cout << "----------------------" << endl;
    cout << "Window [0 to " << k-1 << "]: Sum = " << currentSum << endl;

    // Step 2 & 3: Slide the window from index k to n-1
    for (int i = k; i < n; i++) {
        // Slide the window:
        // - Remove the OUTGOING element (arr[i - k]) from the left
        // - Add the INCOMING element (arr[i]) on the right
        currentSum = currentSum - arr[i - k] + arr[i];

        cout << "Window [" << i-k+1 << " to " << i << "]: "
             << "Sum = " << currentSum
             << " (removed " << arr[i-k] << ", added " << arr[i] << ")" << endl;

        // Step 4: Update maxSum and track which window gave this max
        if (currentSum > maxSum) {
            maxSum   = currentSum;
            maxStart = i - k + 1;  // New window starts at i - k + 1
        }
    }

    // Display result
    cout << "\nMaximum Sum Subarray of size " << k << ":" << endl;
    cout << "  Sum = " << maxSum << endl;
    cout << "  Subarray: [";
    for (int i = maxStart; i < maxStart + k; i++) {
        cout << arr[i];
        if (i < maxStart + k - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "  Starting at index " << maxStart << endl;
}

int main() {
    int n, k;

    cout << "==========================================================" << endl;
    cout << " CASE STUDY 16: Max Sum Subarray of Size K (Sliding Window)" << endl;
    cout << "==========================================================" << endl;
    cout << "\nEnter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter the window size K: ";
    cin >> k;

    maxSumSubarrayK(arr, n, k);

    return 0;
}

/*
============================
Time Complexity:
  O(n) -> Each element is added and removed from window exactly once
  Naive approach: O(n * k)

Space Complexity: O(1) -> Only a few variables used

SIMILAR PROBLEMS (Same Sliding Window Pattern):
  1. Average of Subarrays of Size K     -> Same, just divide by K
  2. First Negative in Every Window     -> Track which negatives are in window
  3. Count Distinct in Window           -> Fixed window distinct element count
  4. Max of Every Window (Deque-based)  -> Use deque for O(1) max queries

SLIDING WINDOW TYPES:
  Fixed Size   -> Window size stays constant K
  Variable Size -> Expand/shrink window based on a condition (Two Pointers)
============================
*/
