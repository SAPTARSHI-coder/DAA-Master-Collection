// Program: Binary Search (Recursive) + Interpolation Search
// What it does: Two alternative search algorithms for sorted arrays.
//   1. Binary Search (Recursive) - same logic as iterative but uses recursion
//   2. Interpolation Search - improved binary search for UNIFORMLY distributed data.
//      Instead of always going to mid, it ESTIMATES where the target might be
//      (like how we search in a dictionary - go to roughly the right page).
//
// Example Input: Sorted Array -> 1 3 5 7 9 11 13 15 17 19, Target -> 7

#include <iostream>
using namespace std;

// === Binary Search (Recursive) ===
int binarySearchRecursive(int arr[], int low, int high, int target) {
    // Base case: search space is invalid -> not found
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;         // Found!
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target); // Search right
    else
        return binarySearchRecursive(arr, low, mid - 1, target);  // Search left
}

// === Interpolation Search ===
// Works best when elements are UNIFORMLY distributed (like searching a phone book)
// Instead of always going to middle, it estimates position using a formula.
int interpolationSearch(int arr[], int size, int target) {
    int low  = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        // INTERPOLATION FORMULA: Estimate position based on value distribution
        // pos = low + [(target - arr[low]) / (arr[high] - arr[low])] * (high - low)
        // This is like saying: "If target is 30% of the way between arr[low] and arr[high],
        // it's probably at about 30% of the index range."
        int pos = low + ((long long)(target - arr[low]) * (high - low))
                        / (arr[high] - arr[low]);

        if (arr[pos] == target) return pos;
        if (arr[pos] < target)  low  = pos + 1;  // Target is in right half
        else                    high = pos - 1;  // Target is in left half
    }
    return -1;
}

int main() {
    int size;

    cout << "=== Recursive Binary Search + Interpolation Search ===" << endl;
    cout << "Enter number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter elements in SORTED order: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    int target;
    cout << "Enter the target to search: ";
    cin >> target;

    int res1 = binarySearchRecursive(arr, 0, size - 1, target);
    int res2 = interpolationSearch(arr, size, target);

    cout << "\nBinary Search (Recursive):    ";
    if (res1 != -1) cout << "Found at index " << res1 << endl;
    else cout << "Not found" << endl;

    cout << "Interpolation Search:         ";
    if (res2 != -1) cout << "Found at index " << res2 << endl;
    else cout << "Not found" << endl;

    return 0;
}

/*
============================
Binary Search (Recursive):
  Time:  O(log n) — same as iterative
  Space: O(log n) — recursive call stack

Interpolation Search:
  Best/Average: O(log log n) — when data is uniformly distributed
  Worst Case:   O(n)         — when data is heavily skewed (exponential values)
  Space: O(1)

When to use Interpolation Search:
  -> Uniformly distributed data (e.g., phone book, sorted timestamps)
  -> Much faster than Binary Search in those cases
============================
*/
