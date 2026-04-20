// Program: Radix Sort
// What it does: Sorts integers digit by digit from the LEAST significant
//               digit (rightmost digit) to the MOST significant digit (leftmost).
//               Uses Counting Sort as a subroutine for each digit position.
//               Non-comparison based sort: works on digits, not comparisons.
// Example Input: 7 elements -> 170 45 75 90 802 24 2 66
// Expected Output: 2 24 45 66 75 90 170 802

#include <iostream>
using namespace std;

// Function to find the maximum element in the array
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}

// Function to do Counting Sort for a specific DIGIT POSITION
// 'digitPlace' is 1 for units, 10 for tens, 100 for hundreds, etc.
void countingSortByDigit(int arr[], int size, int digitPlace) {
    int output[size];    // Output array (stores sorted result)
    int count[10] = {0}; // Count array for digits 0-9

    // Step 1: Count occurrences of each digit at 'digitPlace' position
    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / digitPlace) % 10;  // Extract the digit
        count[digit]++;
    }

    // Step 2: Change count[i] to actual positions (cumulative count)
    // This tells us the position of this digit in the output array
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Build the output array (traverse from RIGHT to maintain stability)
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / digitPlace) % 10;   // Extract digit
        output[count[digit] - 1] = arr[i];         // Place in correct position
        count[digit]--;                            // Decrement count
    }

    // Step 4: Copy sorted output back into original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Main Radix Sort function
void radixSort(int arr[], int size) {
    // Find the maximum number to know the number of digits
    int maxVal = findMax(arr, size);

    // Process each digit position from least significant to most significant
    // digitPlace = 1 (units), 10 (tens), 100 (hundreds), ...
    int digitPlace = 1;
    int passNumber = 1;

    while (maxVal / digitPlace > 0) {
        cout << "\nPass " << passNumber << " (sorting by ";
        if      (digitPlace == 1)   cout << "Units digit";
        else if (digitPlace == 10)  cout << "Tens digit";
        else if (digitPlace == 100) cout << "Hundreds digit";
        else cout << digitPlace << "s digit";
        cout << "):" << endl;

        // Sort by current digit using Counting Sort
        countingSortByDigit(arr, size, digitPlace);

        // Display array after sorting by this digit
        cout << "Array: ";
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;

        digitPlace *= 10;  // Move to next digit position
        passNumber++;
    }
}

// Function to print all elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int size;

    cout << "=== Radix Sort ===" << endl;
    cout << "(Works best with non-negative integers)" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " non-negative integers: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    cout << "\nArray before sorting: ";
    printArray(arr, size);

    radixSort(arr, size);

    cout << "\nArray after sorting:  ";
    printArray(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  O(d * (n + b)) where:
    d = number of digits in the maximum number
    n = number of elements
    b = base (here b=10 for decimal)
  Effectively O(n) for fixed-length integers

Space Complexity: O(n + b) -> For output array and count array

Key: Radix Sort is STABLE and LINEAR-TIME but only works on integers
     (or strings that can be compared digit by digit).
============================
*/
