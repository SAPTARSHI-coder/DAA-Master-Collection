// Program: Bellman-Ford Algorithm (Shortest Path with Negative Weights)
// What it does: Finds the shortest path from a single source to all vertices.
//               UNLIKE Dijkstra, it handles NEGATIVE weight edges.
//               Also DETECTS negative weight cycles.
//               Relaxes ALL edges (V-1) times.
//
// Example Input:
//   5 vertices, 8 edges, Source = 0
//   Edges (u, v, weight):
//     0->1 weight -1, 0->2 weight 4
//     1->2 weight 3,  1->3 weight 2,  1->4 weight 2
//     3->2 weight 5,  3->1 weight 1,  4->3 weight -3
// Expected Output: Distances: 0, -1, 2, -2, 1

#include <iostream>
using namespace std;

#define INF 99999

// Structure to represent a directed edge
struct Edge {
    int source;
    int destination;
    int weight;
};

// Bellman-Ford Algorithm
void bellmanFord(Edge edges[], int numEdges, int numVertices, int source) {
    // Step 1: Initialize distances from source to all vertices as INFINITY
    int distance[numVertices];
    for (int i = 0; i < numVertices; i++) {
        distance[i] = INF;
    }
    distance[source] = 0;  // Distance to source itself is 0

    // Step 2: RELAX all edges (V - 1) times
    // Why V-1? The shortest path in a graph with V vertices can have at most V-1 edges.
    for (int iteration = 1; iteration <= numVertices - 1; iteration++) {

        // Go through ALL edges and relax each one
        for (int e = 0; e < numEdges; e++) {
            int u = edges[e].source;
            int v = edges[e].destination;
            int w = edges[e].weight;

            // Relaxation: If going from source->u->v is shorter, update distance[v]
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Step 3: Check for NEGATIVE WEIGHT CYCLES
    // If we can still relax an edge, there is a negative cycle
    bool hasNegativeCycle = false;
    for (int e = 0; e < numEdges; e++) {
        int u = edges[e].source;
        int v = edges[e].destination;
        int w = edges[e].weight;

        if (distance[u] != INF && distance[u] + w < distance[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    // Display results
    if (hasNegativeCycle) {
        cout << "\nNEGATIVE WEIGHT CYCLE DETECTED! No shortest path exists." << endl;
    } else {
        cout << "\nShortest distances from vertex " << source << ":" << endl;
        cout << "-------------------------------------------" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << source << " -> Vertex " << i << ": ";
            if (distance[i] == INF)
                cout << "UNREACHABLE" << endl;
            else
                cout << distance[i] << endl;
        }
    }
}

int main() {
    int numVertices, numEdges, source;

    cout << "=== Bellman-Ford Algorithm (Handles Negative Weights) ===" << endl;
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

    cout << "Enter source vertex: ";
    cin >> source;

    // Run Bellman-Ford Algorithm
    bellmanFord(edges, numEdges, numVertices, source);

    return 0;
}

/*
============================
Time Complexity:
  O(V * E) -> Relaxes all E edges, V-1 times
  V = vertices, E = edges

Space Complexity: O(V) -> For distance array

Key Advantage over Dijkstra: Works with NEGATIVE weight edges.
Key Limitation: Slower than Dijkstra for large graphs.
============================
*/
