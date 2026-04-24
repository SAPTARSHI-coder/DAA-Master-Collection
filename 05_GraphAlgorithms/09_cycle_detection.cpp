// Program: Cycle Detection in Directed Graph (DFS with Recursion Stack)
// What it does: Detects whether a DIRECTED graph contains a cycle.
//               Uses DFS and maintains a "recursion stack" to track the
//               current DFS path. If we reach a vertex already in the
//               current DFS path, a cycle exists.
//
// Example Input:
//   4 vertices, 4 edges:
//   0->1, 1->2, 2->3, 3->1 (cycle: 1->2->3->1)
// Expected Output: Cycle DETECTED

#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];         // Adjacency matrix
bool visited[MAX];           // Has vertex been visited at all?
bool inCurrentPath[MAX];     // Is vertex in the current DFS traversal path?
int numVertices;

// DFS function that also detects cycles
// Returns true if a cycle is detected
bool dfsCycleDetect(int vertex) {
    // Mark vertex as visited and add to current DFS path
    visited[vertex]       = true;
    inCurrentPath[vertex] = true;

    // Visit all neighbors
    for (int neighbor = 0; neighbor < numVertices; neighbor++) {
        if (graph[vertex][neighbor] == 1) {  // Edge exists

            if (!visited[neighbor]) {
                // Neighbor not yet visited, recurse into it
                if (dfsCycleDetect(neighbor)) {
                    return true;  // Cycle found deeper, propagate result
                }
            }
            else if (inCurrentPath[neighbor]) {
                // Neighbor IS in the current DFS path -> CYCLE DETECTED!
                cout << "Cycle detected involving vertex " << neighbor << endl;
                return true;
            }
        }
    }

    // Remove vertex from current DFS path (backtrack)
    inCurrentPath[vertex] = false;
    return false;
}

// Function to detect cycle in the entire graph (handles disconnected graphs)
bool hasCycle() {
    // Initialize all arrays
    for (int i = 0; i < numVertices; i++) {
        visited[i]       = false;
        inCurrentPath[i] = false;
    }

    // Check each vertex (handles disconnected components)
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            if (dfsCycleDetect(i)) {
                return true;  // Cycle found
            }
        }
    }
    return false;  // No cycle
}

int main() {
    int numEdges;

    cout << "=== Cycle Detection in Directed Graph (DFS) ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    cout << "Enter number of edges: ";
    cin >> numEdges;

    // Initialize graph
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = 0;

    cout << "\nEnter directed edges (u -> v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        graph[u][v] = 1;  // Directed edge
    }

    // Check for cycle
    if (hasCycle()) {
        cout << "\nResult: CYCLE DETECTED in the directed graph!" << endl;
    } else {
        cout << "\nResult: No cycle found. Graph is a DAG (Directed Acyclic Graph)." << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(V^2) with adjacency matrix
  O(V + E) with adjacency list

Space Complexity: O(V) -> visited[], inCurrentPath[], and recursion stack

Key Difference: Undirected graph uses simpler parent check.
                Directed graph needs recursion stack tracking.
============================
*/
