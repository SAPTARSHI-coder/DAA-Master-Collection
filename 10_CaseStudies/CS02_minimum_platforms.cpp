// ============================================================
// CASE STUDY 02: Minimum Number of Train Platforms
// ============================================================
//
// PROBLEM STATEMENT:
//   A railway station is given train arrival and departure times.
//   Find the MINIMUM NUMBER OF PLATFORMS needed so that no train
//   has to wait (all trains can be accommodated simultaneously).
//
// REAL-LIFE INTERPRETATION:
//   - Train station capacity planning.
//   - Hospital: minimum number of operation theatres needed.
//   - Airport: minimum number of gates needed for flights.
//   - Computer: minimum number of CPU cores needed for parallel processes.
//
// ============================================================
// PATTERN RECOGNITION: WHY GREEDY?
// ============================================================
//
//  KEY INSIGHT: At any point in time, the number of platforms
//               needed = number of trains CURRENTLY at the station
//               (arrived but not yet departed).
//
//  APPROACH: Think of it as an "interval scheduling overlap" problem.
//            - Sort arrival and departure times SEPARATELY.
//            - Use TWO POINTERS to simulate time passing.
//            - When a train arrives    -> need one more platform (+1)
//            - When a train departs   -> free up one platform (-1)
//            - Track the MAXIMUM platforms needed at any point.
//
//  WHY NOT BRUTE FORCE? Brute force would be O(n^2) - check every
//                       train against every other. This approach is O(n log n).
//
// CATEGORY: GREEDY / SORTING + TWO POINTERS
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Sort arrival times in ascending order.
//  Step 2: Sort departure times in ascending order.
//  Step 3: Use two pointers: i for arrivals, j for departures
//  Step 4: If next event is an ARRIVAL (arr[i] <= dep[j]):
//             -> Need one more platform (platformsNeeded++)
//             -> Move arrival pointer forward
//          Else (next event is a DEPARTURE):
//             -> Free a platform (platformsNeeded--)
//             -> Move departure pointer forward
//  Step 5: Track MAXIMUM of platformsNeeded seen at any moment.
//
// Example:
//   Arrivals:   900 940 950 1100 1500 1800
//   Departures: 910 1200 1120 1130 1900 2000
//   Max Platforms = 3
//
// ============================================================

#include <iostream>
using namespace std;

// Simple sort function (Bubble Sort) for an array
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp  = arr[j];
                arr[j]    = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find minimum platforms needed
int minimumPlatforms(int arrival[], int departure[], int n) {
    // Step 1 & 2: Sort both arrival and departure arrays independently
    sortArray(arrival, n);
    sortArray(departure, n);

    int platformsNeeded = 0;   // Current number of platforms in use
    int maxPlatforms    = 0;   // Maximum platforms needed at any point

    int i = 0;  // Pointer for arrivals array
    int j = 0;  // Pointer for departures array

    // Step 3 & 4: Process events in chronological order
    while (i < n) {
        // If the next train arrives BEFORE or AT THE SAME TIME as any departure
        if (arrival[i] <= departure[j]) {
            platformsNeeded++;   // One more platform required for this arrival
            i++;                 // Move to next arrival
        } else {
            platformsNeeded--;   // A train departed, free up one platform
            j++;                 // Move to next departure
        }

        // Step 5: Keep track of the maximum platforms needed
        if (platformsNeeded > maxPlatforms) {
            maxPlatforms = platformsNeeded;
        }
    }

    return maxPlatforms;
}

int main() {
    int n;

    cout << "======================================================" << endl;
    cout << " CASE STUDY 02: Minimum Train Platforms (Greedy)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter the number of trains: ";
    cin >> n;

    int arrival[n], departure[n];

    cout << "\nEnter arrival time for each train (in HHMM format, e.g., 900 = 9:00 AM):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Train " << i + 1 << " arrival:   ";
        cin >> arrival[i];
    }

    cout << "\nEnter departure time for each train:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Train " << i + 1 << " departure: ";
        cin >> departure[i];
    }

    int result = minimumPlatforms(arrival, departure, n);

    cout << "\nMinimum platforms needed: " << result << endl;

    return 0;
}

/*
============================
Time Complexity:
  Sorting:    O(n^2) with Bubble Sort [O(n log n) with merge/quick sort]
  Two Pointer sweep: O(n)
  Total:      O(n^2) [O(n log n) with efficient sorting]

Space Complexity: O(1) -> No extra data structures used

SIMILAR PROBLEMS (Same Pattern):
  1. Meeting Rooms II  -> Same problem, just different context
  2. Maximum CPU Load  -> Max concurrent CPU tasks at any instant
  3. Minimum Number of Classrooms -> Overlap of class schedules
  4. Exam Room Assignment -> Students with overlapping exam slots

KEY DIFFERENCE from CS01:
  CS01 (Meeting Rooms): "How MANY meetings can fit?" -> Select non-overlapping
  CS02 (Platforms):     "How many ROOMS are needed?" -> Handle all, minimize rooms
============================
*/
