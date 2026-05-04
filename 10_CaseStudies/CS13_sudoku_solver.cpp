// ============================================================
// CASE STUDY 13: Sudoku Solver
// ============================================================
//
// PROBLEM STATEMENT:
//   Given a partially filled 9x9 Sudoku board, find a solution that:
//   - Each row contains digits 1-9 with no repetition.
//   - Each column contains digits 1-9 with no repetition.
//   - Each of the nine 3x3 sub-boxes contains digits 1-9 with no repetition.
//   Empty cells are represented by '0'.
//
// REAL-LIFE INTERPRETATION:
//   - Puzzle solving (the famous Sudoku newspaper puzzle!).
//   - Constraint satisfaction: seat assignment, class scheduling.
//   - Compiler checking: variable constraint propagation.
//
// ============================================================
// PATTERN RECOGNITION: WHY BACKTRACKING?
// ============================================================
//
//  KEY SIGNALS FOR BACKTRACKING:
//    1. "Fill in / complete" assignments
//    2. "Subject to constraints" -> not all assignments are valid
//    3. "Find a valid arrangement" (not min/max -> just VALID)
//    4. Must TRY all possibilities and ABANDON invalid paths early
//
//  APPROACH:
//    Find the next empty cell.
//    Try placing 1 through 9 in that cell.
//    Check if the placement is VALID (no row/col/box conflict).
//    If valid: recursively try to solve the rest.
//    If recursion fails: BACKTRACK (remove the number and try next).
//    If no number works: return false (this path is invalid).
//
//  WHY NOT GREEDY?
//    Greedy would pick one number and commit -> may fail with no way back.
//  WHY NOT DP?
//    Sudoku has no overlapping subproblems in the traditional sense.
//    State space is too complex for standard DP.
//
// CATEGORY: BACKTRACKING (Constraint Satisfaction Problem)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  Step 1: Find the next empty cell (value = 0).
//  Step 2: If no empty cell found -> Sudoku is SOLVED! Return true.
//  Step 3: Try digits 1 to 9 in the empty cell.
//  Step 4: For each digit, check if it's SAFE:
//            - Not in same row
//            - Not in same column
//            - Not in same 3x3 box
//  Step 5: If safe, PLACE the digit and RECURSE.
//  Step 6: If recursion returns TRUE -> solution found, propagate true.
//  Step 7: If recursion returns FALSE -> BACKTRACK (reset cell to 0), try next digit.
//
// ============================================================

#include <iostream>
using namespace std;

int board[9][9];  // 9x9 Sudoku board (0 = empty)

// Function to display the board
void displayBoard() {
    cout << "\n+-------+-------+-------+" << endl;
    for (int row = 0; row < 9; row++) {
        if (row == 3 || row == 6) cout << "+-------+-------+-------+" << endl;
        cout << "| ";
        for (int col = 0; col < 9; col++) {
            if (col == 3 || col == 6) cout << "| ";
            if (board[row][col] == 0) cout << ". ";
            else cout << board[row][col] << " ";
        }
        cout << "|" << endl;
    }
    cout << "+-------+-------+-------+" << endl;
}

// Function to check if placing 'num' at (row, col) is SAFE
bool isSafe(int row, int col, int num) {
    // Check if 'num' already exists in the same ROW
    for (int c = 0; c < 9; c++) {
        if (board[row][c] == num) return false;
    }

    // Check if 'num' already exists in the same COLUMN
    for (int r = 0; r < 9; r++) {
        if (board[r][col] == num) return false;
    }

    // Check if 'num' already exists in the same 3x3 BOX
    // Find the top-left corner of the 3x3 box this cell belongs to
    int boxStartRow = row - (row % 3);  // Round down to nearest multiple of 3
    int boxStartCol = col - (col % 3);

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[boxStartRow + r][boxStartCol + c] == num) return false;
        }
    }

    return true;  // Safe to place num here
}

// Main backtracking function to solve Sudoku
bool solveSudoku() {
    // Step 1: Find the next empty cell
    int emptyRow = -1, emptyCol = -1;
    bool found = false;

    for (int row = 0; row < 9 && !found; row++) {
        for (int col = 0; col < 9 && !found; col++) {
            if (board[row][col] == 0) {
                emptyRow = row;
                emptyCol = col;
                found = true;  // Found an empty cell
            }
        }
    }

    // Step 2: No empty cell found -> Board is complete!
    if (!found) return true;

    // Step 3: Try digits 1 to 9 in this empty cell
    for (int num = 1; num <= 9; num++) {

        // Step 4: Check if this number can be placed here
        if (isSafe(emptyRow, emptyCol, num)) {

            // Step 5: Place the number (make a choice)
            board[emptyRow][emptyCol] = num;

            // Step 6: Recursively try to solve the rest
            if (solveSudoku()) {
                return true;  // Solution found! Propagate success
            }

            // Step 7: BACKTRACK - placement didn't work, remove the number
            board[emptyRow][emptyCol] = 0;
        }
    }

    // No digit worked for this cell -> signal failure to previous call
    return false;
}

int main() {
    cout << "======================================================" << endl;
    cout << " CASE STUDY 13: Sudoku Solver (Backtracking)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter the 9x9 Sudoku board row by row:" << endl;
    cout << "(Use 0 for empty cells)" << endl;

    for (int i = 0; i < 9; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 9; j++) cin >> board[i][j];
    }

    cout << "\nInitial Board:";
    displayBoard();

    if (solveSudoku()) {
        cout << "\nSUDOKU SOLVED!";
        displayBoard();
    } else {
        cout << "\nNo solution exists for this Sudoku!" << endl;
    }

    return 0;
}

/*
============================
Time Complexity:
  O(9^(empty cells)) -> For each empty cell, try 9 digits
  With constraint pruning, much faster in practice

Space Complexity: O(81) = O(1) for board + O(81) for recursion stack

SIMILAR PROBLEMS (Same Backtracking Constraint Satisfaction Pattern):
  1. N-Queens            -> Place N queens with no conflict
  2. Graph Coloring      -> Color vertices with M colors (no adjacent same color)
  3. Word Search         -> Find word in 2D character grid
  4. Crossword Puzzle    -> Fill words satisfying crossing constraints
  5. Map Coloring        -> Color a map so no bordering regions share a color

BACKTRACKING = Try -> Check -> Recurse -> UNDO if failed
============================
*/
