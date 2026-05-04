# 📚 Case Studies — Pattern-Based Problem Solving

> **Files:** 25 case studies + 2 guide files  
> **Purpose:** Real exam/interview problems solved by recognizing the underlying algorithm pattern  

---

## 🎯 How to Use This Folder

1. **Read the problem** → Don't look at the solution first
2. **Identify the pattern** using the guide below
3. **Match to an algorithm** category
4. **Verify** with the solution file

The goal is to build **pattern recognition instinct**, not memorize solutions.

---

## 🗺️ Pattern → Problem Mapping

### 🟢 Greedy Patterns

| Problem | File | Pattern Trigger |
|---------|------|----------------|
| Meeting Rooms | `CS01_meeting_rooms.cpp` | Max non-overlapping intervals → sort by end |
| Minimum Platforms | `CS02_minimum_platforms.cpp` | Max overlaps at any point → sort + two pointers |
| Largest Number | `CS03_largest_number.cpp` | Custom sort: `a+b > b+a` comparison |
| Gas Station | `CS04_gas_station.cpp` | Single pass, reset start when tank < 0 |
| Jump Game | `CS22_jump_game.cpp` | Track max reachable index |
| Connect Ropes | `CS24_connect_ropes.cpp` | Always merge two smallest → Min-Heap |

### 🔵 Dynamic Programming Patterns

| Problem | File | Pattern Trigger |
|---------|------|----------------|
| Climbing Stairs | `CS05_climbing_stairs.cpp` | DP 1D, Fibonacci recurrence |
| Minimum Cost Path | `CS06_minimum_cost_path.cpp` | DP Grid, move right/down |
| Rod Cutting | `CS07_rod_cutting.cpp` | Unbounded knapsack (cut any length) |
| Egg Drop | `CS08_egg_drop.cpp` | Minimax DP (worst-case minimization) |
| Word Break | `CS17_word_break.cpp` | DP string partition |
| Unique Paths | `CS21_unique_paths.cpp` | DP Grid, count paths |
| Coin Ways Count | `CS25_coin_ways_count.cpp` | Unbounded DP, count ways |

### 🔴 Divide & Conquer Patterns

| Problem | File | Pattern Trigger |
|---------|------|----------------|
| Count Inversions | `CS09_count_inversions.cpp` | Count during merge sort |
| Power Function | `CS10_power_function.cpp` | x^n → split: x^(n/2) × x^(n/2) |

### 🌐 Graph Patterns

| Problem | File | Pattern Trigger |
|---------|------|----------------|
| Number of Islands | `CS11_number_of_islands.cpp` | DFS connected components in grid |
| Shortest Path Grid | `CS12_shortest_path_grid.cpp` | BFS unweighted shortest path |

### 🔄 Backtracking Patterns

| Problem | File | Pattern Trigger |
|---------|------|----------------|
| Sudoku Solver | `CS13_sudoku_solver.cpp` | Constraint satisfaction |
| Word Search | `CS20_word_search.cpp` | Path tracking in 2D grid |
| Generate Permutations | `CS23_generate_permutations.cpp` | All arrangements of elements |

### 🔍 Binary Search Patterns

| Problem | File | Pattern Trigger |
|---------|------|----------------|
| Aggressive Cows | `CS14_aggressive_cows.cpp` | Maximize minimum distance |
| Search Rotated Array | `CS18_search_rotated_array.cpp` | Modified binary search on sorted+rotated |

### 🟣 Sliding Window Patterns

| Problem | File | Pattern Trigger |
|---------|------|----------------|
| Sliding Window Max K | `CS16_sliding_window_max_K.cpp` | Fixed-size window max |
| Longest Distinct Subarray | `CS19_longest_distinct_subarray.cpp` | Variable-size window |

### ⚡ Prefix / Two Pointer Patterns

| Problem | File | Pattern Trigger |
|---------|------|----------------|
| Trapping Rainwater | `CS15_trapping_rainwater.cpp` | Prefix-suffix max arrays |

---

## 📋 All Case Studies with Details

