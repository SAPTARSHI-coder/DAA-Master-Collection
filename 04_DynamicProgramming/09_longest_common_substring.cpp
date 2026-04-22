// Program: Longest Common Substring (Dynamic Programming)
// What it does: Finds the LONGEST CONTIGUOUS substring common to
//               both strings. Unlike LCS, characters MUST be contiguous.
//
// Example Input:
//   String 1: "abcde"
//   String 2: "abfce"
// Expected Output: Longest Common Substring = "ab" (length 2)
// Note: Difference from LCS - "ace" is LCS but NOT a common SUBSTRING

#include <iostream>
#include <string>
using namespace std;

// Function to find Longest Common Substring using DP
void longestCommonSubstring(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // dp[i][j] = Length of longest common SUBSTRING ending at str1[i-1] and str2[j-1]
    int dp[m + 1][n + 1];
    int maxLength = 0;    // Length of longest common substring found
    int endIndex  = 0;    // Ending index in str1 for the longest substring

    // Initialize all to 0
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            // If characters match, extend the current common substring
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                // Update maximum length if this is longer
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex  = i;  // Current position in str1
                }
            } else {
                // Characters don't match - common substring BREAKS here
                dp[i][j] = 0;
            }
        }
    }

    cout << "\nLongest Common Substring Length: " << maxLength << endl;

    if (maxLength > 0) {
        // Extract the substring from str1 using endIndex and maxLength
        string result = str1.substr(endIndex - maxLength, maxLength);
        cout << "Longest Common Substring: \"" << result << "\"" << endl;
    } else {
        cout << "No common substring found." << endl;
    }
}

int main() {
    string str1, str2;

    cout << "=== Longest Common Substring (Dynamic Programming) ===" << endl;
    cout << "Enter first string:  ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // Find and display Longest Common Substring
    longestCommonSubstring(str1, str2);

    return 0;
}

/*
============================
Time Complexity:
  O(m * n) -> m and n are lengths of the two strings

Space Complexity: O(m * n) -> For the 2D dp table

KEY DIFFERENCE:
  LCS (Subsequence) -> Characters can SKIP (non-contiguous)
  LCS (Substring)   -> Characters must be CONTIGUOUS
============================
*/
