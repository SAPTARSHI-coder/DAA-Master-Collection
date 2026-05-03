// ============================================================
// CASE STUDY 09: Count Inversions in an Array
// ============================================================
//
// PROBLEM STATEMENT:
//   An INVERSION is a pair (i, j) where i < j but arr[i] > arr[j].
//   Count the total number of such inversions in an array.
//
// REAL-LIFE INTERPRETATION:
//   - Measuring how "unsorted" an array is (0 inversions = sorted).
//   - Online rating systems: count how many recommendation pairs are reversed.
//   - Supply chain: count how many delivery sequences are out of expected order.
//   - Interview coding platform: measure the disorder in user submission times.
//
// ============================================================
// PATTERN RECOGNITION: WHY DIVIDE AND CONQUER?
// ============================================================
//
//  NAIVE APPROACH: Check every pair (i,j) -> O(n^2). Too slow for large n.
//
//  KEY INSIGHT (Divide & Conquer via Modified Merge Sort):
//    When we MERGE two sorted halves during Merge Sort:
//      - While comparing elements from left and right halves,
//        if LEFT[i] > RIGHT[j], then ALL remaining elements in the
//        LEFT half (from i to mid) are also > RIGHT[j].
//        -> They ALL form inversions with RIGHT[j]!
//    So we can COUNT inversions DURING the merge step!
//
//  WHY MERGE SORT WORKS HERE:
//    Divide -> Solve both halves -> Merge and COUNT cross-inversions
//    This is Divide and Conquer naturally embedded in merge sort.
//
// CATEGORY: DIVIDE AND CONQUER (Modified Merge Sort)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Divide array into two halves.
//  Step 2: Recursively COUNT inversions in left half.
//  Step 3: Recursively COUNT inversions in right half.
//  Step 4: During MERGE: if left[i] > right[j], then
//           (mid - i + 1) inversions are added (all remaining left elements
//            are greater than right[j]).
//  Step 5: Total = inversions from left + right + cross inversions.
//
// Example:
//   Array: 5 3 2 4 1
//   Inversions: (5,3), (5,2), (5,4), (5,1), (3,2), (3,1), (2,1), (4,1) = 8
//
// ============================================================

#include <iostream>
using namespace std;

// Modified merge that counts cross-inversions during the merge step
long long mergeAndCount(int arr[], int left, int mid, int right) {
    // Sizes of the two halves
    int sizeLeft  = mid - left + 1;
    int sizeRight = right - mid;

    // Copy both halves into temporary arrays
    int leftArr[sizeLeft];
    int rightArr[sizeRight];

    for (int i = 0; i < sizeLeft; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < sizeRight; j++)
        rightArr[j] = arr[mid + 1 + j];

    long long inversions = 0;  // Count of cross-inversions found during merge

    int i = 0;      // Pointer for left half
    int j = 0;      // Pointer for right half
    int k = left;   // Pointer for merged result

    // Merge and count
    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            // leftArr[i] > rightArr[j]
            // Since leftArr is sorted, ALL remaining elements in leftArr
            // (from index i to sizeLeft-1) are also > rightArr[j]
            // Each forms an inversion with rightArr[j]
            inversions += (sizeLeft - i);  // Count all remaining left elements
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < sizeLeft)  { arr[k++] = leftArr[i++]; }
    while (j < sizeRight) { arr[k++] = rightArr[j++]; }

    return inversions;
}

// Recursive divide and conquer function
long long countInversions(int arr[], int left, int right) {
    long long inversions = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in left half
        inversions += countInversions(arr, left, mid);

        // Count inversions in right half
        inversions += countInversions(arr, mid + 1, right);

        // Count cross-inversions during merge
        inversions += mergeAndCount(arr, left, mid, right);
    }

    return inversions;
}

int main() {
    int n;

    cout << "==========================================================" << endl;
    cout << " CASE STUDY 09: Count Inversions (Divide & Conquer - Modified Merge Sort)" << endl;
    cout << "==========================================================" << endl;
    cout << "\nEnter the number of elements: ";
    cin >> n;

    int arr[n];
    int original[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        original[i] = arr[i];
    }

    long long result = countInversions(arr, 0, n - 1);

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) cout << original[i] << " ";
    cout << endl;

    cout << "\nSorted array:   ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "\nTotal number of inversions: " << result << endl;
    cout << "(An inversion is a pair (i,j) where i<j but arr[i]>arr[j])" << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(n log n) -> Same as merge sort (divide log n levels, merge O(n) each)

Space Complexity: O(n) -> For temporary arrays during merge

Brute Force Comparison:
  Naive approach: O(n^2) -> Check ALL pairs
  Divide & Conquer: O(n log n) -> Significantly faster for large n

SIMILAR PROBLEMS (Same Divide & Conquer via Merge Sort):
  1. Sort and Count      -> Count pairs with specific property
  2. Count smaller after self -> For each element, count smaller on the right
  3. Reverse Pairs      -> Count (i,j) where arr[i] > 2*arr[j], i < j
============================
*/
