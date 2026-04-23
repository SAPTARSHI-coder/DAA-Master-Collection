// Program: Longest Palindromic Subsequence (DP)
// What it does: Given a string, find the length of the LONGEST subsequence
//               that is a PALINDROME (reads same forwards and backwards).
//               A subsequence can skip characters (non-contiguous).
// Key Trick:    LPS of string S = LCS(S, reverse(S))
//
// Example Input: "bbabcbcab"
// Expected Output: LPS length = 7 ("babcbab")

#include <iostream>
#include <string>
using namespace std;

void longestPalindromicSubsequence(string s) {
    int n = s.length();

    // TRICK: LPS(s) = LCS(s, reverse(s))
    string rev = s;
    for (int i = 0; i < n / 2; i++) swap(rev[i], rev[n - 1 - i]);  // Reverse

    // Now find LCS of s and rev (same DP as LCS problem)
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == rev[j - 1]) {
                // Characters match -> extend LCS by 1
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // Characters don't match -> take max of excluding one character
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << "\nOriginal string:  \"" << s   << "\"" << endl;
    cout << "Reversed string:  \"" << rev << "\"" << endl;
    cout << "\nLength of Longest Palindromic Subsequence: " << dp[n][n] << endl;

    // Trace back the actual palindrome
    string lps = "";
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (s[i - 1] == rev[j - 1]) {
            lps = s[i - 1] + lps;
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << "One Longest Palindromic Subsequence: \"" << lps << "\"" << endl;
}

int main() {
    string s;
    cout << "=== Longest Palindromic Subsequence (DP) ===" << endl;
    cout << "Enter the string: ";
    cin >> s;
    longestPalindromicSubsequence(s);
    return 0;
}

/*
============================
Time Complexity:
  O(n^2) -> Fill n x n DP table

Space Complexity: O(n^2) -> For the DP table

KEY TRICK: LPS(s) = LCS(s, reverse(s))
           This reuses the LCS algorithm you already know!

DIFFERENCE:
  LCS      -> Longest common subsequence of two DIFFERENT strings
  LPS      -> Longest palindromic subsequence of ONE string
  LCS (contiguous) -> Longest common SUBSTRING (contiguous chars)
============================
*/
