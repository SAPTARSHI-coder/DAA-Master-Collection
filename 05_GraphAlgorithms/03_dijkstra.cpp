// Program: Dijkstra's Algorithm (Shortest Path - Single Source)
// What it does: Finds the SHORTEST PATH from a single source vertex to
//               ALL other vertices in a WEIGHTED graph (non-negative weights).
//               Uses a GREEDY approach - always picks the nearest unvisited vertex.
//
// Example Input:
//   5 vertices, Source = 0
//   Adjacency matrix with weights (0 means no edge):
//   Graph (0=no edge):
//      0  4  0  0  8
//      4  0  8  0  11
//      0  8  0  7  0
//      0  0  7  0  9
//      8  11 0  9  0
// Expected Output: Shortest distances from vertex 0

#include <iostream>
using namespace std;

#define MAX_VERTICES 100
#define INF 99999   // Represents infinity (no path)

// Function to find the vertex with minimum distance that is NOT yet processed
int findMinDistance(int distance[], bool processed[], int numVertices) {
    int minDistance = INF;
    int minVertex   = -1;

    for (int v = 0; v < numVertices; v++) {
        // Pick unprocessed vertex with smallest distance
        if (!processed[v] && distance[v] <= minDistance) {
            minDistance = distance[v];
            minVertex   = v;
        }
    }
    return minVertex;
}

// Dijkstra's Algorithm
void dijkstra(int graph[][MAX_VERTICES], int numVertices, int source) {
    int  distance[numVertices];   // Shortest distance from source to each vertex
    bool processed[numVertices];  // Has this vertex been processed?

    // Step 1: Initialize all distances as INFINITY, source = 0
    for (int i = 0; i < numVertices; i++) {
        distance[i]  = INF;
        processed[i] = false;
    }
    distance[source] = 0;  // Distance to source itself is 0

    // Step 2: Process all vertices
    for (int count = 0; count < numVertices - 1; count++) {
        // Pick the unprocessed vertex with minimum distance
        int u = findMinDistance(distance, processed, numVertices);

        if (u == -1) break;  // No reachable vertices left

        // Mark this vertex as processed
        processed[u] = true;

        // Step 3: Update distances of all neighbors of u
        for (int v = 0; v < numVertices; v++) {
            // Update distance[v] if:
            // 1. There is an edge from u to v  (graph[u][v] != 0)
            // 2. v is not yet processed
            // 3. Going through u gives a shorter path to v
            if (!processed[v] &&
                graph[u][v] != 0 &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];  // Relaxation step
            }
        }
    }

    // Display the shortest distances
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

int main() {
    int numVertices;

    cout << "=== Dijkstra's Shortest Path Algorithm ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    int graph[MAX_VERTICES][MAX_VERTICES];

    cout << "\nEnter adjacency matrix (0 if no edge, else weight):" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "\nEnter source vertex: ";
    cin >> source;

    // Run Dijkstra's Algorithm
    dijkstra(graph, numVertices, source);

    return 0;
}

/*
============================
Time Complexity:
  O(V^2) with adjacency matrix (V = vertices)
  O((V + E) log V) with min-heap + adjacency list

Space Complexity: O(V) -> For distance and processed arrays

IMPORTANT: Does NOT work with negative weight edges. Use Bellman-Ford for that.
============================
*/
