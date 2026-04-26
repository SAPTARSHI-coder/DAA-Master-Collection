// Program: Subset Sum Problem (Backtracking)
// What it does: Given a set of POSITIVE integers and a TARGET sum,
//               find and print ALL SUBSETS that add up to the target.
//               (The DP version only tells you IF it's possible.
//                This BACKTRACKING version finds ALL actual subsets.)
// Uses BACKTRACKING: include/exclude each element, backtrack when sum exceeds target.
//
// Example Input: Set = {1, 2, 3, 4, 5}, Target = 5
// Expected Output:
//   {1, 4}
//   {2, 3}
//   {5}

#include <iostream>
using namespace std;

int arr[100];       // Input set
int n;              // Number of elements
int targetSum;      // Target sum
int subset[100];    // Current subset being built
int subsetSize;     // How many elements are currently in the subset
int solutionCount;  // How many valid subsets found

// Display the current subset
void printSubset() {
    cout << "  Subset " << solutionCount << ": { ";
    for (int i = 0; i < subsetSize; i++) cout << subset[i] << " ";
    cout << "} = " << targetSum << endl;
}

// Recursive backtracking function
// index      = current position in arr we are deciding on (include or exclude)
// currentSum = sum of elements included so far in 'subset'
void findSubsets(int index, int currentSum) {
    // BASE CASE: Current sum equals target -> Found a valid subset!
    if (currentSum == targetSum) {
        solutionCount++;
        printSubset();
        return;  // Don't explore further (all positive numbers, adding more only increases sum)
    }

    // If we've gone past all elements, or sum already exceeds target -> stop
    if (index >= n || currentSum > targetSum) {
        return;
    }

    // CHOICE 1: INCLUDE arr[index] in the subset
    subset[subsetSize] = arr[index];  // Add to current subset
    subsetSize++;
    findSubsets(index + 1, currentSum + arr[index]);  // Recurse with this element added

    // BACKTRACK: Remove arr[index] from subset
    subsetSize--;

    // CHOICE 2: EXCLUDE arr[index] from the subset
    findSubsets(index + 1, currentSum);  // Recurse WITHOUT this element
}

int main() {
    cout << "=== Subset Sum Problem (Backtracking) ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter the target sum: ";
    cin >> targetSum;

    subsetSize    = 0;
    solutionCount = 0;

    cout << "\nAll subsets that sum to " << targetSum << ":" << endl;
    cout << "--------------------------------------" << endl;

    findSubsets(0, 0);

    if (solutionCount == 0) {
        cout << "  No subset found with sum = " << targetSum << endl;
    } else {
        cout << "\nTotal subsets found: " << solutionCount << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(2^n) -> Each element is either included or excluded (2 choices each)

Space Complexity: O(n) -> For subset array and recursion stack depth

DIFFERENCE from DP version (04_DynamicProgramming/08_subset_sum.cpp):
  DP:          Answers YES/NO in O(n * sum) — can it be done?
  Backtracking: Answers WHERE (finds ALL actual subsets) — which subsets?

SIMILAR: Sum of Subsets in Backtracking course is same as this problem.
============================
*/
