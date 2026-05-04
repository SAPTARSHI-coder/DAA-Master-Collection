// ============================================================
// CASE STUDY 18: Search in a Rotated Sorted Array
// ============================================================
//
// PROBLEM STATEMENT:
//   A sorted array was ROTATED at some unknown pivot point.
//   For example: [4 5 6 7 0 1 2] is a rotation of [0 1 2 4 5 6 7].
//   Given a target value, find its INDEX in the rotated array.
//   Return -1 if not found.
//   Must be done in O(log n) time.
//
// REAL-LIFE INTERPRETATION:
//   - Circular log buffers: search in a circular log file.
//   - Time-zone adjusted sorted schedules: a 24-hr sorted list that wraps.
//   - Musical scales: finding a note in a scale starting from a different key.
//
// ============================================================
// PATTERN RECOGNITION: WHY BINARY SEARCH (MODIFIED)?
// ============================================================
//
//  WHY NOT LINEAR SEARCH? -> O(n), but problem demands O(log n).
//  WHY CAN'T WE DIRECTLY BINARY SEARCH? -> Array is NOT fully sorted.
//
//  KEY INSIGHT:
//    Even though rotated, when we split at mid:
//      - AT LEAST ONE of the two halves (left or right) is fully sorted!
//    We can check WHICH half is sorted, then decide which half to search.
//
//  DECIDING RULE:
//    If arr[left] <= arr[mid]: -> LEFT HALF is sorted
//      If target is within [arr[left], arr[mid]]: search LEFT
//      Else: search RIGHT
//    Else: -> RIGHT HALF is sorted
//      If target is within [arr[mid], arr[right]]: search RIGHT
//      Else: search LEFT
//
//  HOW TO SPOT THIS PATTERN:
//    "Binary search but with a MODIFIED condition"
//    "Array is sorted with some transformation (rotation, partial sort)"
//    -> Modified Binary Search
//
// CATEGORY: BINARY SEARCH (Modified for Rotated Array)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  low = 0, high = n - 1
//  While low <= high:
//    mid = (low + high) / 2
//    If arr[mid] == target: return mid (found!)
//    If left half is sorted (arr[low] <= arr[mid]):
//       If target is in [arr[low], arr[mid]]: high = mid - 1
//       Else: low = mid + 1
//    Else (right half is sorted):
//       If target is in [arr[mid], arr[high]]: low = mid + 1
//       Else: high = mid - 1
//
// Example:
//   Array: 4 5 6 7 0 1 2,  Target = 0
//   mid = 3, arr[mid]=7, left half [4,5,6,7] sorted, 0 NOT in [4,7] -> go right
//   low=4, high=6, mid=5, arr[mid]=1, right half [1,2] sorted, 0 NOT in [1,2] -> go left
//   low=4, high=4, mid=4, arr[mid]=0 == target -> found at index 4!
//
// ============================================================

#include <iostream>
using namespace std;

// Function to search in a rotated sorted array
int searchRotated(int arr[], int n, int target) {
    int low  = 0;
    int high = n - 1;

    cout << "\nBinary Search Trace:" << endl;
    cout << "--------------------" << endl;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        cout << "  low=" << low << " mid=" << mid << " high=" << high
             << " | arr[mid]=" << arr[mid] << endl;

        // FOUND!
        if (arr[mid] == target) {
            return mid;
        }

        // Check if the LEFT HALF is sorted
        if (arr[low] <= arr[mid]) {
            // Left half [arr[low] ... arr[mid]] is sorted

            // Is the target in the sorted left half?
            if (arr[low] <= target && target < arr[mid]) {
                // Yes, search left half
                high = mid - 1;
                cout << "  -> Left half sorted, target in left -> search left" << endl;
            } else {
                // No, search right half
                low = mid + 1;
                cout << "  -> Left half sorted, target NOT in left -> search right" << endl;
            }
        } else {
            // Right half [arr[mid] ... arr[high]] is sorted

            // Is the target in the sorted right half?
            if (arr[mid] < target && target <= arr[high]) {
                // Yes, search right half
                low = mid + 1;
                cout << "  -> Right half sorted, target in right -> search right" << endl;
            } else {
                // No, search left half
                high = mid - 1;
                cout << "  -> Right half sorted, target NOT in right -> search left" << endl;
            }
        }
    }

    return -1;  // Target not found
}

int main() {
    int n;

    cout << "================================================================" << endl;
    cout << " CASE STUDY 18: Search in Rotated Sorted Array (Modified Binary Search)" << endl;
    cout << "================================================================" << endl;
    cout << "\nEnter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the ROTATED sorted array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter the target to search: ";
    cin >> target;

    int result = searchRotated(arr, n, target);

    if (result == -1)
        cout << "\nTarget " << target << " NOT found in the array." << endl;
    else
        cout << "\nTarget " << target << " found at index " << result << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(log n) -> Binary search, halving search space each time

Space Complexity: O(1) -> Iterative approach, no extra memory

SIMILAR PROBLEMS (Same Modified Binary Search Pattern):
  1. Search in Rotated Array (with duplicates) -> Need to handle arr[low]==arr[mid]
  2. Find Minimum in Rotated Array             -> Same halving logic, find pivot
  3. Find Peak Element                         -> Binary search with local comparison
  4. Search in 2D Matrix                       -> Binary search treating 2D as 1D

KEY INSIGHT FOR VIVA:
  "In a rotated sorted array, at least ONE half is always fully sorted.
   Use that to decide which half to DISCARD."
============================
*/
