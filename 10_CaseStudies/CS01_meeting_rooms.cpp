// ============================================================
// CASE STUDY 01: Meeting Room Scheduling
// ============================================================
//
// PROBLEM STATEMENT:
//   You have ONE meeting room and N meeting requests.
//   Each meeting has a start time and end time.
//   Schedule the MAXIMUM NUMBER of meetings possible
//   such that no two meetings overlap.
//
// REAL-LIFE INTERPRETATION:
//   - A conference hall manager maximizing room bookings.
//   - A doctor scheduling the most appointments in a day.
//   - A CPU scheduling the most tasks in a time slot.
//
// ============================================================
// PATTERN RECOGNITION: WHY GREEDY?
// ============================================================
//
//  ASK YOURSELF: "Can I make a local choice repeatedly
//                 that leads to a global optimum?"
//
//  YES! If I always pick the meeting that ENDS EARLIEST,
//  I free up the room as soon as possible, leaving maximum
//  time for future meetings.
//
//  Greedy Rule: Sort by FINISH TIME. Pick the meeting that
//               ends earliest and doesn't overlap with the
//               last selected meeting.
//
//  WHY NOT DP? - There are no overlapping subproblems.
//               Each decision is independent of future states.
//  WHY NOT BACKTRACKING? - We don't need to explore all subsets;
//                          greedy makes ONE optimal choice each time.
//
// CATEGORY: GREEDY ALGORITHM
//
// PATTERN: "Select maximum non-overlapping intervals"
//           -> ALWAYS sort by finish time -> classic Activity Selection
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//  Step 1: Sort all meetings by their END TIME (ascending).
//          Meetings that finish early give us more free time.
//
//  Step 2: Always select the FIRST meeting (earliest finish).
//
//  Step 3: For each subsequent meeting:
//          - If its START TIME >= last selected meeting's END TIME
//            -> Select it (no overlap)
//          - Otherwise skip it
//
//  Step 4: Count and display all selected meetings.
//
// ============================================================
// Example:
//   Meetings: (1,4), (3,5), (0,6), (5,7), (8,9), (5,9)
//   After sorting by end: (1,4), (3,5), (0,6), (5,7), (5,9), (8,9)
//   Selected: (1,4) -> (5,7) -> (8,9) = 3 meetings
// ============================================================

#include <iostream>
using namespace std;

// Structure to hold a meeting's start and end time
struct Meeting {
    int startTime;
    int endTime;
    int meetingId;  // Original meeting number (for display)
};

// Sort meetings by their end time in ascending order (Bubble Sort)
void sortByEndTime(Meeting meetings[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (meetings[j].endTime > meetings[j + 1].endTime) {
                Meeting temp      = meetings[j];
                meetings[j]       = meetings[j + 1];
                meetings[j + 1]   = temp;
            }
        }
    }
}

// Greedy function to select maximum non-overlapping meetings
void scheduleMeetings(Meeting meetings[], int n) {
    // Step 1: Sort by end time -> meetings finishing earliest come first
    sortByEndTime(meetings, n);

    cout << "\nMeetings sorted by End Time:" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Meeting " << meetings[i].meetingId
             << " -> Start: " << meetings[i].startTime
             << ", End: " << meetings[i].endTime << endl;
    }

    cout << "\nSelected Meetings (Greedy - Earliest Finish First):" << endl;
    cout << "---------------------------------------------------" << endl;

    // Step 2: Always pick the first meeting (earliest end time)
    int lastEndTime = meetings[0].endTime;
    cout << "Meeting " << meetings[0].meetingId
         << " -> (" << meetings[0].startTime << " to " << meetings[0].endTime << ")" << endl;
    int count = 1;

    // Step 3: For each remaining meeting, check if it can be selected
    for (int i = 1; i < n; i++) {
        // GREEDY CHECK: Does this meeting start AFTER the last selected meeting ends?
        if (meetings[i].startTime >= lastEndTime) {
            // No overlap! Select this meeting.
            cout << "Meeting " << meetings[i].meetingId
                 << " -> (" << meetings[i].startTime << " to " << meetings[i].endTime << ")" << endl;
            lastEndTime = meetings[i].endTime;  // Update the end time of last selected
            count++;
        }
    }

    cout << "\nMaximum meetings that can be scheduled: " << count << endl;
}

int main() {
    int n;

    cout << "====================================================" << endl;
    cout << "  CASE STUDY 01: Meeting Room Scheduling (Greedy)" << endl;
    cout << "====================================================" << endl;
    cout << "\nEnter the number of meeting requests: ";
    cin >> n;

    Meeting meetings[n];

    cout << "\nEnter start and end time for each meeting:" << endl;
    for (int i = 0; i < n; i++) {
        meetings[i].meetingId = i + 1;
        cout << "Meeting " << i + 1 << " -> Start time: ";
        cin >> meetings[i].startTime;
        cout << "Meeting " << i + 1 << " -> End time:   ";
        cin >> meetings[i].endTime;
    }

    scheduleMeetings(meetings, n);

    return 0;
}

/*
============================
Time Complexity:
  Sorting:   O(n^2) using Bubble Sort
  Selection: O(n)
  Total:     O(n^2) [O(n log n) with efficient sort like merge sort]

Space Complexity: O(1)

SIMILAR PROBLEMS (Same Pattern - Sort by finish time, pick greedily):
  1. Activity Selection Problem      -> exactly the same problem!
  2. Job Scheduling with Deadlines   -> sort by deadline, assign time slots
  3. Maximum Events You Can Attend   -> sort by end day, pick earliest ending event
  4. Minimum Number of Meeting Rooms -> DIFFERENT (sort by start, use min-heap)
============================
*/