| # | File | Algorithm Category | Difficulty | Key Insight |
|---|------|--------------------|------------|-------------|
| CS01 | `CS01_meeting_rooms.cpp` | Greedy | 🟡 Medium | Sort by end time, count non-overlapping |
| CS02 | `CS02_minimum_platforms.cpp` | Greedy + 2PTR | 🟡 Medium | Sort arrivals & departures, scan with two pointers |
| CS03 | `CS03_largest_number.cpp` | Greedy | 🟡 Medium | Custom comparator: prefer `ab > ba` |
| CS04 | `CS04_gas_station.cpp` | Greedy | 🟡 Medium | If total gas ≥ total cost, solution exists; find start |
| CS05 | `CS05_climbing_stairs.cpp` | DP 1D | 🟢 Easy | `dp[i] = dp[i-1] + dp[i-2]` — Fibonacci |
| CS06 | `CS06_minimum_cost_path.cpp` | DP Grid | 🟡 Medium | `dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1])` |
| CS07 | `CS07_rod_cutting.cpp` | DP Unbounded | 🟡 Medium | Unbounded knapsack — cut rod any way |
| CS08 | `CS08_egg_drop.cpp` | DP Minimax | 🔴 Hard | `dp[e][f] = 1 + min(max(dp[e-1][k-1], dp[e][f-k]))` |
| CS09 | `CS09_count_inversions.cpp` | D&C | 🔴 Hard | Count inversions during merge step |
| CS10 | `CS10_power_function.cpp` | D&C | 🟡 Medium | `x^n = x^(n/2) * x^(n/2)` in O(log n) |
| CS11 | `CS11_number_of_islands.cpp` | Graph DFS | 🟡 Medium | DFS from each unvisited land cell |
| CS12 | `CS12_shortest_path_grid.cpp` | Graph BFS | 🟡 Medium | BFS from source, level = distance |
| CS13 | `CS13_sudoku_solver.cpp` | Backtracking | 🔴 Hard | Try 1–9 in each empty cell; backtrack on conflict |
| CS14 | `CS14_aggressive_cows.cpp` | Bin Search on Ans | 🔴 Hard | Binary search on min distance; check if K cows fit |
| CS15 | `CS15_trapping_rainwater.cpp` | Prefix-Suffix | 🔴 Hard | Water at i = min(maxL[i], maxR[i]) - height[i] |
| CS16 | `CS16_sliding_window_max_K.cpp` | Sliding Window | 🟡 Medium | Deque (monotonic) for O(n) window max |
| CS17 | `CS17_word_break.cpp` | DP String | 🔴 Hard | `dp[i]` = true if s[0..i] can be broken into words |
| CS18 | `CS18_search_rotated_array.cpp` | Modified BS | 🟡 Medium | Determine which half is sorted; binary search there |
| CS19 | `CS19_longest_distinct_subarray.cpp` | Sliding Window | 🟡 Medium | Expand right, shrink left when duplicate found |
| CS20 | `CS20_word_search.cpp` | Backtracking | 🔴 Hard | DFS with visited marking; undo on backtrack |
| CS21 | `CS21_unique_paths.cpp` | DP Grid | 🟡 Medium | `dp[i][j] = dp[i-1][j] + dp[i][j-1]` |
| CS22 | `CS22_jump_game.cpp` | Greedy | 🟡 Medium | Track `maxReach`; if i > maxReach, can't proceed |
| CS23 | `CS23_generate_permutations.cpp` | Backtracking | 🟡 Medium | Swap, recurse, swap back |
| CS24 | `CS24_connect_ropes.cpp` | Greedy/Heap | 🟡 Medium | Always merge two smallest; use min-heap |
| CS25 | `CS25_coin_ways_count.cpp` | DP Unbounded | 🟡 Medium | `dp[i] += dp[i - coin]` for all coins |

---

## 📁 Guide Files

| File | Purpose |
|------|---------|
| `README_CaseStudies.txt` | Quick index + pattern map (text format) |
| `MASTER_VIVA_GUIDE.txt` | Complete viva Q&A, key theorems, complexity tables |

---

## 💡 Pattern Recognition Cheat Sheet

```
Problem has "intervals"          → Greedy (sort by end time)
Problem has "grid + path"        → BFS (shortest) or DFS (exists)
Problem has "count ways"         → DP (unbounded or 0/1)
Problem has "all combinations"   → Backtracking
Problem has "minimize maximum"   → Binary Search on Answer
Problem has "window of size K"   → Sliding Window
Problem has "sorted array"       → Binary Search
Problem has "string transform"   → DP (Edit Distance, LCS)
Problem has "matrix chain"       → Interval DP (MCM)
Problem has "connected groups"   → DFS/BFS (graph traversal)
```

---

*[← Back to Master README](../README.md)*
