// Program: Strongly Connected Components - Kosaraju's Algorithm
// What it does: Finds all STRONGLY CONNECTED COMPONENTS (SCCs) of a directed graph.
//               An SCC is a maximal group of vertices where EVERY vertex can reach
//               every other vertex in the group.
//               Example: In a road network, an SCC = a set of locations you can
//               travel between in BOTH directions.
//
// Kosaraju's Algorithm (Two DFS passes):
//   Step 1: DFS on original graph -> push vertices to stack by FINISH TIME
//   Step 2: Build TRANSPOSE graph (reverse all edges)
//   Step 3: DFS on transpose in stack order -> each DFS tree = one SCC
//
// Example Input: 5 vertices, edges: 1->0, 0->2, 2->1, 0->3, 3->4

#include <iostream>
using namespace std;

#define MAX 20

int graph[MAX][MAX];         // Original graph (adjacency matrix)
int transposeGraph[MAX][MAX]; // Transpose of the graph (all edges reversed)
int visited[MAX];            // Visited array
int stack[MAX];              // Stack to store vertices by finish time
int stackTop;                // Stack pointer
int N;                       // Number of vertices

// First DFS on original graph: push to stack when fully explored (post-order)
void dfsOriginal(int v) {
    visited[v] = 1;

    for (int u = 0; u < N; u++) {
        if (graph[v][u] == 1 && !visited[u]) {
            dfsOriginal(u);
        }
    }

    // Push v to stack AFTER all its neighbors explored (post-order = finish time)
    stack[stackTop++] = v;
}

// Second DFS on TRANSPOSE graph: print all vertices in this DFS = one SCC
void dfsTranspose(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int u = 0; u < N; u++) {
        if (transposeGraph[v][u] == 1 && !visited[u]) {
            dfsTranspose(u);
        }
    }
}

// Main Kosaraju's Algorithm
void kosarajuSCC() {
    // Step 1: Run DFS on original graph and fill stack by finish time
    for (int i = 0; i < N; i++) visited[i] = 0;
    stackTop = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfsOriginal(i);
        }
    }

    // Step 2: Build transpose graph (reverse all edges)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            transposeGraph[i][j] = graph[j][i];  // Reverse edge direction

    // Step 3: Run DFS on transpose in reverse finish-time order (stack order)
    for (int i = 0; i < N; i++) visited[i] = 0;

    int sccCount = 0;
    cout << "\nStrongly Connected Components (SCCs):" << endl;
    cout << "--------------------------------------" << endl;

    // Process vertices in reverse order of finish times (stack top to bottom)
    while (stackTop > 0) {
        int v = stack[--stackTop];  // Pop from stack

        if (!visited[v]) {
            sccCount++;
            cout << "SCC " << sccCount << ": { ";
            dfsTranspose(v);  // All vertices in this DFS = exactly one SCC
            cout << "}" << endl;
        }
    }

    cout << "\nTotal SCCs: " << sccCount << endl;
}

int main() {
    int numEdges;
    cout << "=== Strongly Connected Components (Kosaraju's Algorithm) ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> N;
    cout << "Enter number of directed edges: ";
    cin >> numEdges;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    cout << "Enter edges (directed: from to):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        graph[u][v] = 1;
    }

    kosarajuSCC();

    return 0;
}

/*
============================
Time Complexity:  O(V^2) with adjacency matrix [O(V+E) with adjacency list]
Space Complexity: O(V^2) for matrices, O(V) for visited and stack

KEY POINT FOR VIVA:
  SCC = maximal set of vertices with path between every pair
  Kosaraju's uses TWO DFS passes + graph transposition
  Tarjan's Algorithm is another SCC algorithm using a single DFS + low-link values
============================
*/
