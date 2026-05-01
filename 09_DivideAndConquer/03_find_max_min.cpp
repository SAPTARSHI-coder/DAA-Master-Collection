// Program: Find Maximum and Minimum using Divide and Conquer
// What it does: Finds both the MAXIMUM and MINIMUM of an array using
//               the Divide and Conquer technique.
//               Naive approach compares each element twice -> 2(n-1) comparisons.
//               D&C approach needs only about 3n/2 comparisons (more efficient).
//
// Example Input: 8 elements -> 3 9 1 5 8 2 7 4
// Expected Output: Maximum = 9, Minimum = 1

#include <iostream>
using namespace std;

// Structure to return both min and max together
struct MinMax {
    int minimum;
    int maximum;
};

// Divide and Conquer function to find min and max
MinMax findMinMax(int arr[], int left, int right) {
    MinMax result;

    // BASE CASE 1: Only ONE element -> it's both min and max
    if (left == right) {
        result.minimum = arr[left];
        result.maximum = arr[left];
        return result;
    }

    // BASE CASE 2: Only TWO elements -> compare them directly
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            result.minimum = arr[left];
            result.maximum = arr[right];
        } else {
            result.minimum = arr[right];
            result.maximum = arr[left];
        }
        return result;
    }

    // DIVIDE: Split array into two halves
    int mid = left + (right - left) / 2;

    // CONQUER: Recursively find min and max of each half
    MinMax leftResult  = findMinMax(arr, left, mid);
    MinMax rightResult = findMinMax(arr, mid + 1, right);

    // COMBINE: Overall min = smaller of the two minimums
    //          Overall max = larger of the two maximums
    result.minimum = min(leftResult.minimum, rightResult.minimum);
    result.maximum = max(leftResult.maximum, rightResult.maximum);

    return result;
}

// Naive approach for comparison
void naiveFindMinMax(int arr[], int size) {
    int minVal = arr[0], maxVal = arr[0];
    int comparisons = 0;

    for (int i = 1; i < size; i++) {
        comparisons++;
        if (arr[i] < minVal) minVal = arr[i];
        comparisons++;
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    cout << "\nNaive approach:         Min = " << minVal
         << ", Max = " << maxVal
         << " (Comparisons: " << comparisons << ")" << endl;
}

int main() {
    int size;

    cout << "=== Find Max and Min using Divide and Conquer ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    // Divide and Conquer approach
    MinMax result = findMinMax(arr, 0, size - 1);

    cout << "\nD&C approach:           Min = " << result.minimum
         << ", Max = " << result.maximum
         << " (Comparisons: ~" << (3 * size / 2) << ")" << endl;

    // Naive approach for comparison
    naiveFindMinMax(arr, size);

    return 0;
}

/*
============================
Time Complexity:
  O(n) -> Every element is visited exactly once
  Number of comparisons: 3n/2 - 2  (vs 2n-2 for naive)

Space Complexity: O(log n) -> Recursive call stack depth

Key: When n is even: 3n/2 - 2 comparisons
     When n is odd:  3(n-1)/2 comparisons
     Always fewer than naive 2(n-1) comparisons.
============================
*/
