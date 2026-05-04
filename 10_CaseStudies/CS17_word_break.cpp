// ============================================================
// CASE STUDY 17: Word Break Problem
// ============================================================
//
// PROBLEM STATEMENT:
//   Given a string 's' and a dictionary of words,
//   determine if 's' can be segmented into a SPACE-SEPARATED
//   SEQUENCE OF DICTIONARY WORDS.
//
// REAL-LIFE INTERPRETATION:
//   - Spell checker breaking "helloworld" into "hello world".
//   - Autocorrect segmenting mistyped words.
//   - Search engine parsing: "icecream" -> "ice cream".
//   - DNA analysis: segment a DNA strand into known gene sequences.
//
// ============================================================
// PATTERN RECOGNITION: WHY DYNAMIC PROGRAMMING?
// ============================================================
//
//  BRUTE FORCE: Try all possible ways to split the string -> exponential.
//
//  KEY OBSERVATION: OVERLAPPING SUBPROBLEMS
//    wordBreak("leetcode") -> check "l" in dict, recurse on "eetcode"
//                          -> check "le" in dict, recurse on "etcode"
//                          ...
//    If we compute wordBreak("etcode") in multiple branches -> redundant!
//
//  DP DEFINITION:
//    dp[i] = true if the first i characters of 's' can be segmented.
//    dp[0] = true (empty string is always valid)
//
//  TRANSITION:
//    dp[i] = true IF there exists some j < i such that:
//              dp[j] = true  AND  s[j..i-1] is in the dictionary
//
//  HOW TO SPOT THIS PATTERN:
//    "Can we split/partition a string?"
//    -> Check all prefixes + use stored results for suffixes -> DP
//
// CATEGORY: DYNAMIC PROGRAMMING (String Partitioning)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  dp[0] = true (empty prefix = valid base case)
//  For each ending position i (1 to n):
//     For each starting position j (0 to i-1):
//       If dp[j] == true  AND  s[j..i-1] is in dictionary:
//          Set dp[i] = true, break inner loop
//  Answer: dp[n] (can full string be segmented?)
//
// Example:
//   string = "leetcode"
//   dict = {"leet", "code"}
//   dp[0]=T, dp[4]=T (s[0..3]="leet"), dp[8]=T (s[4..7]="code")
//   Answer: YES
//
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// Function to check if a word exists in the dictionary
bool isInDictionary(string word, string dict[], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (dict[i] == word) return true;
    }
    return false;
}

// Dynamic Programming function for Word Break
void wordBreak(string str, string dict[], int dictSize) {
    int n = str.length();

    // dp[i] = true means the first i characters can be segmented into dict words
    bool dp[n + 1];
    for (int i = 0; i <= n; i++) dp[i] = false;

    dp[0] = true;  // Base case: empty string is always valid

    // Fill dp from index 1 to n
    for (int i = 1; i <= n; i++) {
        // Try all possible starting points j for the current ending position i
        for (int j = 0; j < i; j++) {
            // Check if:
            // 1. The first j characters can be segmented (dp[j] is true)
            // 2. The substring from j to i-1 is in the dictionary
            if (dp[j] == true) {
                string currentWord = str.substr(j, i - j);  // s[j..i-1]
                if (isInDictionary(currentWord, dict, dictSize)) {
                    dp[i] = true;
                    break;  // No need to check other j values for this i
                }
            }
        }
    }

    // Display the DP table
    cout << "\nDP Table (dp[i] = can first i chars be segmented?):" << endl;
    cout << "  dp[0] (empty) = true" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "  dp[" << i << "] (\"" << str.substr(0, i) << "\") = "
             << (dp[i] ? "true" : "false") << endl;
    }

    cout << "\nResult: \"" << str << "\" ";
    if (dp[n]) {
        cout << "CAN be segmented into dictionary words!" << endl;

        // Traceback to find one valid segmentation
        cout << "One valid segmentation: ";
        int i = n;
        string segmentation = "";
        while (i > 0) {
            for (int j = 0; j < i; j++) {
                if (dp[j]) {
                    string word = str.substr(j, i - j);
                    if (isInDictionary(word, dict, dictSize)) {
                        segmentation = "\"" + word + "\" " + segmentation;
                        i = j;
                        break;
                    }
                }
            }
        }
        cout << segmentation << endl;
    } else {
        cout << "CANNOT be segmented into dictionary words." << endl;
    }
}

int main() {
    string str;
    int dictSize;

    cout << "======================================================" << endl;
    cout << " CASE STUDY 17: Word Break Problem (Dynamic Programming)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter the string to check: ";
    cin >> str;

    cout << "Enter the number of dictionary words: ";
    cin >> dictSize;

    string dict[dictSize];
    cout << "Enter the dictionary words one by one:" << endl;
    for (int i = 0; i < dictSize; i++) {
        cout << "Word " << i + 1 << ": ";
        cin >> dict[i];
    }

    wordBreak(str, dict, dictSize);

    return 0;
}

/*
============================
Time Complexity:
  O(n^2 * L) -> n = string length, L = avg word length for substring comparison

Space Complexity: O(n) -> For the dp array

SIMILAR PROBLEMS (Same String Partition DP Pattern):
  1. Word Break II         -> Print ALL valid segmentations
  2. Palindrome Partition  -> Min cuts to partition string into palindromes
  3. Decode Ways           -> Count ways to decode a numeric string
  4. Burst Balloons        -> Partition array to maximize coins

KEY INSIGHT:
  "Can string[0..n] be partitioned?" -> DP where dp[i] represents
   the first i characters being validly segmented.
============================
*/
