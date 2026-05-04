// ============================================================
// CASE STUDY 14: Aggressive Cows (Binary Search on Answer)
// ============================================================
//
// PROBLEM STATEMENT:
//   Farmer John has N stalls along a line and C cows.
//   Place C cows in stalls such that the MINIMUM DISTANCE
//   between any two cows is MAXIMIZED.
//   (The cows hate each other; make them as far apart as possible)
//
// REAL-LIFE INTERPRETATION:
//   - Placing WiFi routers to maximize coverage without interference.
//   - Locating warehouses to maximize minimum distance between them.
//   - Placing sensors to cover maximum area with minimum overlap.
//   - Social distancing: placing people to maximize minimum gap.
//
// ============================================================
// PATTERN RECOGNITION: WHY BINARY SEARCH ON ANSWER?
// ============================================================
//
//  BRUTE FORCE: Try every possible minimum distance -> O(n^2) at least.
//
//  KEY INSIGHT: "Binary Search on the Answer"
//    We don't directly find the answer. Instead:
//    - We ask: "CAN we place C cows with minimum distance >= D?"
//    - This question can be answered in O(n).
//    - The answer to this question is MONOTONE:
//        If D = 10 is possible, then D = 5 is also possible.
//        If D = 10 is NOT possible, then D = 11 is also not possible.
//    -> This monotone property means we can BINARY SEARCH on D!
//
//  HOW TO SPOT "Binary Search on Answer":
//    1. Problem asks for MINIMUM of MAXIMUM or MAXIMUM of MINIMUM.
//    2. You can CHECK if a given answer is feasible in O(n).
//    3. Feasibility is MONOTONE (helps once it helps for all easier cases).
//
// CATEGORY: BINARY SEARCH ON ANSWER + GREEDY VALIDATION
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Sort the stall positions.
//  Step 2: Binary search on minimum distance 'D':
//            low = 1 (minimum possible distance)
//            high = (max stall - min stall) / (cows - 1) [upper bound]
//  Step 3: For each candidate D:
//            Use Greedy to check if we CAN place C cows with min gap D.
//  Step 4: Greedy Check: Place first cow at first stall.
//            For each next stall, if distance from last cow >= D, place a cow.
//            If we placed all C cows, D is feasible.
//  Step 5: If feasible: try even larger D (search right half).
//          If not feasible: D is too large (search left half).
//
// Example:
//   Stalls: 1 2 8 4 9   (sorted: 1 2 4 8 9)
//   Cows: 3
//   Maximum minimum distance = 3 (place at 1, 4, 9)
//
// ============================================================

#include <iostream>
using namespace std;

// Function to sort stall positions (Bubble Sort)
void sortStalls(int stalls[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (stalls[j] > stalls[j + 1]) {
                int temp       = stalls[j];
                stalls[j]      = stalls[j + 1];
                stalls[j + 1]  = temp;
            }
        }
    }
}

// Greedy Check: Can we place 'cows' cows with minimum distance >= minDist?
bool canPlaceCows(int stalls[], int n, int cows, int minDist) {
    int cowsPlaced    = 1;               // Place first cow at the first stall
    int lastPlacedPos = stalls[0];       // Position of last placed cow

    // Try placing remaining cows
    for (int i = 1; i < n; i++) {
        // If current stall is at least 'minDist' away from last placed cow
        if (stalls[i] - lastPlacedPos >= minDist) {
            cowsPlaced++;               // Place a cow here
            lastPlacedPos = stalls[i]; // Update last placed position
        }

        // If all cows are placed successfully
        if (cowsPlaced == cows) return true;
    }

    return false;  // Couldn't place all cows with this minimum distance
}

// Binary Search on the minimum distance
int aggressiveCows(int stalls[], int n, int cows) {
    sortStalls(stalls, n);

    int low  = 1;                          // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int result = 0;

    cout << "\nSorted stalls: ";
    for (int i = 0; i < n; i++) cout << stalls[i] << " ";
    cout << endl;

    cout << "\nBinary Search trace (low = " << low << ", high = " << high << "):" << endl;

    // Binary search on the answer
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Try this as minimum distance

        if (canPlaceCows(stalls, n, cows, mid)) {
            // mid is feasible! Record it and try to find a LARGER minimum distance
            result = mid;
            cout << "  minDist = " << mid << " -> FEASIBLE (search larger)" << endl;
            low = mid + 1;
        } else {
            // mid is too large; try a SMALLER minimum distance
            cout << "  minDist = " << mid << " -> NOT feasible (search smaller)" << endl;
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, cows;

    cout << "========================================================" << endl;
    cout << " CASE STUDY 14: Aggressive Cows (Binary Search on Answer)" << endl;
    cout << "========================================================" << endl;
    cout << "\nEnter the number of stalls: ";
    cin >> n;

    int stalls[n];

    cout << "Enter the stall positions: ";
    for (int i = 0; i < n; i++) cin >> stalls[i];

    cout << "Enter the number of cows: ";
    cin >> cows;

    int maxMinDistance = aggressiveCows(stalls, n, cows);

    cout << "\nMaximum possible MINIMUM distance between any two cows: "
         << maxMinDistance << endl;

    return 0;
}

/*
============================
Time Complexity:
  Sorting: O(n^2) with Bubble Sort
  Binary Search: O(log(max_stall - min_stall))
  Each feasibility check: O(n)
  Total: O(n * log(max-min))

Space Complexity: O(1)

SIMILAR PROBLEMS (Same "Binary Search on Answer" Pattern):
  1. Painter's Partition        -> Min time to paint boards (already in main folder)
  2. Book Allocation            -> Allocate books to minimize max pages
  3. Minimize Max Distance to Gas Station -> Place stations, minimize max gap
  4. Koko Eating Bananas        -> Min eating speed to finish in H hours
  5. Split Array Largest Sum    -> Minimize the largest sum of any group

RECOGNITION PATTERN:
  Problem asks: "Find MAXIMUM/MINIMUM of a VALUE"
  AND: "Subject to some FEASIBILITY CONDITION"
  AND: "Feasibility is MONOTONE"
  = BINARY SEARCH ON THE ANSWER!
============================
*/
