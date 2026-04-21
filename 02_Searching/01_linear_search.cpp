// Program: Linear Search
// What it does: Searches for a target element by checking EVERY element
//               one by one from the beginning until it finds the target
//               or reaches the end of the array.
// Example Input: Array -> 5 3 8 1 9 2, Target -> 8
// Expected Output: Element 8 found at index 2

#include <iostream>
using namespace std;

// Function to perform Linear Search
// Returns the index of the target if found, otherwise returns -1
int linearSearch(int arr[], int size, int target) {
    // Go through each element one by one
    for (int i = 0; i < size; i++) {
        // Check if current element matches the target
        if (arr[i] == target) {
            return i;  // Return the index where target is found
        }
    }
    return -1;  // Target not found in the array
}

int main() {
    int size;

    cout << "=== Linear Search ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    // Call linear search and store the result index
    int resultIndex = linearSearch(arr, size, target);

    // Check if the element was found or not
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
  Best Case:    O(1)  -> Target found at the first position
  Average Case: O(n)
  Worst Case:   O(n)  -> Target is at last position or not present

Space Complexity: O(1) -> No extra memory used

Note: Works on both sorted and unsorted arrays.
============================
*/
