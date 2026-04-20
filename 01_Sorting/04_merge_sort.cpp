// Program: Merge Sort
// What it does: A Divide and Conquer algorithm.
//               It divides the array into two halves, recursively sorts
//               each half, and then MERGES the two sorted halves.
// Example Input: 6 elements -> 38 27 43 3 9 82
// Expected Output: 3 9 27 38 43 82

#include <iostream>
using namespace std;

// Function to merge two sorted halves of the array
// Left half:  arr[left...mid]
// Right half: arr[mid+1...right]
void merge(int arr[], int left, int mid, int right) {
    // Calculate sizes of the two sub-arrays to be merged
    int sizeLeft  = mid - left + 1;
    int sizeRight = right - mid;

    // Create temporary arrays to hold the two halves
    int leftArr[sizeLeft];
    int rightArr[sizeRight];

    // Copy data into temporary left and right arrays
    for (int i = 0; i < sizeLeft; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < sizeRight; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the two temporary arrays back into arr[left...right]
    int i = 0;       // Index for leftArr
    int j = 0;       // Index for rightArr
    int k = left;    // Index for merged array

    // Compare elements from both arrays and pick the smaller one
    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr (if any)
    while (i < sizeLeft) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr (if any)
    while (j < sizeRight) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive function to divide the array and sort using merge
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort the left half
        mergeSort(arr, left, mid);

        // Recursively sort the right half
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
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

    cout << "=== Merge Sort ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    printArray(arr, size);

    // Call merge sort with full array range
    mergeSort(arr, 0, size - 1);

    cout << "Array after sorting:  ";
    printArray(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n log n)
  Average Case: O(n log n)
  Worst Case:   O(n log n) -> Always divides into equal halves

Space Complexity: O(n)    -> Uses extra temporary arrays for merging
============================
*/
