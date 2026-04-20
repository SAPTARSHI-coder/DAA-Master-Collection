// Program: Bubble Sort
// What it does: Repeatedly compares adjacent elements and swaps them
//               if they are in the wrong order, "bubbling" the largest
//               element to the end in each pass.
// Example Input: 5 elements -> 64 34 25 12 22
// Expected Output: 12 22 25 34 64

#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    // Outer loop: controls the number of passes
    // After each pass, the largest unsorted element is placed at its correct position
    for (int pass = 0; pass < size - 1; pass++) {

        // Inner loop: compares adjacent elements in each pass
        // After i-th pass, last i elements are already sorted, so we go up to size-1-pass
        for (int j = 0; j < size - 1 - pass; j++) {

            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                // Swapping using a temporary variable
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print all elements of the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;

    cout << "=== Bubble Sort ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    printArray(arr, size);

    // Call the bubble sort function
    bubbleSort(arr, size);

    cout << "Array after sorting:  ";
    printArray(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n)      -> Already sorted (with optimization)
  Average Case: O(n^2)
  Worst Case:   O(n^2)    -> Reverse sorted array

Space Complexity: O(1)    -> In-place sorting, no extra array used
============================
*/
