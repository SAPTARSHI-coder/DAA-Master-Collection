// Program: KMP - Knuth-Morris-Pratt String Matching Algorithm
// What it does: Efficiently finds all occurrences of a pattern in text.
//               Uses a PREPROCESSED array called LPS (Longest Proper Prefix
//               which is also Suffix) to SKIP unnecessary comparisons when
//               a mismatch occurs. NEVER re-compares text characters unnecessarily.
//
// Example Input:
//   Text:    "AAACAAAB"
//   Pattern: "AAAB"
// Expected Output: Pattern found at index 4

#include <iostream>
#include <string>
using namespace std;

// Function to build the LPS (Longest Proper Prefix = Suffix) array
// LPS[i] = length of longest proper prefix of pattern[0..i] which is also a suffix
// This tells us: when a mismatch occurs at position i, 
//                we can restart matching from lps[i-1] instead of from the beginning
void buildLPS(string pattern, int patternLength, int lps[]) {
    lps[0] = 0;  // First character has no proper prefix
    int length = 0;  // Length of previous longest prefix-suffix
    int i = 1;

    // Build LPS array for index 1 to patternLength-1
    while (i < patternLength) {
        if (pattern[i] == pattern[length]) {
            // Characters match: extend the prefix-suffix length
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                // Don't increment i here; use previous LPS value
                length = lps[length - 1];
            } else {
                // No prefix-suffix possible for this position
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search Function
void kmpSearch(string text, string pattern) {
    int textLength    = text.length();
    int patternLength = pattern.length();
    int matchCount    = 0;

    // Step 1: Build the LPS array for the pattern
    int lps[patternLength];
    buildLPS(pattern, patternLength, lps);

    cout << "\nLPS Array (used for skipping): ";
    for (int k = 0; k < patternLength; k++) cout << lps[k] << " ";
    cout << endl;

    cout << "\nSearching for pattern \"" << pattern << "\" in text..." << endl;
    cout << "--------------------------------------------------" << endl;

    int i = 0;  // Index for text
    int j = 0;  // Index for pattern

    while (i < textLength) {
        // Characters match, advance both indices
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == patternLength) {
            // Pattern found! Starting index = i - j
            cout << "Pattern found at index: " << i - j << endl;
            matchCount++;

            // Use LPS to continue searching (don't restart from 0)
            j = lps[j - 1];
        }
        // Mismatch after j matches
        else if (i < textLength && text[i] != pattern[j]) {
            if (j != 0) {
                // Use LPS to skip unnecessary comparisons
                j = lps[j - 1];
            } else {
                // No prefix match, simply move to next text character
                i++;
            }
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

    cout << "=== KMP (Knuth-Morris-Pratt) String Matching ===" << endl;
    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern to search: ";
    cin >> pattern;

    // Perform KMP String Matching
    kmpSearch(text, pattern);

    return 0;
}

/*
============================
Time Complexity:
  Preprocessing (BuildLPS): O(m)      -> m = pattern length
  Searching:                O(n)      -> n = text length
  Total:                    O(n + m)

Space Complexity: O(m) -> For the LPS array

Key Advantage: Text pointer NEVER goes backward. Much better than Naive O(n*m).
LPS Array: Tells us how many characters to skip on mismatch.
============================
*/
