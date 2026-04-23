// Program: DFS - Depth First Search (Graph Traversal)
// What it does: Explores as FAR as possible along each branch before backtracking.
//               Goes deep into the graph using a STACK (or recursion).
//               Used for detecting cycles, topological sort, finding paths.
//
// Example Input:
//   Graph with 6 vertices:
//   Edges: 0-1, 0-2, 1-3, 1-4, 2-5
//   Start vertex: 0
// Expected Output: DFS order: 0 1 3 4 2 5

#include <iostream>
using namespace std;

#define MAX_VERTICES 100

// Adjacency Matrix representation of graph
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

// DFS recursive function
void dfs(int currentVertex, int numVertices) {
    // Mark current vertex as visited and print it
    visited[currentVertex] = true;
    cout << currentVertex << " ";

    // Visit all unvisited neighbors of this vertex
    for (int neighbor = 0; neighbor < numVertices; neighbor++) {
        // If there is an edge AND neighbor is not yet visited
        if (graph[currentVertex][neighbor] == 1 && !visited[neighbor]) {
            // Recursively call DFS on the neighbor (go deeper)
            dfs(neighbor, numVertices);
        }
    }
    // When all neighbors are visited, we BACKTRACK (return to previous call)
}

int main() {
    int numVertices, numEdges;

    cout << "=== DFS - Depth First Search ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    cout << "Enter number of edges: ";
    cin >> numEdges;

    // Initialize graph (all zeros = no edges)
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            graph[i][j] = 0;

    // Initialize visited array (all false = not visited)
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    cout << "\nEnter " << numEdges << " edges (vertex u and vertex v for each edge):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        // Since graph is undirected, add edge in both directions
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int source;
    cout << "\nEnter starting vertex for DFS: ";
    cin >> source;

    cout << "\nDFS Traversal starting from vertex " << source << ": ";
    dfs(source, numVertices);
    cout << endl;

    // Also handle disconnected graphs (visit remaining unvisited vertices)
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            cout << "(Disconnected component) DFS from vertex " << i << ": ";
            dfs(i, numVertices);
            cout << endl;
        }
    }

    return 0;
}

/*
============================
Time Complexity:
  O(V^2) with Adjacency Matrix (V = vertices)
  O(V + E) with Adjacency List  (E = edges)

Space Complexity: O(V) -> For visited array and recursive call stack

Use: Cycle detection, topological sort, finding connected components.
============================
*/
