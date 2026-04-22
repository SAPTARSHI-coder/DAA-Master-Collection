// Program: Edit Distance (Levenshtein Distance) - Dynamic Programming
// What it does: Finds the MINIMUM NUMBER OF OPERATIONS required to convert
//               one string into another.
//               Three allowed operations: INSERT, DELETE, REPLACE a character.
// Use Case: Spell checkers, DNA sequence analysis, diff tools.
//
// Example Input:
//   String 1: "sunday"
//   String 2: "saturday"
// Expected Output: Edit Distance = 3

#include <iostream>
#include <string>
using namespace std;

// Function to find minimum of three integers
int minOf3(int a, int b, int c) {
    return min(a, min(b, c));
}

// Function to compute Edit Distance using DP
void editDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // dp[i][j] = Minimum operations to convert str1[0..i-1] to str2[0..j-1]
    int dp[m + 1][n + 1];

    // Base cases:
    // Converting empty string to str2[0..j-1] requires j insertions
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    // Converting str1[0..i-1] to empty string requires i deletions
    for (int i = 0; i <= m; i++) dp[i][0] = i;

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            // If characters match, no operation needed - take diagonal
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                // Take minimum of three operations:
                // 1. INSERT: dp[i][j-1] + 1  -> Insert a char to match str2[j-1]
                // 2. DELETE: dp[i-1][j] + 1  -> Delete str1[i-1]
                // 3. REPLACE: dp[i-1][j-1] + 1 -> Replace str1[i-1] with str2[j-1]
                dp[i][j] = 1 + minOf3(dp[i][j - 1],     // INSERT
                                       dp[i - 1][j],     // DELETE
                                       dp[i - 1][j - 1]); // REPLACE
            }
        }
    }

    cout << "\nMinimum Edit Distance: " << dp[m][n] << " operations" << endl;
    cout << "\nOperations needed to convert \"" << str1 << "\" to \"" << str2 << "\":" << endl;

    // Trace back to find the operations
    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]) {
            i--; j--;  // Characters match, no operation
        } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            cout << "  INSERT '" << str2[j - 1] << "' at position " << j << endl;
            j--;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            cout << "  DELETE '" << str1[i - 1] << "' at position " << i << endl;
            i--;
        } else {
            cout << "  REPLACE '" << str1[i - 1] << "' with '" << str2[j - 1] << "'" << endl;
            i--; j--;
        }
    }
}

int main() {
    string str1, str2;

    cout << "=== Edit Distance (Levenshtein Distance) - DP ===" << endl;
    cout << "Enter first string:  ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // Compute and display Edit Distance
    editDistance(str1, str2);

    return 0;
}

/*
============================
Time Complexity:
  O(m * n) -> m and n are lengths of the two strings

Space Complexity: O(m * n) -> For the 2D dp table

Three Operations:
  1. Insert  -> Add a character
  2. Delete  -> Remove a character
  3. Replace -> Change one character to another
============================
*/
