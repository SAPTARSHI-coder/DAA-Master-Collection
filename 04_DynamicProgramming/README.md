# 🧮 Dynamic Programming

> **Category:** Optimal Substructure + Overlapping Subproblems  
> **Files:** 14 algorithms  

---

## 🎯 What is Dynamic Programming?

DP solves problems by **breaking them into overlapping subproblems**, solving each once, and **storing the result** to avoid recomputation.

**Two implementations:**
- **Top-Down (Memoization):** Recursive + cache results
- **Bottom-Up (Tabulation):** Iterative, fill a table

## 🔑 When to Use DP?

Use DP when you see:
- "Minimum / Maximum" of something
- "Count the number of ways"
- "Can we achieve...?" (Yes/No)
- "Longest / Shortest subsequence / substring"
- The problem has **overlapping subproblems** (same sub-calculation appears multiple times)

---

## 📋 Algorithm Details

### 1. 0/1 Knapsack (Tabulation) — `01_knapsack_01.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n·W) | **Space:** O(n·W)
- **Intuition:** Fill a bag of capacity W with items. Each item: take it or leave it (no fractions). Maximise total value.
- **Pattern:** "Select subset with constraint, maximise value, no splitting"
- **Approach:** `dp[i][w] = max(dp[i-1][w], val[i] + dp[i-1][w-wt[i]])`
- **Common mistakes:** Confusing with Fractional Knapsack (which uses Greedy).
- **Commit:** `feat: solve 0/1 knapsack using bottom-up DP tabulation`
- **Tags:** `#Knapsack #DP #DynamicProgramming #DSA`

---

### 2. Longest Common Subsequence — `02_lcs.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(m·n) | **Space:** O(m·n)
- **Intuition:** Find the longest sequence of characters that appears in both strings (not necessarily contiguous).
- **Pattern:** "Longest subsequence involving two strings"
- **Approach:** If `s1[i]==s2[j]`: `dp[i][j] = 1 + dp[i-1][j-1]` else `max(dp[i-1][j], dp[i][j-1])`
- **Common mistakes:** Confusing subsequence (non-contiguous) with substring (contiguous).
- **Commit:** `feat: implement LCS with 2D DP table`
- **Tags:** `#LCS #DynamicProgramming #StringDP #DSA`

---

### 3. Matrix Chain Multiplication — `03_matrix_chain_multiplication.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(n³) | **Space:** O(n²)
- **Intuition:** Given matrices A×B×C, the *order* of multiplication matters for cost. Find the optimal parenthesization.
- **Pattern:** "Optimal order of operations on a sequence"
- **Approach:** `dp[i][j] = min over k of (dp[i][k] + dp[k+1][j] + dim[i]*dim[k+1]*dim[j+1])`
- **Key insight:** MCM does **not** multiply matrices — it finds the cheapest *order* to do so.
- **Commit:** `feat: implement matrix chain multiplication with interval DP`
- **Tags:** `#MCM #IntervalDP #MatrixChain #DSA`

---

### 4. Coin Change (Min Coins) — `04_coin_change.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n·amount) | **Space:** O(amount)
- **Intuition:** Given coin denominations, find the minimum number of coins to make a target amount.
- **Pattern:** "Minimum items to reach target" — unbounded use of items.
- **Approach:** `dp[i] = min over all coins c where c<=i of (1 + dp[i-c])`
- **Commit:** `feat: solve coin change (min coins) with 1D DP`
- **Tags:** `#CoinChange #UnboundedKnapsack #DP #DSA`

---

### 5. Longest Increasing Subsequence — `05_lis.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n²) | **Space:** O(n)
- **Intuition:** Find the longest subsequence where every element is strictly greater than the previous.
- **Pattern:** "Longest subsequence with a monotone condition"
- **Approach:** `dp[i] = 1 + max(dp[j]) for all j < i where arr[j] < arr[i]`
- **Commit:** `feat: implement LIS using O(n²) DP`
- **Tags:** `#LIS #DynamicProgramming #Subsequence #DSA`

---

### 6. Fibonacci DP — `06_fibonacci_dp.cpp`
- **Difficulty:** 🟢 Easy | **Time:** O(n) | **Space:** O(n)
- **Intuition:** Classic DP intro — naive recursion is O(2^n), memoization brings it to O(n).
- **Demonstrates:** Why memoization matters and how overlapping subproblems arise.
- **Commit:** `feat: implement Fibonacci with memoization and tabulation`
- **Tags:** `#Fibonacci #Memoization #DP #Recursion #DSA`

---

