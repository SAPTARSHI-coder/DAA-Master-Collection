// Program: Longest Common Subsequence (LCS) - Dynamic Programming
// What it does: Finds the length of the LONGEST sequence of characters
//               that appears in the SAME ORDER in both strings.
//               (Not necessarily contiguous - gaps are allowed)
//
// Example Input:
//   String 1: "ABCBDAB"
//   String 2: "BDCAB"
// Expected Output: LCS Length = 4, LCS = "BCAB" or "BDAB"

#include <iostream>
#include <string>
using namespace std;

// Function to find LCS using Dynamic Programming
void longestCommonSubsequence(string str1, string str2) {
    int m = str1.length();  // Length of first string
    int n = str2.length();  // Length of second string

    // Create a 2D DP table
    // dp[i][j] = length of LCS of str1[0..i-1] and str2[0..j-1]
    int dp[m + 1][n + 1];

    // Step 1: Initialize base cases
    // When one string is empty, LCS = 0
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Step 2: Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            // If characters match, take diagonal value + 1
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // If characters don't match, take max of left or top value
            else {
                int fromTop  = dp[i - 1][j];  // Skip character from str1
                int fromLeft = dp[i][j - 1];  // Skip character from str2
                dp[i][j] = max(fromTop, fromLeft);
            }
        }
    }

    cout << "\nLCS Length: " << dp[m][n] << endl;

    // Step 3: Trace back to find the actual LCS string
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        // If characters match, this character is part of LCS
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;  // Add character at front
            i--;
            j--;
        }
        // Move in the direction with larger value
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;  // Move up in the table
        } else {
            j--;  // Move left in the table
        }
    }

    cout << "LCS String: " << lcs << endl;
}

int main() {
    string str1, str2;

    cout << "=== Longest Common Subsequence (Dynamic Programming) ===" << endl;
    cout << "Enter first string:  ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // Find and display the LCS
    longestCommonSubsequence(str1, str2);

    return 0;
}

/*
============================
Time Complexity:
  O(m * n) -> m and n are lengths of the two strings
  Fills every cell in the m x n table

Space Complexity: O(m * n) -> For the 2D dp table

Difference from Substring: LCS doesn't need to be contiguous in the original string.
============================
*/
