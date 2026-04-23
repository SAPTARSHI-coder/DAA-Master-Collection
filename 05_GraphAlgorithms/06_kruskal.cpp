// Program: Kruskal's Algorithm (Minimum Spanning Tree)
// What it does: Finds the MINIMUM SPANNING TREE of a connected, undirected,
//               weighted graph. An MST connects all vertices with minimum total
//               edge weight and NO cycles.
// Approach: Sort all edges by weight (ascending), then greedily add edges
//            that don't form a cycle using UNION-FIND (Disjoint Set Union).
//
// Example Input:
//   4 vertices, 5 edges:
//   0-1 (10), 0-2 (6), 0-3 (5), 1-3 (15), 2-3 (4)
// Expected Output: MST edges with total cost = 19

#include <iostream>
using namespace std;

// Structure to represent an edge
struct Edge {
    int source;
    int destination;
    int weight;
};

// Union-Find (Disjoint Set) for cycle detection
int parent[100];  // parent[i] = parent of vertex i

// Find root of the set containing vertex v (with path compression)
int findParent(int v) {
    if (parent[v] != v)
        parent[v] = findParent(parent[v]);  // Path compression
    return parent[v];
}

// Union two sets containing vertices u and v
void unionSet(int u, int v) {
    int rootU = findParent(u);
    int rootV = findParent(v);
    parent[rootU] = rootV;  // Merge the two sets
}

// Function to sort edges by weight using Bubble Sort
void sortEdgesByWeight(Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - 1 - i; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp    = edges[j];
                edges[j]    = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal's Algorithm
void kruskal(Edge edges[], int numEdges, int numVertices) {
    // Step 1: Sort all edges by weight (ascending)
    sortEdgesByWeight(edges, numEdges);

    // Step 2: Initialize Union-Find - each vertex is its own parent initially
    for (int i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    cout << "\nEdges in Minimum Spanning Tree:" << endl;
    cout << "-----------------------------------" << endl;

    int totalCost    = 0;
    int edgesInMST   = 0;

    // Step 3: Greedily add edges that don't form a cycle
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int w = edges[i].weight;

        // Find root of both vertices
        int rootU = findParent(u);
        int rootV = findParent(v);

        // If they have DIFFERENT roots, adding this edge won't form a cycle
        if (rootU != rootV) {
            cout << "Edge: " << u << " -- " << v << " (Weight: " << w << ")" << endl;
            totalCost  += w;
            edgesInMST++;
            unionSet(u, v);  // Merge the two components

            // MST has exactly V-1 edges
            if (edgesInMST == numVertices - 1) break;
        }
    }

    cout << "\nTotal MST Cost: " << totalCost << endl;
}

int main() {
    int numVertices, numEdges;

    cout << "=== Kruskal's Algorithm (Minimum Spanning Tree) ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    cout << "Enter number of edges: ";
    cin >> numEdges;

    Edge edges[numEdges];

    cout << "\nEnter each edge (source destination weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        cout << "Edge " << i + 1 << " (u v w): ";
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    // Run Kruskal's Algorithm
    kruskal(edges, numEdges, numVertices);

    return 0;
}

/*
============================
Time Complexity:
  Sorting edges:  O(E log E) [with efficient sort]
  Union-Find:     O(E * alpha(V)) ≈ O(E) [nearly constant with path compression]
  Overall:        O(E log E)

Space Complexity: O(V + E) -> For parent array and edge list

Key: Processes EDGES in sorted order. Good for sparse graphs.
============================
*/
