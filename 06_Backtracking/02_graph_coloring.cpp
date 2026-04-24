// Program: Graph Coloring Problem (Backtracking)
// What it does: Color the vertices of a graph such that NO two adjacent
//               vertices (connected by an edge) have the SAME color.
//               Find if it's possible to color with at most 'M' colors.
//
// Example Input:
//   4 vertices, 5 edges, M = 3 colors
//   Edges: 0-1, 0-3, 1-2, 1-3, 2-3
// Expected Output: Color assignment: 1 2 3 2 (or other valid colorings)

#include <iostream>
using namespace std;

#define MAX 100

int graph[MAX][MAX];   // Adjacency matrix of the graph
int colorAssigned[MAX]; // colorAssigned[v] = color given to vertex v (1 to M)
int N;                  // Number of vertices
int M;                  // Maximum number of colors allowed

// Function to check if assigning 'color' to vertex 'v' is SAFE
// i.e., no adjacent vertex has the same color
bool isSafe(int vertex, int color) {
    // Check all adjacent vertices of 'vertex'
    for (int neighbor = 0; neighbor < N; neighbor++) {
        // If there's an edge AND the neighbor has the same color
        if (graph[vertex][neighbor] == 1 && colorAssigned[neighbor] == color) {
            return false;  // Color conflict!
        }
    }
    return true;  // Safe to use this color
}

// Recursive backtracking function to color the graph
// 'vertex' = current vertex we are trying to color
bool graphColoring(int vertex) {
    // Base case: All vertices are colored successfully
    if (vertex == N) {
        return true;
    }

    // Try each color from 1 to M
    for (int color = 1; color <= M; color++) {
        // Check if this color can be assigned to current vertex
        if (isSafe(vertex, color)) {
            colorAssigned[vertex] = color;  // Assign the color

            // Recursively color the next vertex
            if (graphColoring(vertex + 1)) {
                return true;  // Solution found!
            }

            // BACKTRACK: Remove color and try next one
            colorAssigned[vertex] = 0;
        }
    }

    // No color worked for this vertex, backtrack to previous vertex
    return false;
}

int main() {
    int numEdges;

    cout << "=== Graph Coloring Problem (Backtracking) ===" << endl;
    cout << "Enter number of vertices: ";
    cin >> N;

    cout << "Enter number of edges: ";
    cin >> numEdges;

    // Initialize graph and color array
    for (int i = 0; i < N; i++) {
        colorAssigned[i] = 0;  // 0 = not colored yet
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;
    }

    cout << "\nEnter edges (vertex u and vertex v):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        graph[u][v] = 1;  // Undirected edge
        graph[v][u] = 1;
    }

    cout << "Enter the maximum number of colors (M): ";
    cin >> M;

    // Try to color the graph starting from vertex 0
    if (graphColoring(0)) {
        cout << "\nGraph can be colored with " << M << " colors!" << endl;
        cout << "\nColor assignment for each vertex:" << endl;
        cout << "---------------------------------" << endl;
        for (int i = 0; i < N; i++) {
            cout << "Vertex " << i << " -> Color " << colorAssigned[i] << endl;
        }
    } else {
        cout << "\nGraph CANNOT be colored with " << M << " colors." << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(M^V) -> At each vertex, try M colors; V vertices total

Space Complexity: O(V) -> For colorAssigned array (+ O(V) call stack)

Key Concept: Backtracking assigns colors and backtracks when a color conflict is found.
             Chromatic number = minimum M for which a valid coloring exists.
============================
*/
