// Program: Transitive Closure of a Graph (Warshall's Algorithm)
// What it does: Given a DIRECTED graph, find the TRANSITIVE CLOSURE.
//               Transitive Closure matrix TC where:
//               TC[i][j] = 1 if there is a PATH from vertex i to vertex j
//                              (directly or through intermediate vertices)
//               TC[i][j] = 0 if no path exists from i to j
//
// Real-life: Reachability in networks, airline route reachability,
//            database query optimization, dependency chains.
//
// Example: If A->B and B->C, then A can reach C (TC[A][C] = 1)
//          even though there's no direct edge A->C.

#include <iostream>
using namespace std;

#define MAX 10

int TC[MAX][MAX];  // Transitive Closure matrix
int N;             // Number of vertices

// Warshall's Algorithm (same structure as Floyd-Warshall but only for reachability)
void warshall() {
    // For each intermediate vertex k
    for (int k = 0; k < N; k++) {
        // For each source vertex i
        for (int i = 0; i < N; i++) {
            // For each destination vertex j
            for (int j = 0; j < N; j++) {
                // If i can reach k AND k can reach j -> i can reach j
                if (TC[i][k] == 1 && TC[k][j] == 1) {
                    TC[i][j] = 1;
                }
            }
        }

        cout << "\nAfter considering vertex " << k << " as intermediate:" << endl;
        cout << "  ";
        for (int i = 0; i < N; i++) cout << i << " ";
        cout << endl;
        for (int i = 0; i < N; i++) {
            cout << i << " ";
            for (int j = 0; j < N; j++) cout << TC[i][j] << " ";
            cout << endl;
        }
    }
}

int main() {
    cout << "=== Transitive Closure - Warshall's Algorithm ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> N;

    cout << "\nEnter the adjacency matrix (1=edge, 0=no edge):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < N; j++) cin >> TC[i][j];
    }

    cout << "\nInitial Adjacency Matrix:" << endl;
    cout << "  ";
    for (int i = 0; i < N; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " ";
        for (int j = 0; j < N; j++) cout << TC[i][j] << " ";
        cout << endl;
    }

    warshall();

    cout << "\nFinal Transitive Closure (TC[i][j]=1 means i can reach j):" << endl;
    cout << "  ";
    for (int j = 0; j < N; j++) cout << j << " ";
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " ";
        for (int j = 0; j < N; j++) cout << TC[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*
============================
Time Complexity:  O(V^3) -> Three nested loops (same as Floyd-Warshall)
Space Complexity: O(V^2) -> For the TC matrix

DIFFERENCE from Floyd-Warshall:
  Floyd-Warshall: Finds SHORTEST DISTANCES between all pairs
  Warshall's:     Finds REACHABILITY only (1 or 0, not actual distance)
============================
*/
