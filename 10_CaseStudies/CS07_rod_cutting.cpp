// ============================================================
// CASE STUDY 07: Rod Cutting Problem
// ============================================================
//
// PROBLEM STATEMENT:
//   You have a rod of length N. You can cut it into pieces.
//   Each piece of length i has a selling PRICE price[i].
//   Find the maximum revenue you can earn by cutting and selling the rod.
//   You can make any number of cuts (or no cuts at all).
//
// REAL-LIFE INTERPRETATION:
//   - Steel manufacturer: How to cut steel bars for maximum profit.
//   - Paper cutting: Cut rolls of paper into lengths with best market value.
//   - Rope cutting: Cut rope into pieces of highest combined value.
//
// ============================================================
// PATTERN RECOGNITION: WHY DYNAMIC PROGRAMMING?
// ============================================================
//
//  BRUTE FORCE: Try all 2^(n-1) ways to cut the rod -> Exponential.
//
//  KEY OBSERVATION:
//    When we cut the rod at position 'k', two subproblems arise:
//      1. A piece of length k (known price)
//      2. A remaining rod of length (n-k) -> SAME PROBLEM with smaller n!
//
//  OVERLAPPING SUBPROBLEMS:
//    maxRevenue(n) = max over k=1 to n of: price[k] + maxRevenue(n-k)
//    Many smaller lengths get recomputed repeatedly.
//
//  DP FIX: Store maxRevenue for every length from 1 to n.
//
//  THIS IS THE UNBOUNDED KNAPSACK PATTERN:
//    - Item length = weight, Price = value
//    - Can use same cut MULTIPLE TIMES (unbounded)
//    - Bag capacity = rod length n
//
// CATEGORY: DYNAMIC PROGRAMMING (Unbounded Knapsack variant)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  dp[length] = max revenue from a rod of 'length'
//
//  Step 1: dp[0] = 0 (empty rod has no revenue)
//  Step 2: For each rod length from 1 to n:
//             For each cut position k from 1 to current length:
//               dp[length] = max(dp[length], price[k] + dp[length - k])
//  Step 3: Answer is dp[n]
//
// Example:
//   Length:  1  2  3  4  5  6  7  8
//   Price:   1  5  8  9  10 17 17 20
//   Rod = 4 -> Best: cut into 2+2 = 5+5 = 10 (better than selling as 4 = 9)
//
// ============================================================

#include <iostream>
using namespace std;

// Function to solve Rod Cutting using DP
void rodCutting(int price[], int n) {
    // dp[length] = maximum revenue obtainable from a rod of given length
    int dp[n + 1];

    // Base case: rod of length 0 has zero revenue
    dp[0] = 0;

    // Fill DP table for rod lengths 1 to n
    for (int rodLength = 1; rodLength <= n; rodLength++) {

        dp[rodLength] = -1;  // Start with impossible value

        // Try every possible FIRST CUT at position cutPos (1 to rodLength)
        for (int cutPos = 1; cutPos <= rodLength; cutPos++) {
            // Revenue from this cut = price of the piece (cutPos) +
            //                         max revenue from remaining rod (rodLength - cutPos)
            int revenue = price[cutPos - 1] + dp[rodLength - cutPos];

            // Update dp[rodLength] if this cutting gives more revenue
            if (revenue > dp[rodLength]) {
                dp[rodLength] = revenue;
            }
        }
    }

    // Display results
    cout << "\nDP Table (Max revenue for each rod length):" << endl;
    cout << "----------------------------------------------" << endl;
    for (int len = 1; len <= n; len++) {
        cout << "Rod length " << len << " -> Max Revenue: " << dp[len] << endl;
    }

    cout << "\nMaximum revenue for rod of length " << n << ": " << dp[n] << endl;

    // Trace back what cuts were made
    cout << "\nCuts made to achieve maximum revenue:" << endl;
    int remaining = n;
    while (remaining > 0) {
        for (int cut = 1; cut <= remaining; cut++) {
            if (dp[remaining] == price[cut - 1] + dp[remaining - cut]) {
                cout << "  Cut piece of length " << cut
                     << " (Price: " << price[cut - 1] << ")" << endl;
                remaining -= cut;
                break;
            }
        }
    }
}

int main() {
    int n;

    cout << "======================================================" << endl;
    cout << " CASE STUDY 07: Rod Cutting Problem (Dynamic Programming)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter the length of the rod: ";
    cin >> n;

    int price[n];

    cout << "\nEnter selling price for each length (length 1 to " << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Price for length " << i + 1 << ": ";
        cin >> price[i];
    }

    rodCutting(price, n);

    return 0;
}

/*
============================
Time Complexity:
  O(n^2) -> Two nested loops (outer: rod length, inner: cut positions)

Space Complexity: O(n) -> For the 1D DP table

SIMILAR PROBLEMS (Same Unbounded Item Selection Pattern):
  1. Coin Change (min coins)               -> Same idea, minimize coins
  2. Integer Break (max product)           -> Break n into parts, max product
  3. Unbounded Knapsack                    -> Each item available unlimited times
  4. Perfect Squares                       -> Min perfect squares to sum to n

KEY DIFFERENCE from 0/1 Knapsack:
  0/1 Knapsack:    Each item used AT MOST ONCE
  Rod Cutting:     Each piece length can be used MULTIPLE TIMES (Unbounded)
============================
*/
