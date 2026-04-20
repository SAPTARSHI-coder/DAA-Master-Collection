// Program: Quick Sort
// What it does: A Divide and Conquer algorithm.
//               It selects a PIVOT element, partitions the array such that
//               all elements less than pivot come before it, and all elements
//               greater come after it. Then recursively sorts the two halves.
// Example Input: 6 elements -> 10 7 8 9 1 5
// Expected Output: 1 5 7 8 9 10

#include <iostream>
using namespace std;

// Function to partition the array around a pivot
// Pivot is chosen as the LAST element
// Returns the final index of the pivot after partitioning
int partition(int arr[], int low, int high) {
    // Choose the last element as the pivot
    int pivot = arr[high];

    // i is the index of the smaller element
    // It tracks the correct position of the pivot
    int i = low - 1;

    // Traverse through all elements, compare each with pivot
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Move boundary of smaller elements

            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct position (after all smaller elements)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Return the index where pivot is now placed
    return i + 1;
}

// Recursive function to apply quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before the pivot
        quickSort(arr, low, pivotIndex - 1);

        // Recursively sort elements after the pivot
        quickSort(arr, pivotIndex + 1, high);
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

    cout << "=== Quick Sort ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    printArray(arr, size);

    // Call quick sort with full array range
    quickSort(arr, 0, size - 1);

    cout << "Array after sorting:  ";
    printArray(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n log n) -> Pivot always divides into equal halves
  Average Case: O(n log n)
  Worst Case:   O(n^2)    -> Pivot is always smallest or largest (sorted array)

Space Complexity: O(log n) -> Recursive call stack
============================
*/
