// Program: Selection Sort
// What it does: Divides the array into sorted and unsorted parts.
//               In each pass, it SELECTS the minimum element from the
//               unsorted part and places it at the beginning of that part.
// Example Input: 5 elements -> 29 10 14 37 13
// Expected Output: 10 13 14 29 37

#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int size) {
    // Outer loop: represents the boundary between sorted and unsorted part
    // After each pass, one more element is sorted at position i
    for (int i = 0; i < size - 1; i++) {

        // Assume the first element of the unsorted part is the minimum
        int minIndex = i;

        // Inner loop: find the actual minimum element in the unsorted part
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Update minIndex if a smaller element is found
            }
        }

        // If the minimum element is not already at position i, swap it
        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
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

    cout << "=== Selection Sort ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    printArray(arr, size);

    // Call the selection sort function
    selectionSort(arr, size);

    cout << "Array after sorting:  ";
    printArray(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n^2)
  Average Case: O(n^2)
  Worst Case:   O(n^2)   -> Always makes n*(n-1)/2 comparisons

Space Complexity: O(1)   -> In-place sorting, no extra memory needed
============================
*/
