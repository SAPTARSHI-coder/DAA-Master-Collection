// Program: Activity Selection Problem (Greedy)
// What it does: Given a set of activities with start and finish times,
//               select the MAXIMUM number of activities that can be
//               performed by a single person (no overlapping activities).
// Greedy Choice: Always pick the activity that finishes EARLIEST
//                (greedy strategy: finish early, do more).
// Example Input:
//   Activities: A1  A2  A3  A4  A5
//   Start:       1   3   0   5   8
//   Finish:      2   4   6   7   9
// Expected Output: A1, A2, A4, A5 (4 activities)

#include <iostream>
using namespace std;

// Structure to represent an activity
struct Activity {
    int start;   // Start time of activity
    int finish;  // Finish time of activity
    int index;   // Original activity number (for display)
};

// Function to sort activities by their finish time (Bubble Sort)
void sortByFinishTime(Activity activities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (activities[j].finish > activities[j + 1].finish) {
                Activity temp    = activities[j];
                activities[j]    = activities[j + 1];
                activities[j + 1] = temp;
            }
        }
    }
}

// Function to select maximum activities using Greedy approach
void activitySelection(Activity activities[], int n) {
    // Step 1: Sort activities by finish time
    sortByFinishTime(activities, n);

    cout << "\nActivities selected (Greedy - Earliest Finish First):" << endl;
    cout << "------------------------------------------------------" << endl;

    // Step 2: The first activity (earliest finish time) is always selected
    int lastSelectedFinish = activities[0].finish;
    cout << "Activity " << activities[0].index
         << " -> Start: " << activities[0].start
         << ", Finish: " << activities[0].finish << endl;

    int count = 1;  // Number of activities selected

    // Step 3: For each subsequent activity, check if it can be added
    for (int i = 1; i < n; i++) {
        // Greedy Check: Current activity's start time must be >= last selected finish time
        // This ensures no overlap between activities
        if (activities[i].start >= lastSelectedFinish) {
            cout << "Activity " << activities[i].index
                 << " -> Start: " << activities[i].start
                 << ", Finish: " << activities[i].finish << endl;

            lastSelectedFinish = activities[i].finish;  // Update last selected
            count++;
        }
    }

    cout << "\nTotal activities selected: " << count << endl;
}

int main() {
    int n;

    cout << "=== Activity Selection Problem (Greedy) ===" << endl;
    cout << "Enter the number of activities: ";
    cin >> n;

    Activity activities[n];

    cout << "\nEnter start and finish time for each activity:" << endl;
    for (int i = 0; i < n; i++) {
        activities[i].index = i + 1;
        cout << "Activity " << i + 1 << " -> Start: ";
        cin >> activities[i].start;
        cout << "Activity " << i + 1 << " -> Finish: ";
        cin >> activities[i].finish;
    }

    // Perform activity selection
    activitySelection(activities, n);

    return 0;
}

/*
============================
Time Complexity:
  Sorting:    O(n^2) using Bubble Sort (can be O(n log n) with better sort)
  Selection:  O(n)
  Overall:    O(n^2)

Space Complexity: O(1) -> No extra memory apart from input

Greedy Strategy: Sort by finish time, always pick activity that finishes earliest.
============================
*/
