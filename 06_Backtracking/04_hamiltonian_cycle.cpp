// Program: Hamiltonian Cycle (Backtracking)
// What it does: Finds a HAMILTONIAN CYCLE in a graph — a path that:
//               - Visits EVERY vertex EXACTLY ONCE.
//               - Returns back to the STARTING VERTEX at the end.
//               (Like a salesman who visits every city exactly once and returns home)
// Uses BACKTRACKING: try adding vertices one by one; if stuck, backtrack.
//
// Example Input:
//   5 vertices
//   Edges: 0-1, 0-3, 1-2, 1-4, 2-3, 2-4, 3-4
// Expected Output: Hamiltonian Cycle: 0 -> 1 -> 2 -> 3 -> 4 -> 0

#include <iostream>
using namespace std;

#define MAX 20

int graph[MAX][MAX];    // Adjacency matrix
int path[MAX];          // Stores the Hamiltonian path/cycle
int N;                  // Number of vertices

// Check if adding vertex 'v' at position 'pos' in path is VALID
bool isSafeToAdd(int v, int pos) {
    // Check 1: Is there an edge from the last vertex in path to v?
    if (graph[path[pos - 1]][v] == 0) return false;

    // Check 2: Has vertex v already been visited in the path?
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }

    return true;  // Safe to add v
}

// Recursive backtracking function to find Hamiltonian Cycle
bool findHamiltonianCycle(int pos) {
    // BASE CASE: All vertices are included in the path
    if (pos == N) {
        // Check if there's an edge back to the STARTING VERTEX (vertex 0)
        // This makes it a CYCLE, not just a path
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;  // Hamiltonian Cycle found!
        } else {
            return false;  // No edge back to start -> not a cycle
        }
    }

    // Try each vertex as the next vertex in the path
    for (int v = 1; v < N; v++) {  // Start from 1 (vertex 0 is always start)
        if (isSafeToAdd(v, pos)) {
            path[pos] = v;  // Add vertex v at current position

            // Recursively try to complete the path
            if (findHamiltonianCycle(pos + 1)) {
                return true;  // Path completed!
            }

            // BACKTRACK: vertex v didn't work, try the next one
            path[pos] = -1;
        }
    }

    return false;  // No vertex works here -> backtrack to previous position
}

int main() {
    int numEdges;

    cout << "=== Hamiltonian Cycle (Backtracking) ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> N;

    cout << "Enter number of edges: ";
    cin >> numEdges;

    // Initialize graph
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    // Initialize path to -1 (no vertex added yet)
    for (int i = 0; i < N; i++) path[i] = -1;

    cout << "\nEnter edges (undirected: u v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Always start the Hamiltonian Cycle from vertex 0
    path[0] = 0;

    if (findHamiltonianCycle(1)) {
        cout << "\nHamiltonian Cycle FOUND:" << endl;
        cout << "Cycle: ";
        for (int i = 0; i < N; i++) cout << path[i] << " -> ";
        cout << path[0] << endl;  // Return to starting vertex
    } else {
        cout << "\nNo Hamiltonian Cycle exists in this graph." << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(N!) -> In the worst case, tries all permutations of N vertices

Space Complexity: O(N) -> For path array and recursion stack

Difference:
  Hamiltonian PATH  -> Visit all vertices exactly once (no return needed)
  Hamiltonian CYCLE -> Visit all vertices + return to start

Related: TSP (Travelling Salesman Problem) = Hamiltonian Cycle with MINIMUM COST
============================
*/
