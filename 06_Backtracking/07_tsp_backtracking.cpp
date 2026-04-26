// Program: Travelling Salesman Problem (Backtracking)
// What it does: Given a set of cities and distances between them,
//               find the SHORTEST POSSIBLE ROUTE that:
//               - Visits EVERY city EXACTLY ONCE
//               - Returns back to the STARTING city
//               This is the classic TSP (NP-Hard problem).
//               Uses BACKTRACKING to explore all permutations and
//               keeps track of the MINIMUM COST found.
//
// Example Input: 4 cities, cost matrix (0=no direct path)
// Expected Output: Minimum cost tour and the path taken

#include <iostream>
#include <climits>
using namespace std;

#define MAX 10

int costMatrix[MAX][MAX];  // Cost between each pair of cities
int visited[MAX];          // visited[i]=1 if city i is in current path
int N;                     // Total number of cities

int minCost   = INT_MAX;   // Minimum tour cost found so far
int bestPath[MAX];         // The best path found
int currentPath[MAX];      // Current path being explored

// Recursive backtracking function to explore all tours
// currentCity = the city we are currently at
// citiesVisited = how many cities we've visited so far (including start)
// currentCost   = total cost of current partial tour
void tspBacktrack(int currentCity, int citiesVisited, int currentCost) {
    // BASE CASE: All cities visited -> try to return to starting city (city 0)
    if (citiesVisited == N) {
        // Cost to return to city 0
        int returnCost = costMatrix[currentCity][0];

        if (returnCost != 0) {  // If a return path exists
            int totalCost = currentCost + returnCost;

            if (totalCost < minCost) {
                minCost = totalCost;    // Update minimum cost

                // Save the best path found so far
                for (int i = 0; i < N; i++) bestPath[i] = currentPath[i];

                cout << "  New best tour found! Cost = " << totalCost << " | Path: ";
                for (int i = 0; i < N; i++) cout << currentPath[i] << " -> ";
                cout << "0" << endl;
            }
        }
        return;
    }

    // PRUNING: If current cost already >= minCost, stop exploring this path
    if (currentCost >= minCost) return;

    // Try visiting each unvisited city from current city
    for (int nextCity = 1; nextCity < N; nextCity++) {
        // Check: is nextCity unvisited AND is there a direct path to it?
        if (!visited[nextCity] && costMatrix[currentCity][nextCity] != 0) {

            // Make choice: visit nextCity
            visited[nextCity]         = 1;
            currentPath[citiesVisited] = nextCity;

            // Recurse: add travel cost to nextCity
            tspBacktrack(nextCity, citiesVisited + 1,
                         currentCost + costMatrix[currentCity][nextCity]);

            // BACKTRACK: undo visiting nextCity
            visited[nextCity] = 0;
        }
    }
}

int main() {
    cout << "=== Travelling Salesman Problem (Backtracking) ===" << endl;
    cout << "Enter number of cities: ";
    cin >> N;

    cout << "\nEnter the cost matrix (" << N << "x" << N
         << ", use 0 if no direct path):" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < N; j++) cin >> costMatrix[i][j];
    }

    // Initialize: start from city 0, mark it as visited
    for (int i = 0; i < N; i++) visited[i] = 0;
    visited[0] = 1;           // Start at city 0
    currentPath[0] = 0;       // First city in path is city 0

    cout << "\nExploring all tours starting from City 0..." << endl;

    tspBacktrack(0, 1, 0);  // Start at city 0, 1 city visited, 0 cost so far

    if (minCost == INT_MAX) {
        cout << "\nNo valid Hamiltonian tour exists!" << endl;
    } else {
        cout << "\n============================================" << endl;
        cout << "OPTIMAL TOUR COST: " << minCost << endl;
        cout << "OPTIMAL PATH: ";
        for (int i = 0; i < N; i++) cout << bestPath[i] << " -> ";
        cout << "0 (back to start)" << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(N!) -> Tries all permutations of N cities

Space Complexity: O(N) -> For path and visited arrays + recursion stack

TSP is NP-HARD: No known polynomial-time algorithm exists.
Exact solutions:
  Backtracking:        O(N!)    -> Works for small N (up to ~15)
  DP (Bitmask TSP):    O(N^2 * 2^N) -> Works for N up to ~20

For LARGE N: Use approximation algorithms (Greedy nearest neighbour = O(N^2))
============================
*/
