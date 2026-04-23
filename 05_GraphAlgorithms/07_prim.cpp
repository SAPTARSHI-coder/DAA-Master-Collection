// Program: Prim's Algorithm (Minimum Spanning Tree)
// What it does: Builds the Minimum Spanning Tree by GROWING a single tree
//               from a starting vertex. At each step, adds the SMALLEST weight
//               edge that connects a vertex IN the tree to a vertex NOT YET in the tree.
// Approach: VERTEX-based selection (unlike Kruskal which is edge-based).
//
// Example Input:
//   5 vertices
//   Adjacency matrix (0 = no edge):
//     0  2  0  6  0
//     2  0  3  8  5
//     0  3  0  0  7
//     6  8  0  0  9
//     0  5  7  9  0
// Expected Output: MST with Total Cost = 16

#include <iostream>
using namespace std;

#define INF 99999
#define MAX 100

// Function to find the vertex with minimum key value
// that is NOT yet included in the MST
int findMinKeyVertex(int key[], bool inMST[], int numVertices) {
    int minKey    = INF;
    int minVertex = -1;

    for (int v = 0; v < numVertices; v++) {
        // Only consider vertices not yet in MST with minimum key
        if (!inMST[v] && key[v] < minKey) {
            minKey    = key[v];
            minVertex = v;
        }
    }
    return minVertex;
}

// Prim's Algorithm
void prim(int graph[][MAX], int numVertices) {
    int  key[numVertices];      // Minimum weight edge to connect vertex to MST
    int  parent[numVertices];   // parent[v] = which vertex connects v to MST
    bool inMST[numVertices];    // Is vertex already included in MST?

    // Step 1: Initialize all keys as INFINITY (none are in MST yet)
    for (int i = 0; i < numVertices; i++) {
        key[i]    = INF;
        inMST[i]  = false;
        parent[i] = -1;
    }

    // Step 2: Start with vertex 0. Set its key to 0 (so it's picked first)
    key[0] = 0;

    // Step 3: Add V vertices to MST one by one
    for (int count = 0; count < numVertices; count++) {
        // Pick vertex with minimum key value that is NOT in MST
        int u = findMinKeyVertex(key, inMST, numVertices);

        if (u == -1) break;  // No reachable vertex found

        // Add this vertex to MST
        inMST[u] = true;

        // Step 4: Update key values of neighbors of u
        for (int v = 0; v < numVertices; v++) {
            // Update key[v] if:
            // 1. There is an edge from u to v
            // 2. v is not yet in MST
            // 3. The edge weight is less than the current key[v]
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v]    = graph[u][v];  // Update minimum edge weight
                parent[v] = u;           // Record which vertex gave this minimum
            }
        }
    }

    // Step 5: Display the MST
    cout << "\nEdges in Minimum Spanning Tree:" << endl;
    cout << "-----------------------------------" << endl;

    int totalCost = 0;
    for (int i = 1; i < numVertices; i++) {
        cout << "Edge: " << parent[i] << " -- " << i
             << " (Weight: " << graph[parent[i]][i] << ")" << endl;
        totalCost += graph[parent[i]][i];
    }

    cout << "\nTotal MST Cost: " << totalCost << endl;
}

int main() {
    int numVertices;

    cout << "=== Prim's Algorithm (Minimum Spanning Tree) ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    int graph[MAX][MAX];

    cout << "\nEnter adjacency matrix (0 if no edge, else weight):" << endl;
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            cin >> graph[i][j];

    // Run Prim's Algorithm
    prim(graph, numVertices);

    return 0;
}

/*
============================
Time Complexity:
  O(V^2) with adjacency matrix
  O((V + E) log V) with min-heap + adjacency list

Space Complexity: O(V) -> For key, parent, inMST arrays

Key Difference from Kruskal:
  Prim's = VERTEX based, starts from a vertex, grows one tree
  Kruskal's = EDGE based, sorts edges, merges components
============================
*/
