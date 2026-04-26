// Program: Naive String Matching Algorithm
// What it does: Checks for a PATTERN in TEXT by sliding the pattern
//               over the text one position at a time and comparing
//               each character one by one. Simple brute force approach.
//
// Example Input:
//   Text:    "AABAACAADAABAABA"
//   Pattern: "AABA"
// Expected Output: Pattern found at index 0, 9, 12

#include <iostream>
#include <string>
using namespace std;

// Function to perform Naive String Matching
void naiveSearch(string text, string pattern) {
    int textLength    = text.length();
    int patternLength = pattern.length();
    int matchCount    = 0;

    cout << "\nSearching for pattern \"" << pattern << "\" in text..." << endl;
    cout << "--------------------------------------------------" << endl;

    // Slide the pattern over the text, one position at a time
    // The pattern can start at positions 0 to textLength-patternLength
    for (int startPos = 0; startPos <= textLength - patternLength; startPos++) {

        // Try to match the pattern starting at position 'startPos' in text
        bool matched = true;
        for (int j = 0; j < patternLength; j++) {
            // Compare text character with pattern character
            if (text[startPos + j] != pattern[j]) {
                matched = false;  // Mismatch found, pattern doesn't start here
                break;            // No need to check further
            }
        }

        // If all characters matched, pattern is found here
        if (matched) {
            cout << "Pattern found at index: " << startPos << endl;
            matchCount++;
        }
    }

    if (matchCount == 0) {
        cout << "Pattern NOT found in the text." << endl;
    } else {
        cout << "\nTotal occurrences: " << matchCount << endl;
    }
}

int main() {
    string text, pattern;

    cout << "=== Naive String Matching Algorithm ===" << endl;
    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern to search: ";
    cin >> pattern;

    // Perform Naive String Matching
    naiveSearch(text, pattern);

    return 0;
}

/*
============================
Time Complexity:
  Best Case:    O(n)      -> Pattern not found early (first char mismatch)
  Worst Case:   O(n * m)  -> n = text length, m = pattern length
                             Example: text = "AAAAAAA", pattern = "AAAAB"

Space Complexity: O(1)   -> No extra memory used

Note: Simple but inefficient for large texts. Better algorithms: KMP, Rabin-Karp.
============================
*/
