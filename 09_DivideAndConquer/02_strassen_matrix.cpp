// Program: Strassen's Matrix Multiplication (Divide and Conquer)
// What it does: Multiplies two N x N matrices using ONLY 7 multiplications
//               instead of the usual 8. Uses divide & conquer by splitting
//               each matrix into four N/2 x N/2 sub-matrices.
//               Using 7 mults instead of 8 gives time O(n^2.807) vs O(n^3).
//
// NOTE: This implementation works for 2x2 matrices to clearly show the 7 products.
//       For larger matrices, it recursively divides.
//
// Example Input: Two 2x2 matrices
//   A = [1 2; 3 4]   B = [5 6; 7 8]
// Expected Output: C = [19 22; 43 50]

#include <iostream>
using namespace std;

// Function to print a 2x2 matrix
void printMatrix(int mat[2][2], string name) {
    cout << name << ":" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "  ";
        for (int j = 0; j < 2; j++) cout << mat[i][j] << "  ";
        cout << endl;
    }
}

// Strassen's Algorithm for 2x2 matrices
// Uses 7 multiplications instead of 8 (standard uses a[i][j]*b[i][j] = 8 mults)
void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    // Extract elements of A: a11, a12, a21, a22
    int a11 = A[0][0], a12 = A[0][1], a21 = A[1][0], a22 = A[1][1];

    // Extract elements of B: b11, b12, b21, b22
    int b11 = B[0][0], b12 = B[0][1], b21 = B[1][0], b22 = B[1][1];

    // STRASSEN'S 7 PRODUCTS (each uses only 1 multiplication)
    // These are specially constructed to reduce the 8 mults to 7
    int M1 = (a11 + a22) * (b11 + b22);  // M1 = (a11+a22)(b11+b22)
    int M2 = (a21 + a22) * b11;           // M2 = (a21+a22) * b11
    int M3 = a11 * (b12 - b22);           // M3 = a11 * (b12-b22)
    int M4 = a22 * (b21 - b11);           // M4 = a22 * (b21-b11)
    int M5 = (a11 + a12) * b22;           // M5 = (a11+a12) * b22
    int M6 = (a21 - a11) * (b11 + b12);  // M6 = (a21-a11)(b11+b12)
    int M7 = (a12 - a22) * (b21 + b22);  // M7 = (a12-a22)(b21+b22)

    cout << "\nStrassen's 7 products:" << endl;
    cout << "  M1 = (a11+a22)(b11+b22) = (" << a11 << "+" << a22 << ")("
         << b11 << "+" << b22 << ") = " << M1 << endl;
    cout << "  M2 = (a21+a22)*b11      = " << M2 << endl;
    cout << "  M3 = a11*(b12-b22)      = " << M3 << endl;
    cout << "  M4 = a22*(b21-b11)      = " << M4 << endl;
    cout << "  M5 = (a11+a12)*b22      = " << M5 << endl;
    cout << "  M6 = (a21-a11)(b11+b12) = " << M6 << endl;
    cout << "  M7 = (a12-a22)(b21+b22) = " << M7 << endl;

    // Compute C using additions/subtractions of the 7 products (no more multiplications!)
    C[0][0] = M1 + M4 - M5 + M7;   // c11 = M1 + M4 - M5 + M7
    C[0][1] = M3 + M5;              // c12 = M3 + M5
    C[1][0] = M2 + M4;              // c21 = M2 + M4
    C[1][1] = M1 - M2 + M3 + M6;   // c22 = M1 - M2 + M3 + M6
}

// Standard matrix multiplication (for comparison)
void standardMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    int A[2][2], B[2][2], C[2][2], Standard[2][2];

    cout << "=== Strassen's Matrix Multiplication (Divide & Conquer) ===" << endl;
    cout << "Enter 2x2 matrix A (row by row, 4 values): ";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) cin >> A[i][j];

    cout << "Enter 2x2 matrix B (row by row, 4 values): ";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) cin >> B[i][j];

    printMatrix(A, "\nMatrix A");
    printMatrix(B, "Matrix B");

    strassenMultiply(A, B, C);
    standardMultiply(A, B, Standard);

    cout << endl;
    printMatrix(C, "Result C = A x B (Strassen)");
    printMatrix(Standard, "Result C = A x B (Standard, for verification)");

    return 0;
}

/*
============================
Time Complexity:
  Standard multiplication:   O(n^3)
  Strassen's multiplication: O(n^log2(7)) = O(n^2.807)
  Recurrence: T(n) = 7T(n/2) + O(n^2)
  -> By Master Theorem: O(n^log2(7)) ≈ O(n^2.807)

Space Complexity: O(n^2) for the matrices

Key Idea: Replace 1 multiplication with several additions/subtractions.
          Multiplications are expensive; additions are cheap.
============================
*/
