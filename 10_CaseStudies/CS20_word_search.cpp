// ============================================================
// CASE STUDY 20: Word Search in 2D Grid
// ============================================================
//
// PROBLEM STATEMENT:
//   Given an M x N grid of characters and a word, return TRUE if
//   the word exists in the grid. The word can be formed by
//   sequentially ADJACENT cells (up, down, left, right).
//   The SAME CELL may not be used more than once in forming the word.
//
// REAL-LIFE INTERPRETATION:
//   - Word Search puzzle (newspaper games).
//   - Spell checking in a scrambled letter grid.
//   - DNA analysis: finding a gene sequence in a 2D matrix representation.
//
// ============================================================
// PATTERN RECOGNITION: WHY BACKTRACKING?
// ============================================================
//
//  KEY SIGNALS:
//    1. We need to SEARCH for a sequence that satisfies constraints.
//    2. We must EXPLORE multiple paths (all 4 directions).
//    3. If a path fails, we must UNDO our choices (mark cell unvisited).
//    4. No global optimum -> just FIND a valid path.
//
//  APPROACH:
//    For every cell:
//      If it matches the first character of the word:
//        Try to match the rest of the word from this cell (DFS).
//        At each step, mark cell as visited (can't reuse).
//        Try all 4 directions for next character.
//        If we reach the end of the word -> FOUND!
//        If dead end -> BACKTRACK (unmark cell, try another direction).
//
//  WHY NOT BFS?
//    BFS explores ALL cells at each distance level -> can't enforce "same path".
//    Backtracking maintains a single path and undoes choices.
//
// CATEGORY: BACKTRACKING (DFS on 2D Grid with path tracking)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Loop through every cell in grid.
//  If grid[i][j] == word[0]:
//    Call backtrack(i, j, 0)  // Try matching word starting here
//
//  backtrack(row, col, wordIndex):
//    If wordIndex == word.length: return TRUE (all chars matched!)
//    If out of bounds OR cell is visited OR grid[row][col] != word[wordIndex]: return FALSE
//
//    Mark cell as visited.
//    Try all 4 directions: if any returns TRUE -> propagate TRUE.
//    UNMARK cell (backtrack).
//    Return FALSE if all 4 directions fail.
//
// ============================================================

#include <iostream>
#include <string>
using namespace std;

#define MAX 10

char grid[MAX][MAX];   // The 2D character grid
bool visited[MAX][MAX]; // Track cells used in current path
int rows, cols;

// 4 directions: Up, Down, Left, Right
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = { 0, 0,-1, 1};

// Backtracking function
// row, col     = current cell
// word         = the word we're searching for
// wordIndex    = how many characters of word we've matched so far
bool backtrack(int row, int col, string word, int wordIndex) {
    // BASE CASE: All characters matched!
    if (wordIndex == (int)word.length()) {
        return true;
    }

    // Check bounds, visited, and character match
    if (row < 0 || row >= rows ||
        col < 0 || col >= cols ||
        visited[row][col] ||
        grid[row][col] != word[wordIndex]) {
        return false;
    }

    // Mark current cell as part of current path
    visited[row][col] = true;

    // Try all 4 directions to match the NEXT character
    for (int dir = 0; dir < 4; dir++) {
        int newRow = row + rowDir[dir];
        int newCol = col + colDir[dir];

        if (backtrack(newRow, newCol, word, wordIndex + 1)) {
            visited[row][col] = false;  // Clean up before returning
            return true;  // Word found!
        }
    }

    // BACKTRACK: None of the 4 directions worked. Unmark this cell.
    visited[row][col] = false;

    return false;  // Word not found starting with this path
}

// Main function to search for word in grid
bool wordSearch(string word) {
    // Initialize visited
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i][j] = false;

    // Try every cell as a starting point for the first character
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // If first character matches, try from this cell
            if (grid[i][j] == word[0]) {
                if (backtrack(i, j, word, 0)) {
                    cout << "  Word starts at cell (" << i << ", " << j << ")" << endl;
                    return true;
                }
            }
        }
    }

    return false;  // Word not found anywhere
}

int main() {
    cout << "======================================================" << endl;
    cout << " CASE STUDY 20: Word Search in Grid (Backtracking)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter grid dimensions (rows cols): ";
    cin >> rows >> cols;

    cout << "\nEnter the character grid row by row:" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << " (" << cols << " chars): ";
        for (int j = 0; j < cols; j++) cin >> grid[i][j];
    }

    cout << "\nGrid:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << grid[i][j] << " ";
        cout << endl;
    }

    string word;
    cout << "\nEnter the word to search: ";
    cin >> word;

    cout << "\nSearching for \"" << word << "\"..." << endl;

    if (wordSearch(word))
        cout << "Result: Word \"" << word << "\" EXISTS in the grid!" << endl;
    else
        cout << "Result: Word \"" << word << "\" does NOT exist in the grid." << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(M * N * 4^L) -> M*N start positions, 4 directions, L = word length
  With effective pruning, much faster in practice

Space Complexity: O(L) -> Recursion call stack depth = word length

SIMILAR PROBLEMS (Same Backtracking with Path Tracking Pattern):
  1. Knight's Tour           -> Find a path where knight visits all squares
  2. Hamiltonian Path        -> Visit all vertices exactly once in graph
  3. Boggle Game             -> Find all words in a grid from a dictionary
  4. Rat in a Maze           -> Find path from (0,0) to (N,N) avoiding walls

BACKTRACKING TEMPLATE:
  1. Check invalid state -> return False
  2. Check goal state -> return True
  3. Make a choice (mark visited)
  4. Recurse on next states
  5. Undo choice (unmark visited)
  6. Return False if no choice worked
============================
*/
