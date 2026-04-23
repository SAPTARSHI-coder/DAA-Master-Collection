// Program: Optimal Binary Search Tree (Dynamic Programming)
// What it does: Given a sorted set of KEYS and their SEARCH FREQUENCIES,
//               find the BST arrangement that MINIMIZES total EXPECTED SEARCH COST.
//               Not all BSTs are equal — a balanced one may be worse if
//               frequently searched keys are deep in the tree.
//               Total cost = sum of (frequency[i] * depth[i]) for all keys.
//
// Example Input: 3 keys, Frequencies: 34 8 50
// Expected Output: Minimum cost and optimal root for each range

#include <iostream>
#include <climits>
using namespace std;

#define MAX 15

int keys[MAX];        // The sorted keys
int freq[MAX];        // Search frequency of each key
int cost[MAX][MAX];   // cost[i][j] = min cost of OBST for keys i to j
int root[MAX][MAX];   // root[i][j] = optimal root of OBST from key i to key j
int n;                // Number of keys

// Function to compute sum of frequencies from index i to j
int sumFreq(int i, int j) {
    int total = 0;
    for (int k = i; k <= j; k++) total += freq[k];
    return total;
}

// Dynamic Programming function to build Optimal BST
void optimalBST() {
    // Base case: Single keys (chains of length 1)
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];   // Single key -> cost is just its frequency
        root[i][i] = i;
    }

    // Base case: Empty range (no keys)
    for (int i = 0; i < n; i++) cost[i][i - 1] = 0;

    // Fill for increasing chain lengths (2 keys, 3 keys, ..., n keys)
    for (int chainLen = 2; chainLen <= n; chainLen++) {
        for (int i = 0; i <= n - chainLen; i++) {
            int j = i + chainLen - 1;  // End of current range

            cost[i][j] = INT_MAX;

            // Try every key r as ROOT of this range [i..j]
            for (int r = i; r <= j; r++) {
                // Cost if r is root:
                //   Left subtree cost  + Right subtree cost + sum of all frequencies in [i..j]
                // (Adding sumFreq because every key goes one level deeper when r is root)
                int leftCost  = (r > i) ? cost[i][r - 1] : 0;
                int rightCost = (r < j) ? cost[r + 1][j] : 0;
                int totalCost = leftCost + rightCost + sumFreq(i, j);

                // Update if this root gives minimum cost
                if (totalCost < cost[i][j]) {
                    cost[i][j] = totalCost;
                    root[i][j] = r;
                }
            }
        }
    }
}

// Display the optimal tree structure
void displayTree(int i, int j, int parent, string side) {
    if (i > j) return;

    int r = root[i][j];
    if (parent == -1)
        cout << "  Key " << keys[r] << " is the ROOT" << endl;
    else
        cout << "  Key " << keys[r] << " is the " << side
             << " child of Key " << keys[parent] << endl;

    displayTree(i, r - 1, r, "LEFT ");
    displayTree(r + 1, j, r, "RIGHT");
}

int main() {
    cout << "=== Optimal Binary Search Tree (DP) ===" << endl;
    cout << "Enter the number of keys: ";
    cin >> n;

    cout << "\nEnter the SORTED keys: ";
    for (int i = 0; i < n; i++) cin >> keys[i];

    cout << "Enter the SEARCH FREQUENCIES for each key:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  Frequency of key " << keys[i] << ": ";
        cin >> freq[i];
    }

    optimalBST();

    cout << "\nMinimum Expected Search Cost: " << cost[0][n - 1] << endl;

    cout << "\nOptimal BST Structure:" << endl;
    displayTree(0, n - 1, -1, "");

    return 0;
}

/*
============================
Time Complexity:
  O(n^3) -> Three nested loops: chain length, range start, root selection

Space Complexity: O(n^2) -> For cost and root tables

WHY THIS IS IMPORTANT:
  A balanced BST gives O(log n) per search ON AVERAGE.
  An OBST gives O(log n) per search WEIGHTED BY FREQUENCY.
  If key 'A' is searched 1000x more than 'Z', put 'A' near the root!
============================
*/
