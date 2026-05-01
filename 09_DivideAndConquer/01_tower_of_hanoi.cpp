// Program: Tower of Hanoi (Divide and Conquer / Recursion)
// What it does: Move N disks from source peg to destination peg using
//               a helper (auxiliary) peg. Rules:
//               1. Only one disk can be moved at a time.
//               2. A disk can only be placed on a LARGER disk or empty peg.
//
// Example Input: N = 3 disks
// Expected Output:
//   Move disk 1 from A to C
//   Move disk 2 from A to B
//   Move disk 1 from C to B
//   Move disk 3 from A to C
//   Move disk 1 from B to A
//   Move disk 2 from B to C
//   Move disk 1 from A to C

#include <iostream>
using namespace std;

int moveCount = 0;  // Count total moves

// Recursive function for Tower of Hanoi
// n      = number of disks to move
// source = the peg where disks currently are
// target = the peg where we want to move them
// helper = the auxiliary peg used for temporary storage
void hanoi(int n, char source, char target, char helper) {
    // Base case: If only 1 disk, move directly from source to target
    if (n == 1) {
        moveCount++;
        cout << "Move " << moveCount << ": Move disk 1 from " << source << " to " << target << endl;
        return;
    }

    // Step 1: Move top (n-1) disks from source to helper (using target as helper)
    hanoi(n - 1, source, helper, target);

    // Step 2: Move the largest disk (disk n) from source to target
    moveCount++;
    cout << "Move " << moveCount << ": Move disk " << n << " from " << source << " to " << target << endl;

    // Step 3: Move (n-1) disks from helper to target (using source as helper)
    hanoi(n - 1, helper, target, source);
}

int main() {
    int n;

    cout << "=== Tower of Hanoi (Divide and Conquer) ===" << endl;
    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "\nStep-by-step moves (Pegs: A=Source, B=Helper, C=Target):" << endl;
    cout << "-------------------------------------------------------------" << endl;

    // Solve Tower of Hanoi: move n disks from A to C using B
    hanoi(n, 'A', 'C', 'B');

    cout << "\nTotal moves required: " << moveCount << endl;
    cout << "Formula: 2^N - 1 = " << (1 << n) - 1 << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(2^n) -> Each call makes 2 recursive calls; n levels deep
  Total moves = 2^n - 1

Space Complexity: O(n) -> Recursive call stack depth is n

Key Insight: Divide and Conquer - break the problem into smaller versions of itself.
             For n disks: Move(n-1) + Move(1) + Move(n-1) = 2*Move(n-1) + 1
============================
*/
