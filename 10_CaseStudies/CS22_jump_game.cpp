// ============================================================
// CASE STUDY 22: Jump Game (Can You Reach the End?)
// ============================================================
//
// PROBLEM STATEMENT:
//   Given an array where each element represents the MAXIMUM number
//   of steps you can jump forward from that position, determine if
//   you can reach the LAST INDEX starting from index 0.
//
// REAL-LIFE: Frog on lily pads, level-skipping in a game, network hop routing.
//
// ============================================================
// PATTERN RECOGNITION: WHY GREEDY?
// ============================================================
//
//  GREEDY INSIGHT: Track the MAXIMUM INDEX REACHABLE at any point.
//    For each position i (if i <= maxReach):
//      maxReach = max(maxReach, i + arr[i])
//    If maxReach >= n-1 at any point -> YES
//    If i > maxReach at any point -> STUCK, return NO
//
//  WHY GREEDY WORKS: At each step, the best possible future reach
//  is fully captured by maxReach. No benefit to reconsidering.
//
// ============================================================

#include <iostream>
using namespace std;

bool canJump(int arr[], int n) {
    int maxReach = 0;  // Maximum index reachable from indices seen so far

    for (int i = 0; i < n; i++) {
        // If current index is beyond reach -> stuck here, can't proceed
        if (i > maxReach) {
            return false;
        }

        // Update the farthest index we can reach from position i
        if (i + arr[i] > maxReach) {
            maxReach = i + arr[i];
        }

        cout << "  Position " << i << " (jump up to " << arr[i]
             << ") -> Max Reach: " << maxReach << endl;

        // If we can already reach the last index, done!
        if (maxReach >= n - 1) return true;
    }

    return maxReach >= n - 1;
}

int main() {
    int n;
    cout << "=== CASE STUDY 22: Jump Game (Greedy) ===" << endl;
    cout << "Enter number of positions: ";
    cin >> n;

    int arr[n];
    cout << "Enter max jump from each position: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "\nGreedy Trace:" << endl;
    bool result = canJump(arr, n);
    cout << "\nResult: " << (result ? "YES, can reach the end!" : "NO, cannot reach the end.") << endl;

    return 0;
}

/*
============================
Time:  O(n) -> Single pass through array
Space: O(1) -> Only maxReach variable

SIMILAR: Jump Game II (min jumps to reach end) -> Greedy with jump count
         Reach a Number -> BFS/Math
============================
*/
