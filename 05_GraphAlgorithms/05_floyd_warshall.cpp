// Program: Floyd-Warshall Algorithm (All-Pairs Shortest Path)
// What it does: Finds the SHORTEST PATHS between ALL pairs of vertices
//               in a weighted graph (works with negative weights too,
//               but no negative cycles).
//               Uses Dynamic Programming with 3 nested loops.
//
// Example Input:
//   4 vertices
//   Adjacency matrix (INF = 99999 means no edge):
//     0   3  INF  7
//     8   0   2  INF
//    5  INF   0   1
//    2  INF  INF  0
// Expected Output: Updated matrix with shortest distances between all pairs

#include <iostream>
using namespace std;

#define INF 99999   // Represents no direct edge (infinity)
#define MAX 100

// Function to display the distance matrix
void displayMatrix(int dist[][MAX], int n) {
    cout << "\nShortest distance matrix:" << endl;
    cout << "------------------------------------" << endl;
    cout << "   ";
    for (int i = 0; i < n; i++) cout << "  V" << i << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "V" << i << " ";
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "  INF ";
            else
                cout << "  " << dist[i][j] << "  ";
        }
        cout << endl;
    }
}

// Floyd-Warshall Algorithm
void floydWarshall(int graph[][MAX], int numVertices) {
    // dist[i][j] = shortest distance from vertex i to vertex j
    int dist[MAX][MAX];

    // Step 1: Initialize dist matrix as the same as graph matrix
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            dist[i][j] = graph[i][j];

    cout << "\nInitial distance matrix (from input graph):";
    displayMatrix(dist, numVertices);

    // Step 2: Consider each vertex as an INTERMEDIATE vertex
    // 'k' is the intermediate vertex through which we check for shorter paths
    for (int k = 0; k < numVertices; k++) {

        // For every source vertex i
        for (int i = 0; i < numVertices; i++) {

            // For every destination vertex j
            for (int j = 0; j < numVertices; j++) {

                // Check if going through vertex k gives a shorter path from i to j
                // dist[i][k] = cost from i to k
                // dist[k][j] = cost from k to j
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Step 3: Check for negative cycles (if dist[i][i] < 0 for any vertex)
    bool hasNegativeCycle = false;
    for (int i = 0; i < numVertices; i++) {
        if (dist[i][i] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "\nNEGATIVE CYCLE DETECTED! Floyd-Warshall cannot give correct result." << endl;
    } else {
        cout << "\nFinal shortest distance matrix (after Floyd-Warshall):";
        displayMatrix(dist, numVertices);
    }
}

int main() {
    int numVertices;

    cout << "=== Floyd-Warshall (All-Pairs Shortest Path) ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> numVertices;

    int graph[MAX][MAX];

    cout << "\nEnter adjacency matrix (use " << INF << " for no direct edge):" << endl;
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            cin >> graph[i][j];

    // Run Floyd-Warshall
    floydWarshall(graph, numVertices);

    return 0;
}

/*
============================
Time Complexity:
  O(V^3) -> Three nested loops for V vertices

Space Complexity: O(V^2) -> For the distance matrix

Key: Works for ALL pairs (unlike Dijkstra/Bellman-Ford which are single-source).
============================
*/
