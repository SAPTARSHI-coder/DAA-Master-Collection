// ============================================================
// CASE STUDY 11: Number of Islands
// ============================================================
//
// PROBLEM STATEMENT:
//   Given a 2D grid of '1's (land) and '0's (water), count the
//   number of ISLANDS. An island is a group of '1's connected
//   horizontally or vertically (not diagonally).
//
// REAL-LIFE INTERPRETATION:
//   - Satellite maps: count distinct land masses in ocean.
//   - Circuit board: count connected components in a circuit.
//   - Social networks: count isolated friend groups.
//   - Pandemic model: count isolated infection clusters.
//
// ============================================================
// PATTERN RECOGNITION: WHY BFS / DFS?
// ============================================================
//
//  KEY INSIGHT: This is a CONNECTED COMPONENTS problem on a 2D grid.
//    - The grid is just a GRAPH where each cell is a vertex.
//    - Edges exist between adjacent land cells (up, down, left, right).
//    - Counting islands = counting connected components in this graph.
//
//  APPROACH: Start from any unvisited '1' cell, do a DFS/BFS to visit
//            ALL connected '1' cells (mark them visited), then count
//            how many times we performed this DFS/BFS.
//
//  WHY DFS?
//    - DFS naturally explores all connected cells recursively.
//    - Simple to implement (just 4 recursive calls for 4 directions).
//
//  WHY NOT DP or GREEDY?
//    - No optimization needed (just counting distinct groups).
//    - No "best choice" to make; just systematic exploration.
//
// CATEGORY: GRAPH TRAVERSAL (DFS on 2D Grid = BFS works too)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Go through each cell in the grid.
//  Step 2: If current cell is '1' (land) AND not visited:
//            - Increment island count
//            - Do DFS from this cell to mark ALL connected land as visited
//  Step 3: DFS explores all 4 neighbors (up, down, left, right).
//          If a neighbor is a valid '1', recursively call DFS on it.
//  Step 4: Return total island count.
//
// Example:
//   1 1 0 0 0
//   1 1 0 0 0
//   0 0 1 0 0
//   0 0 0 1 1
//   -> 3 islands
//
// ============================================================

#include <iostream>
using namespace std;

#define MAX 10

char grid[MAX][MAX];    // The 2D grid
bool visited[MAX][MAX]; // Track visited cells
int rows, cols;

// 4 directions: Up, Down, Left, Right
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = { 0, 0,-1, 1};

// DFS function to visit all connected land cells
void dfsIsland(int row, int col) {
    // Mark current cell as visited
    visited[row][col] = true;

    // Explore all 4 neighboring directions
    for (int dir = 0; dir < 4; dir++) {
        int newRow = row + rowDir[dir];
        int newCol = col + colDir[dir];

        // Check if the neighbor is WITHIN BOUNDS, is LAND ('1'), and NOT VISITED
        if (newRow >= 0 && newRow < rows &&
            newCol >= 0 && newCol < cols &&
            grid[newRow][newCol] == '1' &&
            !visited[newRow][newCol]) {

            // Recursively visit this connected land cell
            dfsIsland(newRow, newCol);
        }
    }
}

// Main function to count islands
int countIslands() {
    // Initialize all cells as not visited
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i][j] = false;

    int islandCount = 0;

    // Go through each cell in the grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // If this is an unvisited land cell -> new island found!
            if (grid[i][j] == '1' && !visited[i][j]) {
                islandCount++;                  // Found a new island
                dfsIsland(i, j);               // Mark all connected land as visited
            }
        }
    }

    return islandCount;
}

int main() {
    cout << "======================================================" << endl;
    cout << " CASE STUDY 11: Number of Islands (Graph DFS on Grid)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter grid dimensions (rows cols): ";
    cin >> rows >> cols;

    cout << "\nEnter the grid row by row (use '1' for land, '0' for water):" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\nGrid:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << grid[i][j] << " ";
        cout << endl;
    }

    int result = countIslands();

    cout << "\nNumber of Islands: " << result << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(rows * cols) -> Each cell is visited at most once

Space Complexity: O(rows * cols) -> For the visited array and DFS call stack

SIMILAR PROBLEMS (Same "Connected Components on Grid" Pattern):
  1. Max Area of Island    -> Find island with maximum area
  2. Flood Fill            -> Fill connected region with new color (MS Paint)
  3. Surrounded Regions    -> Find 'O's enclosed by 'X's
  4. Number of Provinces   -> Same but with adjacency matrix, not grid

KEY INSIGHT FOR VIVA:
  "2D Grid + Connected Regions + Visit All Connected = DFS/BFS"
  "Count how many times you initiate DFS = count connected components"
============================
*/
