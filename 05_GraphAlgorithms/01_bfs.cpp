// Program: BFS - Breadth First Search (Graph Traversal)
// What it does: Explores all vertices of a graph level by level.
//               Starts from source, visits all neighbors first (same level),
//               then moves to the next level. Uses a QUEUE.
//               Used for finding shortest path in unweighted graphs.
//
// Example Input:
//   Graph with 6 vertices:
//   Edges: 0-1, 0-2, 1-3, 1-4, 2-5
//   Start vertex: 0
// Expected Output: BFS order: 0 1 2 3 4 5

#include <iostream>
using namespace std;

#define MAX_VERTICES 100

// Adjacency Matrix representation of graph
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

// Simple Queue implementation (using array)
int queue[MAX_VERTICES];
int front = -1, rear = -1;

// Check if queue is empty
bool isQueueEmpty() {
    return front == -1 || front > rear;
}

// Add element to queue
void enqueue(int vertex) {
    if (front == -1) front = 0;  // First element
    queue[++rear] = vertex;
}

// Remove element from queue and return it
int dequeue() {
    return queue[front++];
}

// BFS function starting from source vertex
void bfs(int numVertices, int source) {
    // Mark source as visited and add to queue
    visited[source] = true;
    enqueue(source);

    cout << "\nBFS Traversal starting from vertex " << source << ": ";

    // Continue until queue is empty
    while (!isQueueEmpty()) {
        // Dequeue the front vertex
        int currentVertex = dequeue();
        cout << currentVertex << " ";

        // Visit all neighbors of the current vertex
        for (int neighbor = 0; neighbor < numVertices; neighbor++) {
            // Check if there's an edge and neighbor is not visited
            if (graph[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = true;
                enqueue(neighbor);  // Add neighbor to queue for later processing
            }
        }
    }
    cout << endl;
}

int main() {
    int numVertices, numEdges;

    cout << "=== BFS - Breadth First Search ===" << endl;
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
    cout << "\nEnter starting vertex for BFS: ";
    cin >> source;

    // Perform BFS
    bfs(numVertices, source);

    return 0;
}

/*
============================
Time Complexity:
  O(V^2) with Adjacency Matrix (V = vertices)
  O(V + E) with Adjacency List  (E = edges)

Space Complexity: O(V) -> For visited array and queue

Use: Shortest path in unweighted graphs, level-order traversal.
============================
*/
