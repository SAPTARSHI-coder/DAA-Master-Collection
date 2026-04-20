// Program: Heap Sort
// What it does: Uses a MAX HEAP data structure to sort elements.
//               A Max-Heap is a COMPLETE BINARY TREE where each parent node
//               is GREATER THAN OR EQUAL TO its children.
//               Step 1: Build a Max-Heap from the array.
//               Step 2: Repeatedly extract the maximum (root) and place at end.
//
// Example Input: 12 11 13 5 6 7
// Expected Output: 5 6 7 11 12 13

#include <iostream>
using namespace std;

// Function to "heapify" a subtree rooted at index 'rootIndex'
// in array of size 'heapSize'.
// Ensures that the subtree satisfies the MAX-HEAP property.
void heapify(int arr[], int heapSize, int rootIndex) {
    int largest      = rootIndex;          // Assume root is the largest
    int leftChild    = 2 * rootIndex + 1;  // Left child index
    int rightChild   = 2 * rootIndex + 2;  // Right child index

    // If left child exists and is greater than current largest
    if (leftChild < heapSize && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    // If right child exists and is greater than current largest
    if (rightChild < heapSize && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    // If largest is NOT the root, we need to swap and re-heapify
    if (largest != rootIndex) {
        // Swap root with the largest child
        int temp         = arr[rootIndex];
        arr[rootIndex]   = arr[largest];
        arr[largest]     = temp;

        // Recursively fix the affected subtree
        heapify(arr, heapSize, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: BUILD MAX-HEAP from the array
    // Start from the last non-leaf node and heapify down to root
    // Last non-leaf node is at index n/2 - 1
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: EXTRACT elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current MAX (root of heap) to the end of array
        int temp   = arr[0];
        arr[0]     = arr[i];
        arr[i]     = temp;

        // Re-heapify the reduced heap (excluding the last sorted element)
        heapify(arr, i, 0);
    }
}

// Function to print all elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;

    cout << "=== Heap Sort ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nArray before sorting: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Array after sorting:  ";
    printArray(arr, n);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n log n)
  Average Case: O(n log n)
  Worst Case:   O(n log n) -> Always same performance

Space Complexity: O(1) -> In-place sorting (heapify uses O(log n) stack)

Key: Build heap = O(n), Extract each element = O(log n), Total = O(n log n)
============================
*/
