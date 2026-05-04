// ============================================================
// CASE STUDY 12: Shortest Path in a Maze (BFS on Grid)
// ============================================================
//
// PROBLEM STATEMENT:
//   Given a 2D maze grid where '0' = open and '1' = wall,
//   find the LENGTH OF THE SHORTEST PATH from the source cell
//   (0,0) to the destination cell (N-1, M-1).
//   You can move in all 4 directions (up, down, left, right).
//   Return -1 if no path exists.
//
// REAL-LIFE INTERPRETATION:
//   - GPS navigation on a city grid block map.
//   - Robot navigation around obstacles.
//   - Game pathfinding (avoiding walls/traps).
//   - Network routing through firewalls.
//
// ============================================================
// PATTERN RECOGNITION: WHY BFS (Not DFS, Not DP)?
// ============================================================
//
//  WHY NOT DFS?
//    DFS finds A path, but NOT necessarily the SHORTEST path.
//    DFS may go deep in one direction and miss a shorter path.
//
//  WHY NOT DP (only right/down)?
//    We can move in ALL 4 directions (including up/left).
//    This means there's no clear "direction" dependency for DP.
//
//  WHY BFS?
//    BFS explores cells LEVEL BY LEVEL (by distance from source).
//    The FIRST time BFS reaches the destination = the SHORTEST path.
//    This is because all edges in the maze have equal weight (1 step).
//
//  GOLDEN RULE:
//    "UNWEIGHTED graph + shortest path = BFS"
//    "WEIGHTED graph  + shortest path = Dijkstra or Bellman-Ford"
//
// CATEGORY: GRAPH TRAVERSAL - BFS (Breadth First Search)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Start with source (0,0) in queue, distance = 0.
//  Step 2: Process cells level by level.
//           For each cell, explore 4 neighbors.
//  Step 3: If a neighbor is open (0) and unvisited:
//             - Set its distance = current + 1
//             - Add to queue
//             - Mark as visited (don't revisit!)
//  Step 4: When destination is dequeued -> return its distance.
//
// ============================================================

#include <iostream>
using namespace std;

#define MAX 10

// Structure to represent a cell in the queue
struct Cell {
    int row;
    int col;
    int distance;  // Distance from source
};

int maze[MAX][MAX];
bool visited[MAX][MAX];

// 4 directions: Up, Down, Left, Right
int rowDir[] = {-1, 1,  0, 0};
int colDir[] = { 0, 0, -1, 1};

// BFS function to find shortest path
int shortestPathBFS(int rows, int cols, int sourceRow, int sourceCol,
                    int destRow, int destCol) {
    // Initialize visited array
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i][j] = false;

    // Simple queue implementation
    Cell queue[MAX * MAX];
    int qFront = 0, qRear = 0;

    // Start BFS from source
    queue[qRear++] = {sourceRow, sourceCol, 0};
    visited[sourceRow][sourceCol] = true;

    // Process queue level by level
    while (qFront < qRear) {
        // Dequeue the front cell
        Cell current = queue[qFront++];

        // Check if we reached the destination
        if (current.row == destRow && current.col == destCol) {
            return current.distance;
        }

        // Explore all 4 neighbors
        for (int dir = 0; dir < 4; dir++) {
            int newRow = current.row + rowDir[dir];
            int newCol = current.col + colDir[dir];

            // Check if neighbor is valid, open (0), and not visited
            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols &&
                maze[newRow][newCol] == 0 &&
                !visited[newRow][newCol]) {

                visited[newRow][newCol] = true;
                // Add neighbor with distance = current distance + 1
                queue[qRear++] = {newRow, newCol, current.distance + 1};
            }
        }
    }

    return -1;  // Destination not reachable
}

int main() {
    int rows, cols;

    cout << "======================================================" << endl;
    cout << " CASE STUDY 12: Shortest Path in Maze (BFS on Grid)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter maze dimensions (rows cols): ";
    cin >> rows >> cols;

    cout << "\nEnter the maze (0 = open, 1 = wall):" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++) cin >> maze[i][j];
    }

    cout << "\nMaze (0=open, 1=wall):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << maze[i][j] << " ";
        cout << endl;
    }

    int result = shortestPathBFS(rows, cols, 0, 0, rows - 1, cols - 1);

    if (result == -1)
        cout << "\nNo path exists from (0,0) to (" << rows-1 << "," << cols-1 << ")!" << endl;
    else
        cout << "\nShortest path length from (0,0) to (" << rows-1 << ","
             << cols-1 << "): " << result << " steps" << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(rows * cols) -> Each cell visited at most once

Space Complexity: O(rows * cols) -> For visited array and BFS queue

ALGORITHM SELECTION GUIDE:
  Shortest path in UNWEIGHTED graph/grid -> BFS
  Shortest path in WEIGHTED graph (no negative) -> Dijkstra
  Shortest path (negative weights allowed) -> Bellman-Ford
  Shortest path for ALL pairs -> Floyd-Warshall

SIMILAR PROBLEMS (Same BFS Shortest Path Pattern):
  1. 01 Matrix           -> Distance of each cell from nearest 0
  2. Shortest Path in Binary Matrix -> BFS on 8-directional grid
  3. Word Ladder         -> Min transformations from word A to word B
  4. Jump Game III       -> Reach 0-value cell from start
============================
*/
