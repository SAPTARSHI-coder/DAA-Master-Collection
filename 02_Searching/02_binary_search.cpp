// Program: Binary Search
// What it does: Searches a SORTED array by repeatedly halving the search space.
//               Compares target with middle element; if smaller, search left half;
//               if larger, search right half. Much faster than linear search.
// IMPORTANT: Array must be sorted before applying Binary Search!
// Example Input: Sorted Array -> 1 3 5 7 9 11 13, Target -> 7
// Expected Output: Element 7 found at index 3

#include <iostream>
using namespace std;

// Function to perform Binary Search (Iterative version)
// Returns the index of the target if found, otherwise returns -1
int binarySearch(int arr[], int size, int target) {
    int low  = 0;        // Start of the search range
    int high = size - 1; // End of the search range

    // Keep searching while there is a valid range
    while (low <= high) {
        // Calculate the middle index (avoids overflow compared to (low+high)/2)
        int mid = low + (high - low) / 2;

        // Case 1: Target found at middle position
        if (arr[mid] == target) {
            return mid;
        }

        // Case 2: Target is greater than middle -> search in right half
        else if (arr[mid] < target) {
            low = mid + 1;  // Discard left half
        }

        // Case 3: Target is smaller than middle -> search in left half
        else {
            high = mid - 1;  // Discard right half
        }
    }

    return -1;  // Target not found
}

int main() {
    int size;

    cout << "=== Binary Search ===" << endl;
    cout << "(IMPORTANT: Array must be sorted before searching!)" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements in SORTED order: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    // Call binary search
    int resultIndex = binarySearch(arr, size, target);

    // Display result
    if (resultIndex != -1) {
        cout << "\nElement " << target << " found at index " << resultIndex
             << " (position " << resultIndex + 1 << ")" << endl;
    } else {
        cout << "\nElement " << target << " NOT found in the array." << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(1)       -> Target found at the middle position
  Average Case: O(log n)
  Worst Case:   O(log n)   -> Halves search space each time

Space Complexity: O(1)     -> Iterative approach, no extra memory

Note: Only works on sorted arrays. Faster than linear search for large arrays.
============================
*/
