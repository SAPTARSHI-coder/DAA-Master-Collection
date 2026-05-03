// ============================================================
// CASE STUDY 04: Gas Station / Circular Tour Problem
// ============================================================
//
// PROBLEM STATEMENT:
//   There are N petrol pumps arranged in a CIRCLE. Each pump:
//   - Provides a certain amount of petrol.
//   - Requires petrol to REACH THE NEXT pump.
//   Determine the STARTING PUMP from which a truck can complete
//   the full circular tour WITHOUT running out of fuel.
//   Return -1 if no such starting point exists.
//
// REAL-LIFE INTERPRETATION:
//   - Delivery truck completing a circular route.
//   - Drone recharging and flying through waypoints.
//   - Traveling salesman visiting all cities in a loop.
//
// ============================================================
// PATTERN RECOGNITION: WHY GREEDY (Single Pass)?
// ============================================================
//
//  NAIVE APPROACH  (Brute Force): Try each pump as starting point,
//                   simulate the full trip -> O(n^2). Too slow.
//
//  GREEDY INSIGHT:
//    1. If total petrol available >= total petrol required,
//       a solution ALWAYS EXISTS.
//    2. If at some point our tank goes NEGATIVE while starting from
//       pump 'i', then NO pump between i and current position
//       can be the starting point. Start fresh from the NEXT pump.
//
//  WHY DOES GREEDY WORK?
//    When cumulative deficit occurs at pump j (starting from i),
//    all pumps between i and j also fail as starting points
//    (because starting from them, we'd arrive at j with even less fuel).
//
// CATEGORY: GREEDY (Single Pass O(n) trick)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Calculate net gain at each pump = petrol[i] - cost[i]
//  Step 2: Track totalSurplus and currentTankLevel
//  Step 3: If currentTankLevel < 0 at pump j:
//            -> Set starting pump = j + 1
//            -> Reset currentTankLevel = 0
//  Step 4: If totalSurplus >= 0 at the end -> starting pump is valid
//          Else -> no solution exists (return -1)
//
// Example:
//   Petrol: 4 6 7 4 (what each pump provides)
//   Cost:   6 5 3 5 (cost to reach next pump)
//   Net:   -2 1 4 -1
//   Starting from pump 1 (index 1): 1+4-1=4 >=0 -> Valid!
//
// ============================================================

#include <iostream>
using namespace std;

// Function to find the starting petrol pump using Greedy
int findStartingPump(int petrol[], int cost[], int n) {
    int totalSurplus      = 0;  // Total net fuel (must be >= 0 for a solution)
    int currentTankLevel  = 0;  // Fuel in tank starting from 'startPump'
    int startPump         = 0;  // Candidate starting pump

    // Single pass through all pumps
    for (int i = 0; i < n; i++) {
        // Net fuel gain/loss at pump i
        int netFuel = petrol[i] - cost[i];

        totalSurplus     += netFuel;   // Keep track of global total
        currentTankLevel += netFuel;   // Update current trip total

        // If tankLevel goes negative, can't start from 'startPump' through i
        if (currentTankLevel < 0) {
            // GREEDY: None of the pumps from startPump to i can be the start
            // Try the NEXT pump as the new starting candidate
            startPump        = i + 1;
            currentTankLevel = 0;  // Reset tank (fresh start from next pump)
        }
    }

    // If total surplus is negative, no valid starting point exists
    if (totalSurplus < 0) {
        return -1;
    }

    return startPump;
}

int main() {
    int n;

    cout << "========================================================" << endl;
    cout << " CASE STUDY 04: Gas Station / Circular Tour (Greedy)" << endl;
    cout << "========================================================" << endl;
    cout << "\nEnter the number of petrol pumps: ";
    cin >> n;

    int petrol[n], cost[n];

    cout << "\nEnter petrol available at each pump (in order):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Pump " << i << " petrol: ";
        cin >> petrol[i];
    }

    cout << "\nEnter cost to reach the NEXT pump from each pump:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Pump " << i << " -> next cost: ";
        cin >> cost[i];
    }

    // Display net fuel at each pump
    cout << "\nNet fuel (petrol - cost) at each pump:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Pump " << i << ": " << petrol[i] - cost[i] << endl;
    }

    int result = findStartingPump(petrol, cost, n);

    if (result == -1) {
        cout << "\nNo valid starting pump exists. Tour impossible!" << endl;
    } else {
        cout << "\nStart the tour from Pump " << result << endl;
        cout << "(The truck can complete the full circular route from this pump)" << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(n) -> Single pass through all pumps

Space Complexity: O(1) -> No extra data structures

SIMILAR PROBLEMS (Same Single-Pass Greedy Pattern):
  1. Circular Array - Can we traverse? -> Same structure
  2. Jump Game II   -> Min jumps to reach end (track maximum reach)
  3. Ships / Routes -> Can a ship visit all ports and return?

KEY INSIGHT FOR VIVA:
  "When a single pass can detect if any prefix violates a condition
   and lets you skip ahead -> it's a Greedy Single-Pass pattern."
============================
*/
