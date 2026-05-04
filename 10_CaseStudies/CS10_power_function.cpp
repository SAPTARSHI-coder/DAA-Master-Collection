// ============================================================
// CASE STUDY 10: Fast Power Function (x raised to n)
// ============================================================
//
// PROBLEM STATEMENT:
//   Compute x^n (x raised to the power n) efficiently.
//   Naive: multiply x by itself n times -> O(n).
//   Challenge: Do it in O(log n) using Divide & Conquer.
//
// REAL-LIFE INTERPRETATION:
//   - Cryptography: RSA encryption uses modular exponentiation (huge exponents).
//   - Matrix exponentiation: Computing Fibonacci(n) in O(log n).
//   - Game engines: Computing transformations repeatedly.
//   - Financial: Compound interest = principal * (1 + rate)^years.
//
// ============================================================
// PATTERN RECOGNITION: WHY DIVIDE AND CONQUER?
// ============================================================
//
//  KEY INSIGHT:
//    x^n = x^(n/2) * x^(n/2)    [if n is EVEN]
//    x^n = x * x^(n-1)          [if n is ODD]
//
//  Why this helps:
//    x^8 = (x^4)^2
//    x^4 = (x^2)^2
//    x^2 = (x^1)^2
//    Instead of 8 multiplications, we only do 3!
//
//  Recurrence: T(n) = T(n/2) + O(1)
//  Solution:   T(n) = O(log n)    <-- Master Theorem Case 2
//
//  HOW TO SPOT THIS PATTERN:
//    "A problem where the input can be HALVED at each step"
//    "Subproblem reuses the result of a smaller version of itself"
//    -> Divide and Conquer / Binary Exponentiation
//
// CATEGORY: DIVIDE AND CONQUER (Binary Exponentiation)
//
// ============================================================
// STEP-BY-STEP THINKING:
// ============================================================
//
//  computePower(x, n):
//    Base case: if n == 0, return 1 (anything^0 = 1)
//    If n is EVEN: return computePower(x, n/2) * computePower(x, n/2)
//                         [Better: half = computePower(x, n/2); return half*half]
//    If n is ODD:  return x * computePower(x, n-1)
//
//  IMPORTANT: Don't compute computePower(x, n/2) TWICE!
//             Store it in a variable and reuse. Avoids exponential time.
//
// ============================================================

#include <iostream>
#include <cmath>
using namespace std;

// Recursive function: compute x^n using Divide and Conquer
// Returns x raised to the power n
double fastPower(double base, int exponent) {
    // Base case: anything raised to 0 is 1
    if (exponent == 0) {
        return 1.0;
    }

    // Handle negative exponents: x^(-n) = 1 / x^n
    if (exponent < 0) {
        return 1.0 / fastPower(base, -exponent);
    }

    // If exponent is EVEN: x^n = (x^(n/2))^2
    if (exponent % 2 == 0) {
        double half = fastPower(base, exponent / 2);  // Compute ONCE, reuse!
        return half * half;                            // Square it
    }

    // If exponent is ODD: x^n = x * x^(n-1)
    else {
        return base * fastPower(base, exponent - 1);
    }
}

// Iterative version (Binary Exponentiation) - even more efficient
double fastPowerIterative(double base, int exponent) {
    double result = 1.0;
    bool isNegative = false;

    if (exponent < 0) {
        isNegative = true;
        exponent   = -exponent;
    }

    // Process each bit of exponent from LSB to MSB
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            // If current bit is 1, multiply result by current base
            result *= base;
        }
        base     *= base;  // Square the base for next bit
        exponent /= 2;     // Move to next bit
    }

    return isNegative ? 1.0 / result : result;
}

int main() {
    double base;
    int exponent;

    cout << "======================================================" << endl;
    cout << " CASE STUDY 10: Fast Power - x^n (Divide & Conquer)" << endl;
    cout << "======================================================" << endl;
    cout << "\nEnter the base (x): ";
    cin >> base;
    cout << "Enter the exponent (n): ";
    cin >> exponent;

    double resultRecursive  = fastPower(base, exponent);
    double resultIterative  = fastPowerIterative(base, exponent);
    double resultLibrary    = pow(base, exponent);  // For verification

    cout << "\n--- Results ---" << endl;
    cout << base << "^" << exponent << " = " << resultRecursive << " (Recursive D&C)" << endl;
    cout << base << "^" << exponent << " = " << resultIterative << " (Iterative)" << endl;
    cout << base << "^" << exponent << " = " << resultLibrary   << " (Library pow - for verification)" << endl;

    cout << "\n--- Step Trace for " << base << "^" << exponent << " ---" << endl;
    cout << "(Each level halves the exponent -> O(log n) steps)" << endl;
    int exp = (exponent < 0) ? -exponent : exponent;
    int stepCount = 0;
    while (exp > 0) { stepCount++; exp /= 2; }
    cout << "Number of recursive calls = approximately " << stepCount * 2 << endl;
    cout << "Naive approach would need " << ((exponent < 0) ? -exponent : exponent) << " multiplications" << endl;

    return 0;
}

/*
============================
Time Complexity:
  Recursive:  O(log n)  -> Exponent is halved each call
  Iterative:  O(log n)  -> Process each bit of exponent

Space Complexity:
  Recursive:  O(log n)  -> Recursive call stack depth
  Iterative:  O(1)      -> No extra space

SIMILAR PROBLEMS (Same Divide & Conquer / Halving Pattern):
  1. Fibonacci in O(log n)        -> Matrix exponentiation using fast power
  2. Modular Exponentiation       -> (x^n) mod m -> Used in RSA cryptography
  3. Fast Multiplication (Karatsuba) -> Multiply two n-digit numbers in O(n^1.585)
  4. Binary Search                -> Also halves search space each step

MASTER THEOREM (For Viva):
  T(n) = T(n/2) + O(1) -> O(log n)  <- Fast Power recurrence
  T(n) = 2T(n/2) + O(n) -> O(n log n) <- Merge Sort recurrence
============================
*/
