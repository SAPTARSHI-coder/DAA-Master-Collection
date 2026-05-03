// ============================================================
// CASE STUDY 03: Arrange Numbers to Form the Largest Number
// ============================================================
//
// PROBLEM STATEMENT:
//   Given a list of non-negative integers, arrange them such that
//   they form the LARGEST POSSIBLE NUMBER when concatenated together.
//
// REAL-LIFE INTERPRETATION:
//   - Stock market: arrange deal codes to form the highest value ID.
//   - Document filing: arrange document numbers for max reference value.
//   - Puzzle: join number tiles to maximize the resulting number.
//
// ============================================================
// PATTERN RECOGNITION: WHY GREEDY (CUSTOM COMPARATOR)?
// ============================================================
//
//  NAIVE IDEA (WRONG): Sort numbers in descending order.
//  WHY WRONG? 9 and 90 -> descending gives 9, 90 -> "990" ✓
//             But: 9 and 91 -> "991" vs "919" -> "991" is larger
//                  3 and 30 -> "330" vs "303" -> "330" is larger
//
//  CORRECT GREEDY RULE:
//    Compare two numbers A and B by checking which concatenation is larger:
//    If AB > BA, then A should come BEFORE B.
//
//  WHY THIS WORKS (Greedy Proof):
//    The ordering is TRANSITIVE and gives a globally optimal arrangement.
//
// CATEGORY: GREEDY with CUSTOM COMPARISON
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Convert numbers to strings (easier to concatenate).
//  Step 2: Sort using a CUSTOM COMPARATOR:
//          For strings a and b: if (a + b) > (b + a), put 'a' first.
//  Step 3: Concatenate all sorted strings.
//  Step 4: Handle edge case: if result starts with '0', output just "0".
//
// Example:
//   Input: 3 30 34 5 9
//   Compare 9 vs 5:  "95" > "59" -> 9 comes first
//   Compare 5 vs 34: "534" > "345" -> 5 comes first
//   ... and so on
//   Output: 9 5 34 3 30 -> "9534330"
//
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// Function to compare two numbers A and B as strings
// Returns true if A should come BEFORE B in the final arrangement
bool shouldComeBefore(string a, string b) {
    // Concatenate both ways and compare
    string ab = a + b;  // A before B
    string ba = b + a;  // B before A

    // If "AB" gives larger number, A should come first
    return ab > ba;
}

// Sort the number-strings using bubble sort with custom comparator
void customSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // If arr[j+1] should come before arr[j], swap
            if (shouldComeBefore(arr[j + 1], arr[j])) {
                string temp   = arr[j];
                arr[j]        = arr[j + 1];
                arr[j + 1]    = temp;
            }
        }
    }
}

// Function to form the largest number
void largestNumber(int numbers[], int n) {
    // Step 1: Convert all integers to strings
    string strNumbers[n];
    for (int i = 0; i < n; i++) {
        strNumbers[i] = to_string(numbers[i]);
    }

    // Step 2: Sort using custom comparator (greedy rule)
    customSort(strNumbers, n);

    // Step 3: Concatenate all sorted strings
    string result = "";
    for (int i = 0; i < n; i++) {
        result += strNumbers[i];
    }

    // Step 4: Handle edge case where all numbers are 0
    // If the largest number starts with '0', the result is just "0"
    if (result[0] == '0') {
        result = "0";
    }

    cout << "\nThe Largest Number formed: " << result << endl;
}

int main() {
    int n;

    cout << "========================================================" << endl;
    cout << " CASE STUDY 03: Largest Number (Greedy + Custom Sort)" << endl;
    cout << "========================================================" << endl;
    cout << "\nEnter the count of numbers: ";
    cin >> n;

    int numbers[n];

    cout << "Enter " << n << " non-negative integers: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    largestNumber(numbers, n);

    cout << "\nExplanation of Custom Sort Rule:" << endl;
    cout << "  For any two numbers A and B:" << endl;
    cout << "  If string(A+B) > string(B+A), then A should come first." << endl;

    return 0;
}

/*
============================
Time Complexity:
  Sorting with custom comparator: O(n^2 * L) where L = avg string length
  Concatenation: O(n * L)
  Total: O(n^2 * L)

Space Complexity: O(n * L) -> For storing strings

SIMILAR PROBLEMS (Same Pattern - Custom Greedy Comparator):
  1. Minimum Number formed from array    -> sort so AB < BA (reverse condition)
  2. Task Scheduling to Minimize Penalty -> compare tasks by custom criteria
  3. Sort Array for Maximum Product      -> different custom comparison
============================
*/
