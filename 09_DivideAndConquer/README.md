# ✂️ Divide and Conquer Algorithms

> **Category:** Split → Solve → Combine  
> **Files:** 4 algorithms  

---

## 🎯 What is Divide and Conquer?

D&C splits a problem into **independent subproblems**, solves each recursively, then **combines** results.

**The 3-step template:**
1. **Divide:** Split input into smaller parts
2. **Conquer:** Solve each part recursively (base case when trivial)
3. **Combine:** Merge the subproblem solutions

## 🔑 When to Use D&C?

| Trigger | Algorithm |
|---------|-----------|
| Multiply two n×n matrices faster than O(n³) | Strassen's |
| Count inversions in array | Merge Sort D&C |
| Compute x^n in O(log n) | Binary Exponentiation |
| Find max and min simultaneously in 3n/2 comparisons | D&C Min-Max |
| Move n disks between pegs | Tower of Hanoi |

---

## 📋 Algorithm Details

### 1. Tower of Hanoi — `01_tower_of_hanoi.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(2^n) | **Space:** O(n) recursion stack
- **Intuition:** Move n disks from source to destination using one auxiliary peg. Rules: move one disk at a time, never place larger on smaller.
- **Recurrence:** `T(n) = 2T(n-1) + O(1)` → O(2^n) — minimum moves = 2^n - 1
- **Approach:** Move top n-1 disks to aux, move disk n to dest, move n-1 disks from aux to dest.
- **Common mistakes:** Wrong peg assignment in recursive calls.
- **Example:** 3 disks → 7 moves
- **Commit:** `feat: solve Tower of Hanoi recursively — O(2^n)`
- **Tags:** `#TowerOfHanoi #Recursion #DivideAndConquer #DSA`

---

### 2. Strassen's Matrix Multiply — `02_strassen_matrix.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(n^2.807) | **Space:** O(n²)
- **Intuition:** Standard 2×2 multiplication needs 8 multiplications. Strassen found 7 are enough using clever additions/subtractions, giving a better asymptotic complexity.
- **Recurrence:** `T(n) = 7T(n/2) + O(n²)` → O(n^log₂7) ≈ O(n^2.807) by Master Theorem
- **The 7 products (M1–M7):**
  ```
  M1 = (a11+a22)(b11+b22)
  M2 = (a21+a22) × b11
  M3 = a11 × (b12-b22)
  M4 = a22 × (b21-b11)
  M5 = (a11+a12) × b22
  M6 = (a21-a11)(b11+b12)
  M7 = (a12-a22)(b21+b22)
  ```
- **Result assembly:**
  ```
  C11 = M1+M4-M5+M7  |  C12 = M3+M5
  C21 = M2+M4        |  C22 = M1-M2+M3+M6
  ```
- **Common mistakes:** Confusing which M goes where in result assembly.
- **Commit:** `feat: implement Strassen matrix multiply with 7 products`
- **Tags:** `#Strassen #MatrixMultiplication #DivideAndConquer #DSA`

---

### 3. Find Max & Min (D&C) — `03_find_max_min.cpp`
- **Difficulty:** 🟢 Easy | **Time:** O(n) [exactly 3n/2 - 2 comparisons] | **Space:** O(log n)
- **Intuition:** Naive approach needs 2(n-1) comparisons. D&C pairs up elements, comparing within pairs first, then tracking pair-winners separately → only 3n/2 comparisons.
- **Approach:** Divide array in half. Find (max,min) of left and right. Combine: result max = max(left_max, right_max); result min = min(left_min, right_min).
- **Why better:** Reduces comparisons from ~2n to ~1.5n.
- **Commit:** `feat: find max and min with D&C in 3n/2 comparisons`
- **Tags:** `#MaxMin #DivideAndConquer #Optimization #DSA`

---

### 4. Standard Matrix Multiply — `04_naive_matrix_multiplication.cpp`
- **Difficulty:** 🟢 Easy | **Time:** O(m·p·n) | **Space:** O(m·n)
- **Intuition:** Each element C[i][j] = dot product of row i of A with column j of B. Triple nested loop.
- **Use:** Baseline for comparison against Strassen's.
- **Approach:** `C[i][j] += A[i][k] * B[k][j]` for all i, j, k.
- **Total multiplications for n×n:** n³ (vs Strassen's ~n^2.807)
- **Commit:** `feat: add naive matrix multiplication — O(n^3) baseline`
- **Tags:** `#MatrixMultiplication #Naive #LinearAlgebra #DSA`

---

## 📊 Matrix Multiplication Comparison

| Method | Time | Multiplications (2×2) | Key Idea |
|--------|------|-----------------------|---------|
| Naive | O(n³) | 8 | Triple loop |
| Strassen's | O(n^2.807) | 7 | Clever M1–M7 decomposition |
| MCM (DP) | O(n³) DP | — | Finds optimal *order*, doesn't multiply |

## 📐 Master Theorem Quick Reference

```
T(n) = aT(n/b) + O(n^k)

Tower of Hanoi:   T(n) = 2T(n-1) + O(1)      → O(2^n)
Merge Sort:       T(n) = 2T(n/2) + O(n)       → O(n log n)
Binary Search:    T(n) = T(n/2) + O(1)         → O(log n)
Strassen:         T(n) = 7T(n/2) + O(n²)       → O(n^2.807)
```

---

*[← Back to Master README](../README.md)*
