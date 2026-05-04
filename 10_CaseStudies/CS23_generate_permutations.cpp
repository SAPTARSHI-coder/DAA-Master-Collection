// ============================================================
// CASE STUDY 23: Generate All Permutations (Backtracking)
// ============================================================
//
// PROBLEM STATEMENT:
//   Given an array of DISTINCT integers, generate ALL possible
//   permutations (all orderings of all elements).
//
// REAL-LIFE: Password cracking (all orderings of known chars),
//            scheduling all possible task orderings, anagram generation.
//
// ============================================================
// PATTERN RECOGNITION: WHY BACKTRACKING?
// ============================================================
//
//  "Generate ALL arrangements" = BACKTRACKING
//  At each position, swap-in each unused element, recurse, then SWAP BACK.
//
//  APPROACH (Swap-based):
//    fix(start, arr):
//      if start == n: print permutation
//      for i from start to n-1:
//        swap(arr[start], arr[i])    <- Choose arr[i] for position 'start'
//        fix(start + 1, arr)         <- Fix rest
//        swap(arr[start], arr[i])    <- BACKTRACK (restore)
//
// ============================================================

#include <iostream>
using namespace std;

int arr[20];
int n;
int permCount;

void generatePermutations(int start) {
    if (start == n) {
        permCount++;
        cout << "  Permutation " << permCount << ": { ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "}" << endl;
        return;
    }

    // Try FIXING each remaining element at position 'start'
    for (int i = start; i < n; i++) {
        // Bring arr[i] to position 'start' by swapping
        int temp    = arr[start];
        arr[start]  = arr[i];
        arr[i]      = temp;

        // Fix remaining positions recursively
        generatePermutations(start + 1);

        // BACKTRACK: Restore original order
        temp        = arr[start];
        arr[start]  = arr[i];
        arr[i]      = temp;
    }
}

int main() {
    cout << "=== CASE STUDY 23: All Permutations (Backtracking) ===" << endl;
    cout << "Enter number of elements (max 8 recommended): ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    permCount = 0;
    cout << "\nAll " << 1 * 2 * 3 << " permutations:" << endl;
    // Compute n! for display
    int factorial = 1;
    for (int i = 1; i <= n; i++) factorial *= i;
    cout << "Total expected: " << factorial << " permutations" << endl << endl;

    generatePermutations(0);

    return 0;
}

/*
============================
Time:  O(n! * n) -> n! permutations, each takes O(n) to print
Space: O(n) -> Recursion depth = n

SIMILAR (Same "generate all" backtracking pattern):
  Generate all subsets    -> Include/exclude each element
  Generate all parentheses -> Add '(' or ')' with constraints
  Letter combinations of phone number -> Backtrack through each digit's chars
============================
*/
