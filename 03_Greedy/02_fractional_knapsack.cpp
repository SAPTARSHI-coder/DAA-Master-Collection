// Program: Fractional Knapsack Problem (Greedy)
// What it does: Given items with weights and values, and a knapsack of
//               limited capacity, select items (or fractions of items)
//               to MAXIMIZE total value in the knapsack.
// Key: Unlike 0/1 Knapsack, here we CAN take fractions of an item.
// Greedy Choice: Always take the item with the HIGHEST value-to-weight ratio.
//
// Example Input:
//   Capacity = 50
//   Items:  Weight  Value   Ratio
//     1:      10     60      6.0
//     2:      20     100     5.0
//     3:      30     120     4.0
// Expected Output: Max Value = 240.0

#include <iostream>
using namespace std;

// Structure to represent an item
struct Item {
    int weight;    // Weight of the item
    int value;     // Value of the item
    double ratio;  // Value per unit weight (value/weight)
    int index;     // Item number (for display)
};

// Function to sort items by value-to-weight ratio in decreasing order (Bubble Sort)
void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp    = items[j];
                items[j]    = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Function to solve Fractional Knapsack using Greedy
void fractionalKnapsack(Item items[], int n, int capacity) {
    // Step 1: Sort items by value-to-weight ratio (highest first)
    sortByRatio(items, n);

    double totalValue       = 0.0;  // Total value accumulated
    int remainingCapacity   = capacity;  // Remaining space in knapsack

    cout << "\nItems taken in the knapsack:" << endl;
    cout << "------------------------------------" << endl;

    // Step 2: Greedily pick items
    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0) break;  // Knapsack is full

        if (items[i].weight <= remainingCapacity) {
            // Take the FULL item if it fits in the remaining capacity
            totalValue        += items[i].value;
            remainingCapacity -= items[i].weight;

            cout << "Item " << items[i].index
                 << " -> Taken FULL (Weight: " << items[i].weight
                 << ", Value: " << items[i].value << ")" << endl;
        } else {
            // Take a FRACTION of the item to fill the remaining capacity
            double fraction    = (double)remainingCapacity / items[i].weight;
            double takenValue  = fraction * items[i].value;
            totalValue        += takenValue;

            cout << "Item " << items[i].index
                 << " -> Taken " << fraction * 100 << "% (Weight: "
                 << remainingCapacity << ", Value: " << takenValue << ")" << endl;

            remainingCapacity = 0;  // Knapsack is now full
        }
    }

    cout << "\nMaximum Value in Knapsack = " << totalValue << endl;
}

int main() {
    int n, capacity;

    cout << "=== Fractional Knapsack Problem (Greedy) ===" << endl;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    Item items[n];

    cout << "\nEnter weight and value for each item:" << endl;
    for (int i = 0; i < n; i++) {
        items[i].index = i + 1;
        cout << "Item " << i + 1 << " -> Weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " -> Value: ";
        cin >> items[i].value;
        // Calculate value-to-weight ratio
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Solve Fractional Knapsack
    fractionalKnapsack(items, n, capacity);

    return 0;
}

/*
============================
Time Complexity:
  Sorting:    O(n^2) using Bubble Sort (O(n log n) with better sort)
  Selection:  O(n)
  Overall:    O(n^2)

Space Complexity: O(1) -> In-place operations

Greedy Strategy: Sort by value/weight ratio, always pick the best ratio item first.
============================
*/