### 7. Box Stacking — `07_box_stacking.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(n²) | **Space:** O(n)
- **Intuition:** Stack boxes (each in any rotation) to maximise total height. Box A can go on B only if A's base is strictly smaller.
- **Pattern:** Extension of LIS — but generate all rotations first.
- **Approach:** Generate all rotations → sort by base area → run LIS on height.
- **Commit:** `feat: solve box stacking problem as LIS variant`
- **Tags:** `#BoxStacking #LIS #DP #DSA`

---

### 8. Subset Sum — `08_subset_sum.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n·W) | **Space:** O(n·W)
- **Intuition:** Can any subset of the array sum exactly to the target?
- **Pattern:** "Can we partition / reach target?" Yes/No answer.
- **Approach:** `dp[i][s] = dp[i-1][s] || dp[i-1][s-arr[i]]`
- **Commit:** `feat: solve subset sum problem with boolean DP table`
- **Tags:** `#SubsetSum #Knapsack #BooleanDP #DSA`

---

### 9. Longest Common Substring — `09_longest_common_substring.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(m·n) | **Space:** O(m·n)
- **Intuition:** Same as LCS but the matching characters must be **contiguous**.
- **Key difference:** Reset to 0 when characters don't match (no carry from diagonals of non-matching pairs).
- **Approach:** If `s1[i]==s2[j]`: `dp[i][j] = 1 + dp[i-1][j-1]` else `dp[i][j] = 0`
- **Commit:** `feat: implement longest common substring (contiguous LCS)`
- **Tags:** `#LongestCommonSubstring #StringDP #DP #DSA`

---

### 10. Edit Distance — `10_edit_distance.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(m·n) | **Space:** O(m·n)
- **Intuition:** Minimum insert / delete / replace operations to convert string A into string B. Used in spell-checkers and Git diff.
- **Pattern:** "Minimum operations to transform one string to another"
- **Approach:** If chars match: `dp[i][j] = dp[i-1][j-1]` else `1 + min(insert, delete, replace)`
- **Commit:** `feat: implement edit distance (Levenshtein) with 2D DP`
- **Tags:** `#EditDistance #Levenshtein #StringDP #DSA`

---

### 11. 0/1 Knapsack (Memoization) — `11_knapsack_memoization.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n·W) | **Space:** O(n·W)
- **Intuition:** Same as `01_knapsack_01.cpp` but implemented top-down with recursive calls + memo table.
- **Use:** Shows the contrast between top-down and bottom-up approaches.
- **Commit:** `feat: add 0/1 knapsack top-down with memoization`
- **Tags:** `#Knapsack #Memoization #TopDown #DSA`

---

### 12. Longest Palindromic Subsequence — `12_longest_palindromic_subsequence.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n²) | **Space:** O(n²)
- **Intuition:** Find the longest subsequence of a string that is a palindrome.
- **Key trick:** LPS(s) = LCS(s, reverse(s))
- **Commit:** `feat: implement LPS as LCS(s, reverse(s))`
- **Tags:** `#LPS #Palindrome #DP #StringDP #DSA`

---

### 13. Wildcard Matching — `13_wildcard_matching.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(m·n) | **Space:** O(m·n)
- **Intuition:** Match a pattern with `*` (matches any sequence) and `?` (matches any single char) against a string.
- **Approach:** DP table where `*` can match empty string or any number of chars → `dp[i][j] = dp[i-1][j] || dp[i][j-1]`
- **Commit:** `feat: solve wildcard pattern matching with 2D DP`
- **Tags:** `#WildcardMatching #PatternMatch #DP #DSA`

---

### 14. Optimal BST — `14_optimal_bst.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(n³) | **Space:** O(n²)
- **Intuition:** Given keys with search frequencies, build a BST that minimises total search cost (not just balanced — frequency-weighted).
- **Pattern:** "Interval DP — optimal structure for a sequence"
- **Approach:** Try each key as root; cost = frequency[root] + left subtree cost + right subtree cost. Minimise.
- **Commit:** `feat: implement optimal BST with interval DP`
- **Tags:** `#OptimalBST #IntervalDP #BST #DP #DSA`

---

## 📊 Tabulation vs Memoization

| Aspect | Tabulation (Bottom-Up) | Memoization (Top-Down) |
|--------|----------------------|----------------------|
| Direction | Iterative, fills table | Recursive, caches results |
| Stack overflow | No risk | Possible for large n |
| Efficiency | Slightly faster | Computes only needed states |
| Easier to code | Often harder | Often easier |

---

*[← Back to Master README](../README.md)*
