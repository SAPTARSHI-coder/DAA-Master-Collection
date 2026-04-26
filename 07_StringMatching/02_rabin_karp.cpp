// Program: Rabin-Karp String Matching Algorithm
// What it does: Uses HASHING to find a pattern in text efficiently.
//               Instead of comparing characters one by one, it first
//               compares HASH VALUES of the pattern with hash values
//               of substrings. Only does character comparison if hashes match.
//               This avoids unnecessary comparisons.
//
// Example Input:
//   Text:    "GEEKS FOR GEEKS"
//   Pattern: "GEEK"
// Expected Output: Pattern found at index 0 and 10

#include <iostream>
#include <string>
using namespace std;

#define BASE  256    // Number of characters in input alphabet (ASCII)
#define PRIME 101    // A prime number for modular arithmetic (to avoid overflow)

// Function to perform Rabin-Karp String Matching
void rabinKarp(string text, string pattern) {
    int textLength    = text.length();
    int patternLength = pattern.length();
    int matchCount    = 0;

    // Step 1: Calculate BASE^(patternLength-1) mod PRIME
    // This is used for removing the leftmost character's hash contribution
    int basePow = 1;
    for (int i = 0; i < patternLength - 1; i++) {
        basePow = (basePow * BASE) % PRIME;
    }

    // Step 2: Calculate hash of pattern and first window of text
    int patternHash   = 0;  // Hash value of pattern
    int textWindowHash = 0; // Hash value of current text window

    for (int i = 0; i < patternLength; i++) {
        patternHash    = (BASE * patternHash + pattern[i]) % PRIME;
        textWindowHash = (BASE * textWindowHash + text[i]) % PRIME;
    }

    cout << "\nSearching for pattern \"" << pattern << "\" in text..." << endl;
    cout << "--------------------------------------------------" << endl;

    // Step 3: Slide the pattern over the text
    for (int startPos = 0; startPos <= textLength - patternLength; startPos++) {

        // Step 4: HASH MATCH - Check if hash values are equal
        if (patternHash == textWindowHash) {
            // VERIFY: Hashes match! Now check actual characters (spurious hit prevention)
            bool matched = true;
            for (int j = 0; j < patternLength; j++) {
                if (text[startPos + j] != pattern[j]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                cout << "Pattern found at index: " << startPos << endl;
                matchCount++;
            }
        }

        // Step 5: ROLLING HASH - Calculate hash for next window
        // Remove leftmost character, add new rightmost character
        if (startPos < textLength - patternLength) {
            textWindowHash = (BASE * (textWindowHash - text[startPos] * basePow)
                             + text[startPos + patternLength]) % PRIME;

            // Ensure hash is non-negative
            if (textWindowHash < 0)
                textWindowHash += PRIME;
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

    cout << "=== Rabin-Karp String Matching Algorithm ===" << endl;
    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern to search: ";
    cin >> pattern;

    // Perform Rabin-Karp String Matching
    rabinKarp(text, pattern);

    return 0;
}

/*
============================
Time Complexity:
  Best/Average Case: O(n + m) -> n = text length, m = pattern length
  Worst Case:        O(n * m) -> Many hash collisions (spurious hits)

Space Complexity: O(1)

Key Concept: Rolling Hash - efficiently updates hash when sliding window.
             Spurious Hit: When hash matches but actual string doesn't match.
============================
*/
