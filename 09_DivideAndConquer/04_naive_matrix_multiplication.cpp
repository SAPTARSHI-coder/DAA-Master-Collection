// Program: Naive / Standard Matrix Multiplication
// What it does: Multiplies two matrices A (m x p) and B (p x n) to produce
//               result matrix C (m x n) using the classic triple-loop method.
//               C[i][j] = sum over k of A[i][k] * B[k][j]
//
// Key idea: Row of A dotted with Column of B for each output cell.
//
// Example Input:
//   A = [1 2; 3 4]   (2x2)
//   B = [5 6; 7 8]   (2x2)
// Expected Output:
//   C = [19 22; 43 50]

#include <iostream>
using namespace std;

const int MAXN = 100;

// Print a matrix
void printMatrix(int mat[][MAXN], int rows, int cols, string name) {
    cout << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "  [ ";
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j];
            if (j < cols - 1) cout << "  ";
        }
        cout << " ]" << endl;
    }
    cout << endl;
}

// Standard (naive) matrix multiplication: C = A * B
// A is (rowsA x colsA), B is (colsA x colsB)
// Result C is (rowsA x colsB)
void naiveMultiply(int A[][MAXN], int B[][MAXN], int C[][MAXN],
                   int rowsA, int colsA, int colsB) {
    // Initialize result matrix to 0
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
            C[i][j] = 0;

    // Triple loop: i = row of A, j = col of B, k = shared inner dimension
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                // Each output element = dot product of row i of A and col j of B
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];
    int rowsA, colsA, rowsB, colsB;

    cout << "=== Standard (Naive) Matrix Multiplication ===" << endl;
    cout << "Enter dimensions of matrix A (rows cols): ";
    cin >> rowsA >> colsA;

    cout << "Enter dimensions of matrix B (rows cols): ";
    cin >> rowsB >> colsB;

    // Validate that multiplication is possible
    if (colsA != rowsB) {
        cout << "ERROR: Cannot multiply! Columns of A (" << colsA
             << ") must equal Rows of B (" << rowsB << ")." << endl;
        return 1;
    }

    cout << "Enter matrix A (" << rowsA << "x" << colsA << ") row by row:" << endl;
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++) {
            cout << "  A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }

    cout << "Enter matrix B (" << rowsB << "x" << colsB << ") row by row:" << endl;
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++) {
            cout << "  B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }

    printMatrix(A, rowsA, colsA, "\nMatrix A");
    printMatrix(B, rowsB, colsB, "Matrix B");

    naiveMultiply(A, B, C, rowsA, colsA, colsB);

    printMatrix(C, rowsA, colsB, "Result C = A x B");

    cout << "Total scalar multiplications performed: "
         << rowsA * colsA * colsB << endl;

    return 0;
}

/*
============================
Time Complexity:
  O(n^3) for square n x n matrices — three nested loops
  For rectangular matrices: O(m * p * n)
  where A is m x p and B is p x n.

Space Complexity: O(m*n) for the result matrix C

Limitation: Slow for large matrices.
            Strassen's algorithm improves this to O(n^2.807)
            using only 7 multiplications per recursive step.

Comparison:
  Naive          : O(n^3)       — 8 multiplications per 2x2 step
  Strassen's D&C : O(n^2.807)  — 7 multiplications per 2x2 step
  Matrix Chain (DP): NOT about HOW to multiply, but in WHAT ORDER to
                     parenthesize a chain of matrices to minimize cost.
============================
*/
