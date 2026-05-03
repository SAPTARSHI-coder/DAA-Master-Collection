// ============================================================
// CASE STUDY 05: Climbing Stairs
// ============================================================
//
// PROBLEM STATEMENT:
//   You are climbing a staircase with N steps.
//   Each time you can either climb 1 step or 2 steps.
//   Find the TOTAL NUMBER OF DISTINCT WAYS to reach the top.
//
// REAL-LIFE INTERPRETATION:
//   - Person climbing stairs choosing 1 or 2 steps at a time.
//   - Frog jumping from stone to stone (1 or 2 leaps).
//   - Robot paths on a 1D track moving forward 1 or 2 units.
//   - Counting ways to tile a floor with 1x1 and 1x2 tiles.
//
// ============================================================
// PATTERN RECOGNITION: WHY DYNAMIC PROGRAMMING?
// ============================================================
//
//  FIRST, TRY RECURSION:
//    ways(n) = ways(n-1) + ways(n-2)
//    (You reach step n from step n-1 (take 1 step) OR
//     from step n-2 (take 2 steps))
//
//  PROBLEM WITH PURE RECURSION: OVERLAPPING SUBPROBLEMS!
//    ways(5) calls ways(4) and ways(3)
//    ways(4) ALSO calls ways(3) <-- CALCULATED AGAIN!
//    ways(3) is calculated MULTIPLE times -> Exponential time O(2^n)
//
//  DP FIX: Store results of already-computed subproblems.
//           ways(3) is calculated ONCE, stored, reused.
//
//  SPOTTING THE PATTERN:
//    - Answer = sum of overlapping subproblem answers
//    - Optimal substructure: ways(n) depends on ways(n-1) and ways(n-2)
//    - This is literally the FIBONACCI sequence!
//
// CATEGORY: DYNAMIC PROGRAMMING (Tabulation / Bottom-Up)
//           Also solvable by memoization (Top-Down)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Observation:
//    ways(1) = 1  {1}
//    ways(2) = 2  {1+1, 2}
//    ways(3) = 3  {1+1+1, 1+2, 2+1}
//    ways(4) = 5  {1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2}
//    ways(5) = 8  ...
//
//  Pattern: ways(n) = ways(n-1) + ways(n-2)
//  Base cases: ways(1) = 1, ways(2) = 2
//
//  Build table from 1 to n (bottom-up):
//    Step -> Ways:  1->1, 2->2, 3->3, 4->5, 5->8, ...
//
// ============================================================

#include <iostream>
using namespace std;

// Function to count ways to climb N stairs (Tabulation / Bottom-Up DP)
long long climbingStairs(int n) {
    if (n == 1) return 1;  // Base case: only 1 way for 1 step
    if (n == 2) return 2;  // Base case: 2 ways for 2 steps

    // Create DP table where dp[i] = number of ways to reach step i
    long long dp[n + 1];

    dp[1] = 1;  // 1 way to reach step 1: {1}
    dp[2] = 2;  // 2 ways to reach step 2: {1+1} or {2}

    // Fill the table from step 3 onwards
    for (int step = 3; step <= n; step++) {
        // To reach 'step', you can come from:
        //   step-1 (by taking 1 step) OR
        //   step-2 (by taking 2 steps)
        dp[step] = dp[step - 1] + dp[step - 2];
    }

    return dp[n];
}

// Function to also display all ways (backtracking version for small n)
void displayAllWays(int current, int target, int path[], int pathLength) {
    if (current == target) {
        // Reached the top! Print this path
        cout << "  { ";
        for (int i = 0; i < pathLength; i++) cout << path[i] << " ";
        cout << "}" << endl;
        return;
    }

    if (current > target) return;  // Overshot, stop

    // Try taking 1 step
    path[pathLength] = 1;
    displayAllWays(current + 1, target, path, pathLength + 1);

    // Try taking 2 steps
    path[pathLength] = 2;
    displayAllWays(current + 2, target, path, pathLength + 1);
}

int main() {
    int n;

    cout << "======================================================" << endl;
    cout << " CASE STUDY 05: Climbing Stairs (Dynamic Programming)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter the number of stairs: ";
    cin >> n;

    cout << "\nTotal distinct ways to reach step " << n
         << ": " << climbingStairs(n) << endl;

    // For small values, also show all actual ways
    if (n <= 6) {
        cout << "\nAll possible ways:" << endl;
        int path[20];
        displayAllWays(0, n, path, 0);
    }

    // Display the DP table
    cout << "\nDP Table (ways to reach each step):" << endl;
    cout << "--------------------------------------" << endl;
    long long dp[n + 1];
    dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    for (int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    for (int i = 1; i <= n; i++) {
        cout << "Step " << i << " -> " << dp[i] << " ways" << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(n) -> Fill DP table once from 1 to n

Space Complexity: O(n) -> For the DP table
                  O(1) can be achieved by keeping only last 2 values

SIMILAR PROBLEMS (Same DP Pattern - State depends on previous 1 or 2 states):
  1. Fibonacci number                   -> Same recurrence!
  2. Frog Jump (with variable costs)    -> Add cost to reach each step
  3. Tile the Floor with 1x1 and 1x2   -> Exactly same count
  4. Decode Ways (LeetCode 91)          -> Same DP, different base cases

KEY INSIGHT FOR VIVA:
  "Whenever current state depends on a FIXED number of previous states,
   and we count ways or find min/max, think DP with that recurrence."
============================
*/
