// ============================================================
// CASE STUDY 24: Minimum Cost to Connect Ropes (Greedy)
// ============================================================
//
// PROBLEM STATEMENT:
//   You have N ropes of different lengths. Each time you connect
//   two ropes, the cost = SUM of their lengths. Find the MINIMUM
//   TOTAL COST to connect all ropes into one.
//
// REAL-LIFE: Minimum cost to merge files, minimum transmission cost
//            to merge data packets, minimum cost to combine tasks.
//
// ============================================================
// PATTERN RECOGNITION: WHY GREEDY (Always merge smallest)?
// ============================================================
//
//  KEY INSIGHT: Always merge the TWO SMALLEST ropes first.
//               Merging small ropes first incurs low cost repeatedly.
//               If you merge large ropes early, their length gets
//               added to ALL subsequent merges (expensive!).
//
//  This is EXACTLY the idea behind HUFFMAN CODING — always combine
//  the two lowest-frequency items first.
//
//  IMPLEMENTATION: Use a MIN-HEAP (priority queue).
//    1. Push all rope lengths into min-heap.
//    2. Repeatedly extract two minimums, add their sum as cost,
//       and push the combined rope back into the heap.
//    3. Stop when only one rope remains.
//
//  Without STL, we simulate min-heap using sorted array.
//
// ============================================================

#include <iostream>
using namespace std;

// Simple min-heap using sorted array (insertion sort after each add)
int heap[200];
int heapSize;

// Add element and maintain sorted order (simulated min-heap)
void insertToHeap(int val) {
    heap[heapSize++] = val;
    // Insertion sort step to maintain sorted order
    int i = heapSize - 1;
    while (i > 0 && heap[i] < heap[i - 1]) {
        int temp    = heap[i];
        heap[i]     = heap[i - 1];
        heap[i - 1] = temp;
        i--;
    }
}

// Extract minimum (first element in sorted array)
int extractMin() {
    int minVal = heap[0];
    for (int i = 0; i < heapSize - 1; i++) heap[i] = heap[i + 1];
    heapSize--;
    return minVal;
}

int connectRopes(int ropes[], int n) {
    heapSize = 0;

    // Push all rope lengths into min-heap
    for (int i = 0; i < n; i++) insertToHeap(ropes[i]);

    int totalCost = 0;
    int stepCount = 0;

    cout << "\nGreedy Merge Trace (always merge 2 smallest):" << endl;
    cout << "-----------------------------------------------" << endl;

    // Keep merging until only one rope remains
    while (heapSize > 1) {
        int rope1 = extractMin();  // Smallest rope
        int rope2 = extractMin();  // Second smallest rope

        int combinedLength = rope1 + rope2;
        totalCost += combinedLength;
        stepCount++;

        cout << "Step " << stepCount << ": Merge " << rope1
             << " + " << rope2 << " = " << combinedLength
             << " (Running cost: " << totalCost << ")" << endl;

        // Push combined rope back into heap
        insertToHeap(combinedLength);
    }

    return totalCost;
}

int main() {
    int n;
    cout << "=== CASE STUDY 24: Minimum Cost to Connect Ropes (Greedy) ===" << endl;
    cout << "Enter number of ropes: ";
    cin >> n;

    int ropes[n];
    cout << "Enter lengths of all ropes: ";
    for (int i = 0; i < n; i++) cin >> ropes[i];

    int result = connectRopes(ropes, n);
    cout << "\nMinimum Total Cost to Connect All Ropes: " << result << endl;

    return 0;
}

/*
============================
Time:  O(n^2) with sorted array simulation [O(n log n) with real min-heap]
Space: O(n)

THIS IS THE SAME IDEA AS HUFFMAN CODING!
  Huffman:      Merge lowest frequency nodes to build optimal prefix code tree
  Connect Ropes: Merge shortest ropes to minimize total merge cost

SIMILAR:
  Huffman Coding            -> same greedy merge logic
  Minimum Cost to Merge Stones -> DP variant (not just 2 stones at a time)
============================
*/
