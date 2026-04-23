// Program: Topological Sort (Graph Algorithm - DFS based)
// What it does: For a DIRECTED ACYCLIC GRAPH (DAG), produces a LINEAR ordering
//               of vertices such that for every directed edge u->v,
//               vertex u comes BEFORE v in the ordering.
// Use Case: Task scheduling, build dependency resolution, course prerequisites.
//
// Example Input:
//   6 vertices (0 to 5), edges:
//   5->2, 5->0, 4->0, 4->1, 2->3, 3->1
// Expected Output: Topological order: 5 4 2 3 1 0 (or similar valid order)

#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];   // Adjacency matrix
bool visited[MAX];     // Has vertex been visited?
int stack[MAX];        // Stack to store topological order (using array)
int stackTop = -1;     // Stack pointer

// Function to push to stack
void push(int vertex) {
    stack[++stackTop] = vertex;
}

// DFS-based Topological Sort
// Visit all vertices reachable from 'vertex', then add 'vertex' to stack
void topologicalSortDFS(int vertex, int numVertices) {
    visited[vertex] = true;

    // Visit all unvisited neighbors first (go deeper)
    for (int neighbor = 0; neighbor < numVertices; neighbor++) {
        if (graph[vertex][neighbor] == 1 && !visited[neighbor]) {
            topologicalSortDFS(neighbor, numVertices);
        }
    }

    // After visiting all neighbors, push current vertex to stack
    // This ensures vertex comes BEFORE its dependencies in the order
    push(vertex);
}

int main() {
    int numVertices, numEdges;

    cout << "=== Topological Sort (DFS-based) ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    cout << "Enter number of edges: ";
    cin >> numEdges;

    // Initialize graph and visited
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = 0;
    }

    cout << "\nEnter edges (directed: u -> v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << " (u v): ";
        cin >> u >> v;
        graph[u][v] = 1;  // Directed edge from u to v ONLY
    }

    // Run DFS from each unvisited vertex (handles disconnected DAGs too)
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, numVertices);
        }
    }

    // Print topological order (pop from stack = reverse DFS finish order)
    cout << "\nTopological Sort Order:" << endl;
    while (stackTop >= 0) {
        cout << stack[stackTop--] << " ";
    }
    cout << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(V + E) with adjacency list
  O(V^2) with adjacency matrix (V = vertices, E = edges)

Space Complexity: O(V) -> For visited array and stack

IMPORTANT: Works ONLY on Directed Acyclic Graphs (DAG).
           Cyclic graphs do NOT have a valid topological ordering.
============================
*/
