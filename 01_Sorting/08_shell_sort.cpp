// Program: Shell Sort
// What it does: An improved version of Insertion Sort.
//               Instead of comparing adjacent elements (gap=1),
//               it first compares elements FAR APART (large gap),
//               then gradually REDUCES the gap until gap = 1.
//               This moves elements closer to their final position
//               quickly, making final passes much cheaper.
// Example Input: 5 elements -> 12 34 54 2 3
// Expected Output: 2 3 12 34 54

#include <iostream>
using namespace std;

// Function to perform Shell Sort
void shellSort(int arr[], int size) {
    // Start with a large gap, then reduce it by half each time
    // gap = size/2, size/4, size/8, ... 1
    for (int gap = size / 2; gap > 0; gap = gap / 2) {

        cout << "\n--- Pass with gap = " << gap << " ---" << endl;

        // Perform insertion sort for elements separated by 'gap'
        // This is exactly insertion sort but with step = gap instead of 1
        for (int i = gap; i < size; i++) {

            // 'key' is the element we are trying to insert into sorted position
            int key = arr[i];
            int j   = i;

            // Shift earlier gap-sorted elements upward until correct position is found
            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];  // Shift element gap positions forward
                j -= gap;
            }

            // Place key in its correct gap-sorted position
            arr[j] = key;
        }

        // Print array after each gap pass
        cout << "Array after gap " << gap << ": ";
        for (int k = 0; k < size; k++) cout << arr[k] << " ";
        cout << endl;
    }
}

// Function to print all elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int size;

    cout << "=== Shell Sort ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    cout << "\nArray before sorting: ";
    printArray(arr, size);

    shellSort(arr, size);

    cout << "\nArray after sorting:  ";
    printArray(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n log n)  -> With optimal gap sequence
  Average Case: O(n^1.25)   -> Depends heavily on gap sequence used
  Worst Case:   O(n^2)      -> With gap sequence n/2, n/4...1

Space Complexity: O(1) -> In-place sorting, no extra memory

Key: Shell Sort is BETTER THAN Insertion Sort for large arrays because
     large gaps quickly move elements close to their correct final positions.
============================
*/
