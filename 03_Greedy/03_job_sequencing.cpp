// Program: Job Sequencing Problem (Greedy)
// What it does: Given jobs with deadlines and profits, schedule jobs to
//               maximize total PROFIT. Each job takes 1 unit of time.
//               A job can only be done before its deadline.
// Greedy Choice: Sort jobs by profit (highest first), then assign each
//                job to the latest available time slot before its deadline.
//
// Example Input:
//   Jobs:  J1  J2  J3  J4  J5
//   Profit: 20  15  10   5   1
//   Deadline: 2   2   1   3   3
// Expected Output: J1, J2, J4 -> Total Profit = 40

#include <iostream>
using namespace std;

// Structure to represent a Job
struct Job {
    int id;       // Job number
    int deadline; // Deadline (must be completed within this time)
    int profit;   // Profit earned if completed on time
};

// Function to sort jobs by profit in decreasing order (Bubble Sort)
void sortByProfit(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp    = jobs[j];
                jobs[j]     = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

// Function to schedule jobs and maximize profit
void jobSequencing(Job jobs[], int n) {
    // Step 1: Sort jobs by profit (highest first)
    sortByProfit(jobs, n);

    // Find the maximum deadline to determine the number of time slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Create a time slot array, -1 means the slot is free
    // timeSlot[i] stores the job ID assigned to time slot i+1
    int timeSlot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        timeSlot[i] = -1;  // Initialize all slots as empty
    }

    int totalProfit = 0;
    int jobCount    = 0;

    // Step 2: For each job (sorted by profit), find the latest free slot
    for (int i = 0; i < n; i++) {
        // Try to assign the job to the latest available slot before its deadline
        // We go from deadline-1 down to 0 (0-indexed)
        for (int slot = jobs[i].deadline - 1; slot >= 0; slot--) {
            if (timeSlot[slot] == -1) {
                // Found a free slot! Assign this job here
                timeSlot[slot] = jobs[i].id;
                totalProfit   += jobs[i].profit;
                jobCount++;
                break;  // Move to next job
            }
        }
    }

    // Step 3: Display the result
    cout << "\nScheduled Jobs (in time order):" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < maxDeadline; i++) {
        if (timeSlot[i] != -1) {
            cout << "Time Slot " << i + 1 << ": Job " << timeSlot[i] << endl;
        }
    }
    cout << "\nTotal Jobs Scheduled: " << jobCount << endl;
    cout << "Total Profit: " << totalProfit << endl;
}

int main() {
    int n;

    cout << "=== Job Sequencing Problem (Greedy) ===" << endl;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job jobs[n];

    cout << "\nEnter Job ID, Deadline, and Profit for each job:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << " -> ID: ";
        cin >> jobs[i].id;
        cout << "Job " << i + 1 << " -> Deadline: ";
        cin >> jobs[i].deadline;
        cout << "Job " << i + 1 << " -> Profit: ";
        cin >> jobs[i].profit;
    }

    // Solve Job Sequencing
    jobSequencing(jobs, n);

    return 0;
}

/*
============================
Time Complexity:
  Sorting:       O(n^2)
  Assignment:    O(n * maxDeadline)
  Overall:       O(n^2)

Space Complexity: O(maxDeadline) -> For the time slot array

Greedy Strategy: Pick highest profit jobs first, then assign to latest free slot.
============================
*/
