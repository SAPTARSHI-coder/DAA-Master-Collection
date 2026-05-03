// ============================================================
// CASE STUDY 08: Egg Drop Problem
// ============================================================
//
// PROBLEM STATEMENT:
//   You have E eggs and a building with F floors.
//   An egg breaks if dropped from a floor > critical floor.
//   An egg does NOT break if dropped from floor <= critical floor.
//   Find the MINIMUM NUMBER OF TRIALS needed in the WORST CASE
//   to determine the critical floor, regardless of its value.
//
// REAL-LIFE INTERPRETATION:
//   - Quality testing: Find the minimum drop height that breaks a product.
//   - Safety engineering: Find the maximum safe operating voltage.
//   - Drug testing: Find the minimum harmful dosage with limited test samples.
//
// ============================================================
// PATTERN RECOGNITION: WHY DYNAMIC PROGRAMMING?
// ============================================================
//
//  NAIVE APPROACH: Linear scan - drop from floor 1, 2, 3...
//    With 1 egg: must try every floor (worst case F trials).
//    With infinite eggs: Binary search -> O(log F) trials.
//    With E eggs and F floors: BETWEEN these two extremes.
//
//  WHY DP?
//    When we drop from floor 'k':
//      - Egg BREAKS    -> Look below, we now have (E-1) eggs, (k-1) floors
//      - Egg SURVIVES  -> Look above, we still have E eggs, (F-k) floors
//    We want to MINIMIZE the MAXIMUM of these two scenarios (worst case).
//
//    dp[eggs][floors] = min trials needed with 'eggs' eggs and 'floors' floors
//    dp[e][f] = 1 + min over k=1 to f of: max(dp[e-1][k-1], dp[e][f-k])
//
//  OVERLAPPING SUBPROBLEMS: Same (eggs, floors) combination calculated many times.
//
// CATEGORY: DYNAMIC PROGRAMMING (Optimization on nested choices)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Base Cases:
//    dp[e][0] = 0 -> 0 floors, 0 trials needed
//    dp[e][1] = 1 -> 1 floor, 1 trial needed
//    dp[1][f] = f -> 1 egg, must try all f floors linearly
//
//  For dp[e][f]: try each floor k (1 to f) as the test floor.
//    - Breaking:  dp[e-1][k-1]  (fewer eggs, floors below k)
//    - Surviving: dp[e][f-k]    (same eggs, floors above k)
//    - Worst case for floor k:  max of these two
//    - Best trial floor:        minimize over all k
//
// Example: 2 eggs, 10 floors -> Answer = 4 trials
//
// ============================================================

#include <iostream>
using namespace std;

#define MAX 20
#define INF 99999

int dp[MAX][MAX];  // dp[eggs][floors]

// Function to solve Egg Drop Problem
int eggDrop(int eggs, int floors) {
    // Base case 1: 0 floors -> 0 trials, 1 floor -> 1 trial
    for (int e = 1; e <= eggs; e++) {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    // Base case 2: 1 egg -> must check every floor linearly
    for (int f = 1; f <= floors; f++) {
        dp[1][f] = f;
    }

    // Fill DP table for more eggs and more floors
    for (int e = 2; e <= eggs; e++) {
        for (int f = 2; f <= floors; f++) {

            dp[e][f] = INF;  // Start with worst case = infinity

            // Try dropping from each floor k (1 to f)
            for (int k = 1; k <= f; k++) {
                // Egg BREAKS from floor k -> check below (e-1 eggs, k-1 floors)
                int ifBreaks = dp[e - 1][k - 1];

                // Egg SURVIVES from floor k -> check above (e eggs, f-k floors)
                int ifSurvives = dp[e][f - k];

                // Worst case for this choice of floor k
                int worstCase = 1 + max(ifBreaks, ifSurvives);  // +1 for this trial

                // We want to MINIMIZE the worst case
                if (worstCase < dp[e][f]) {
                    dp[e][f] = worstCase;
                }
            }
        }
    }

    return dp[eggs][floors];
}

int main() {
    int eggs, floors;

    cout << "======================================================" << endl;
    cout << " CASE STUDY 08: Egg Drop Problem (Dynamic Programming)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter the number of eggs: ";
    cin >> eggs;
    cout << "Enter the number of floors: ";
    cin >> floors;

    int result = eggDrop(eggs, floors);

    cout << "\nMinimum trials needed (worst case) with " << eggs
         << " egg(s) and " << floors << " floor(s): " << result << endl;

    // Display partial DP table
    cout << "\nDP Table (rows = eggs, cols = floors):" << endl;
    cout << "  Eggs\\Floors  ";
    for (int f = 0; f <= min(floors, 10); f++) cout << f << "\t";
    cout << endl;

    for (int e = 1; e <= eggs; e++) {
        cout << "  " << e << " egg(s)    ";
        for (int f = 0; f <= min(floors, 10); f++) {
            cout << dp[e][f] << "\t";
        }
        cout << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(E * F^2) -> For each (eggs, floors) state, try all F floors
  E = number of eggs, F = number of floors

Space Complexity: O(E * F) -> For the 2D DP table

OPTIMIZATION: Can be improved to O(E * F * log F) using binary search
              on the optimal drop floor instead of linear scan.

SIMILAR PROBLEMS (Same min-max DP Pattern):
  1. Minimum Cost to Paint Houses        -> Min cost with constraint on adjacent colors
  2. Burst Balloons                      -> Choose burst order to maximize coins
  3. Stone Merge                         -> Min cost to merge stones

KEY TERM FOR VIVA: "Minimax DP" - We MINIMIZE the MAXIMUM (worst case)
============================
*/
