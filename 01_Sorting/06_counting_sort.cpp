// Program: Counting Sort
// What it does: A non-comparison based sorting algorithm.
//               It counts the frequency of each element and uses
//               those counts to place elements in sorted order.
//               Works best when elements are in a limited range (0 to MAX).
// Example Input: 7 elements -> 4 2 2 8 3 3 1
// Expected Output: 1 2 2 3 3 4 8

#include <iostream>
using namespace std;

// Function to perform Counting Sort
void countingSort(int arr[], int size) {
    // Step 1: Find the maximum element in the array
    //         We need this to decide the size of the count array
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Step 2: Create a count array of size (maxElement + 1)
    //         Initialize all counts to 0
    int countArr[maxElement + 1];
    for (int i = 0; i <= maxElement; i++) {
        countArr[i] = 0;
    }

    // Step 3: Count the frequency of each element
    //         countArr[x] = number of times x appears in arr
    for (int i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }

    // Step 4: Reconstruct the sorted array using the count array
    //         For each value i, place it countArr[i] times in the output
    int index = 0;  // Index for placing elements back in arr
    for (int i = 0; i <= maxElement; i++) {
        while (countArr[i] > 0) {
            arr[index] = i;   // Place value i at current index
            index++;
            countArr[i]--;    // Decrease count
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

    cout << "=== Counting Sort ===" << endl;
    cout << "(Works best with non-negative integers in a small range)" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " non-negative integer elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before sorting: ";
    printArray(arr, size);

    // Call counting sort
    countingSort(arr, size);

    cout << "Array after sorting:  ";
    printArray(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n + k)  -> n = number of elements, k = range of input
  Average Case: O(n + k)
  Worst Case:   O(n + k)

Space Complexity: O(k)    -> Extra count array of size k (max element + 1)

Note: Not suitable when range (k) is much larger than n.
============================
*/
