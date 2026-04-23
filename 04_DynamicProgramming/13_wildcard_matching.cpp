// Program: Wildcard Pattern Matching (Dynamic Programming)
// What it does: Given a TEXT string and a PATTERN string (with wildcards),
//               determine if the pattern matches the text.
//               Wildcards: '?' matches any SINGLE character
//                          '*' matches any SEQUENCE of characters (including empty)
//
// Example Input: Text = "abcde", Pattern = "a?c*e"
// Expected Output: true (a=a, ?=b, c=c, *=d, e=e)

#include <iostream>
#include <string>
using namespace std;

// DP function to check if pattern matches text
bool wildcardMatch(string text, string pattern) {
    int m = text.length();
    int n = pattern.length();

    // dp[i][j] = true if pattern[0..j-1] matches text[0..i-1]
    bool dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = false;

    // Base case: empty pattern matches empty text
    dp[0][0] = true;

    // Base case: pattern of only '*'s can match empty text
    // dp[0][j] = true if pattern[0..j-1] has all '*'s
    for (int j = 1; j <= n; j++) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];  // '*' can match empty string
        }
    }

    // Fill the rest of the table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (pattern[j - 1] == '*') {
                // '*' can: (1) match zero characters -> dp[i][j-1]
                //          (2) match one more character -> dp[i-1][j]
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];

            } else if (pattern[j - 1] == '?' || pattern[j - 1] == text[i - 1]) {
                // '?' matches any single char, or exact char match
                dp[i][j] = dp[i - 1][j - 1];

            } else {
                dp[i][j] = false;  // Characters don't match
            }
        }
    }

    return dp[m][n];
}

int main() {
    string text, pattern;
    cout << "=== Wildcard Pattern Matching (DP) ===" << endl;
    cout << "  '?' matches any single character" << endl;
    cout << "  '*' matches any sequence of characters" << endl;
    cout << "\nEnter the text:    ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;

    bool result = wildcardMatch(text, pattern);
    cout << "\nPattern \"" << pattern << "\" ";
    if (result) cout << "MATCHES";
    else cout << "does NOT match";
    cout << " text \"" << text << "\"" << endl;

    return 0;
}

/*
============================
Time Complexity:  O(m * n) -> Fill m x n DP table
Space Complexity: O(m * n) -> For DP table

SIMILAR PROBLEMS:
  Regular Expression Matching -> '.' matches any char, '*' means zero or more
  String Matching (KMP, RK)   -> Exact match (no wildcards)
============================
*/
