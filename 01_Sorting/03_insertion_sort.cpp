// Program: Insertion Sort
// What it does: Builds a sorted array one element at a time.
//               It picks each element and INSERTS it into its correct
//               position in the already-sorted left portion.
//               Works like sorting playing cards in your hand.
// Example Input: 5 elements -> 12 11 13 5 6
// Expected Output: 5 6 11 12 13

#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int size) {
    // Start from the second element (index 1) because a single element is always sorted
    for (int i = 1; i < size; i++) {

        // Pick the current element to be inserted into sorted part
        int key = arr[i];

        // j is the index of the last element in the sorted portion
        int j = i - 1;

        // Shift elements of the sorted portion that are greater than 'key'
        // one position to the right to make space for 'key'
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element one position to the right
            j--;                   // Move to the previous element
        }

        // Place the key in its correct position
        arr[j + 1] = key;
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

    cout << "=== Insertion Sort ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    printArray(arr, size);

    // Call the insertion sort function
    insertionSort(arr, size);

    cout << "Array after sorting:  ";
    printArray(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n)     -> Already sorted array (inner while loop doesn't run)
  Average Case: O(n^2)
  Worst Case:   O(n^2)  -> Reverse sorted array (maximum shifts needed)

Space Complexity: O(1)  -> In-place sorting
============================
*/
