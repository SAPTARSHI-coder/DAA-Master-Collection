<div align="center">

# 🧠 DAA Master Collection
### Design & Analysis of Algorithms — Complete C++ Reference

[![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus)](https://isocpp.org/)
[![Programs](https://img.shields.io/badge/Programs-83%20Files-green?style=for-the-badge)](.)
[![Categories](https://img.shields.io/badge/Categories-10-orange?style=for-the-badge)](.)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)](LICENSE)

> **83 well-commented C++ programs** — organized by category, explained with real-world intuition, and mapped to interview patterns.

*For lab exams · viva prep · FAANG interviews · GitHub content*

</div>

---

## 📖 About

This is not a code dump — it's a **structured learning system** for DAA.

Every algorithm comes with:
- 🔍 **Pattern recognition hints** — know *when* to use each algorithm
- 💬 **Plain-English explanations** — intuition before implementation
- ⏱️ **Complexity analysis** — time and space at a glance
- 🌍 **Real-world analogies** — connect theory to practice

| Audience | What you get |
|----------|-------------|
| 🎓 B.Tech / MCA students | Lab programs + viva answers |
| 💼 Interview aspirants | Pattern-based approach to DSA rounds |
| 📣 Content creators | Commit messages + LinkedIn post templates |
| 👨‍🏫 Educators | Commented, teachable code with step-by-step logic |

---

## 📁 Repository Structure

```
DAA/
├── 01_Sorting/             →  9 algorithms
├── 02_Searching/           →  3 algorithms
├── 03_Greedy/              →  4 algorithms
├── 04_DynamicProgramming/  → 14 algorithms
├── 05_GraphAlgorithms/     → 11 algorithms
├── 06_Backtracking/        →  7 algorithms
├── 07_StringMatching/      →  3 algorithms
├── 08_Advanced/            →  3 algorithms
├── 09_DivideAndConquer/    →  4 algorithms
└── 10_CaseStudies/         → 25 case studies + 2 guides
```

---

## 🗺️ Algorithm Index

### 📦 Sorting — `01_Sorting/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_bubble_sort.cpp` | Bubble Sort | O(n²) | O(1) | 🟢 Easy |
| `02_selection_sort.cpp` | Selection Sort | O(n²) | O(1) | 🟢 Easy |
| `03_insertion_sort.cpp` | Insertion Sort | O(n²) | O(1) | 🟢 Easy |
| `04_merge_sort.cpp` | Merge Sort | O(n log n) | O(n) | 🟡 Medium |
| `05_quick_sort.cpp` | Quick Sort | O(n log n) avg | O(log n) | 🟡 Medium |
| `06_counting_sort.cpp` | Counting Sort | O(n+k) | O(k) | 🟡 Medium |
| `07_heap_sort.cpp` | Heap Sort | O(n log n) | O(1) | 🟡 Medium |
| `08_shell_sort.cpp` | Shell Sort | O(n^1.25) | O(1) | 🟡 Medium |
| `09_radix_sort.cpp` | Radix Sort | O(d·(n+b)) | O(n+b) | 🔴 Hard |

### 🔍 Searching — `02_Searching/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_linear_search.cpp` | Linear Search | O(n) | O(1) | 🟢 Easy |
| `02_binary_search.cpp` | Binary Search | O(log n) | O(1) | 🟢 Easy |
| `03_recursive_binary_interpolation.cpp` | Recursive BS + Interpolation | O(log log n) | O(log n) | 🟡 Medium |

### 💰 Greedy — `03_Greedy/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_activity_selection.cpp` | Activity Selection | O(n log n) | O(1) | 🟡 Medium |
| `02_fractional_knapsack.cpp` | Fractional Knapsack | O(n log n) | O(n) | 🟡 Medium |
| `03_job_sequencing.cpp` | Job Sequencing | O(n²) | O(n) | 🟡 Medium |
| `04_huffman_coding.cpp` | Huffman Coding | O(n log n) | O(n) | 🔴 Hard |

### 🧮 Dynamic Programming — `04_DynamicProgramming/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_knapsack_01.cpp` | 0/1 Knapsack (Tabulation) | O(n·W) | O(n·W) | 🟡 Medium |
| `02_lcs.cpp` | Longest Common Subsequence | O(m·n) | O(m·n) | 🟡 Medium |
| `03_matrix_chain_multiplication.cpp` | Matrix Chain Multiplication | O(n³) | O(n²) | 🔴 Hard |
| `04_coin_change.cpp` | Coin Change (Min Coins) | O(n·amt) | O(amt) | 🟡 Medium |
| `05_lis.cpp` | Longest Increasing Subsequence | O(n²) | O(n) | 🟡 Medium |
| `06_fibonacci_dp.cpp` | Fibonacci (Memo + Tab) | O(n) | O(n) | 🟢 Easy |
| `07_box_stacking.cpp` | Box Stacking | O(n²) | O(n) | 🔴 Hard |
| `08_subset_sum.cpp` | Subset Sum | O(n·W) | O(n·W) | 🟡 Medium |
| `09_longest_common_substring.cpp` | Longest Common Substring | O(m·n) | O(m·n) | 🟡 Medium |
| `10_edit_distance.cpp` | Edit Distance | O(m·n) | O(m·n) | 🔴 Hard |
| `11_knapsack_memoization.cpp` | 0/1 Knapsack (Top-Down) | O(n·W) | O(n·W) | 🟡 Medium |
| `12_longest_palindromic_subsequence.cpp` | Longest Palindromic Subsequence | O(n²) | O(n²) | 🟡 Medium |
| `13_wildcard_matching.cpp` | Wildcard Matching (`*` `?`) | O(m·n) | O(m·n) | 🔴 Hard |
| `14_optimal_bst.cpp` | Optimal BST | O(n³) | O(n²) | 🔴 Hard |

### 🌐 Graph Algorithms — `05_GraphAlgorithms/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_bfs.cpp` | Breadth First Search | O(V+E) | O(V) | 🟢 Easy |
| `02_dfs.cpp` | Depth First Search | O(V+E) | O(V) | 🟢 Easy |
| `03_dijkstra.cpp` | Dijkstra's SSSP | O(V²) | O(V) | 🟡 Medium |
| `04_bellman_ford.cpp` | Bellman-Ford SSSP | O(V·E) | O(V) | 🟡 Medium |
| `05_floyd_warshall.cpp` | Floyd-Warshall APSP | O(V³) | O(V²) | 🟡 Medium |
| `06_kruskal.cpp` | Kruskal's MST | O(E log E) | O(V) | 🟡 Medium |
| `07_prim.cpp` | Prim's MST | O(V²) | O(V) | 🟡 Medium |
| `08_topological_sort.cpp` | Topological Sort | O(V+E) | O(V) | 🟡 Medium |
| `09_cycle_detection.cpp` | Cycle Detection | O(V+E) | O(V) | 🟡 Medium |
| `10_transitive_closure_warshall.cpp` | Warshall's Transitive Closure | O(V³) | O(V²) | 🟡 Medium |
| `11_kosaraju_scc.cpp` | Kosaraju's SCC | O(V+E) | O(V) | 🔴 Hard |

### 🔄 Backtracking — `06_Backtracking/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_n_queens.cpp` | N-Queens | O(N!) | O(N) | 🟡 Medium |
| `02_graph_coloring.cpp` | Graph Coloring | O(M^V) | O(V) | 🟡 Medium |
| `03_rat_in_maze.cpp` | Rat in a Maze | O(4^(n²)) | O(n²) | 🟡 Medium |
| `04_hamiltonian_cycle.cpp` | Hamiltonian Cycle | O(N!) | O(N) | 🔴 Hard |
| `05_knights_tour.cpp` | Knight's Tour | O(8^(N²)) | O(N²) | 🔴 Hard |
| `06_subset_sum_backtracking.cpp` | Subset Sum (All Subsets) | O(2^n) | O(n) | 🟡 Medium |
| `07_tsp_backtracking.cpp` | TSP (Backtracking) | O(N!) | O(N) | 🔴 Hard |

### 🔤 String Matching — `07_StringMatching/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_naive_string_matching.cpp` | Naive / Brute Force | O(n·m) | O(1) | 🟢 Easy |
| `02_rabin_karp.cpp` | Rabin-Karp (Hashing) | O(n+m) avg | O(1) | 🟡 Medium |
| `03_kmp.cpp` | KMP (Failure Function) | O(n+m) | O(m) | 🔴 Hard |

### ⚙️ Advanced — `08_Advanced/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_painter_partition.cpp` | Painter's Partition | O(n log n) | O(1) | 🔴 Hard |
| `02_stock_buy_sell.cpp` | Stock Buy & Sell | O(n) | O(1) | 🟡 Medium |
| `03_kadane_max_subarray.cpp` | Kadane's Max Subarray | O(n) | O(1) | 🟡 Medium |

### ✂️ Divide & Conquer — `09_DivideAndConquer/`

| File | Algorithm | Time | Space | Difficulty |
|------|-----------|------|-------|------------|
| `01_tower_of_hanoi.cpp` | Tower of Hanoi | O(2^n) | O(n) | 🟡 Medium |
| `02_strassen_matrix.cpp` | Strassen's Matrix Multiply | O(n^2.807) | O(n²) | 🔴 Hard |
| `03_find_max_min.cpp` | Find Max & Min (D&C) | O(n) [3n/2] | O(log n) | 🟢 Easy |
| `04_naive_matrix_multiplication.cpp` | Standard Matrix Multiply | O(n³) | O(n²) | 🟢 Easy |

### 📚 Case Studies — `10_CaseStudies/`

| File | Problem | Pattern | Difficulty |
|------|---------|---------|------------|
| `CS01_meeting_rooms.cpp` | Meeting Rooms | Greedy / Intervals | 🟡 Medium |
| `CS02_minimum_platforms.cpp` | Minimum Platforms | Greedy + Two Pointers | 🟡 Medium |
| `CS03_largest_number.cpp` | Largest Number | Greedy / Custom Sort | 🟡 Medium |
| `CS04_gas_station.cpp` | Gas Station | Greedy / Single Pass | 🟡 Medium |
| `CS05_climbing_stairs.cpp` | Climbing Stairs | DP 1D / Fibonacci | 🟢 Easy |
| `CS06_minimum_cost_path.cpp` | Minimum Cost Path | DP Grid | 🟡 Medium |
| `CS07_rod_cutting.cpp` | Rod Cutting | DP Unbounded | 🟡 Medium |
| `CS08_egg_drop.cpp` | Egg Drop | DP Minimax | 🔴 Hard |
| `CS09_count_inversions.cpp` | Count Inversions | D&C / Merge Sort | 🔴 Hard |
| `CS10_power_function.cpp` | Fast Power x^n | D&C / Binary Exponentiation | 🟡 Medium |
| `CS11_number_of_islands.cpp` | Number of Islands | Graph DFS | 🟡 Medium |
| `CS12_shortest_path_grid.cpp` | Shortest Path in Grid | Graph BFS | 🟡 Medium |
| `CS13_sudoku_solver.cpp` | Sudoku Solver | Backtracking | 🔴 Hard |
| `CS14_aggressive_cows.cpp` | Aggressive Cows | Binary Search on Answer | 🔴 Hard |
| `CS15_trapping_rainwater.cpp` | Trapping Rainwater | Prefix-Suffix / Two Pointers | 🔴 Hard |
| `CS16_sliding_window_max_K.cpp` | Sliding Window Max | Sliding Window (Fixed) | 🟡 Medium |
| `CS17_word_break.cpp` | Word Break | DP / String Partition | 🔴 Hard |
| `CS18_search_rotated_array.cpp` | Search in Rotated Array | Modified Binary Search | 🟡 Medium |
| `CS19_longest_distinct_subarray.cpp` | Longest Distinct Subarray | Sliding Window (Variable) | 🟡 Medium |
| `CS20_word_search.cpp` | Word Search in Grid | Backtracking | 🔴 Hard |
| `CS21_unique_paths.cpp` | Unique Paths | DP Grid | 🟡 Medium |
| `CS22_jump_game.cpp` | Jump Game | Greedy / Max Reach | 🟡 Medium |
| `CS23_generate_permutations.cpp` | Generate Permutations | Backtracking | 🟡 Medium |
| `CS24_connect_ropes.cpp` | Connect Ropes | Greedy / Min Heap | 🟡 Medium |
| `CS25_coin_ways_count.cpp` | Coin Ways Count | DP Unbounded | 🟡 Medium |

---

## 🧠 Pattern Recognition Guide

> The most important skill in DSA is **recognizing the pattern**, not memorizing the solution.

### 🟢 Greedy — "Make the best local choice"
| If the problem says... | Use this |
|------------------------|----------|
| Max non-overlapping intervals / meetings | Activity Selection |
| Items can be **split** to fill knapsack | Fractional Knapsack |
| Schedule jobs to maximize profit before deadlines | Job Sequencing |
| Build optimal prefix codes / compression | Huffman Coding |
| Always merge the **two smallest** things | Min-Heap Greedy |
| Track max reachable index | Jump Game (Greedy) |

### 🔵 Dynamic Programming — "Overlapping subproblems + optimal substructure"
| If the problem says... | Use this |
|------------------------|----------|
| Items **cannot be split**, fit in weight W | 0/1 Knapsack |
| Longest subsequence matching two strings | LCS |
| Longest **contiguous** matching substring | Longest Common Substring |
| Minimum operations to convert string A → B | Edit Distance |
| Longest strictly increasing subsequence | LIS |
| Longest subsequence that reads same forwards/backwards | LPS |
| Count/find ways to make change with coins | Coin Change / Coin Ways |
| Can a subset sum to target? | Subset Sum |
| Optimal order to multiply a chain of matrices | Matrix Chain Multiplication |
| Match string with `*` and `?` wildcards | Wildcard Matching |
| Minimum cost search tree given access frequencies | Optimal BST |
| Count paths in a grid | Unique Paths |
| Partition string into dictionary words | Word Break |

### 🔴 Graph — "Model as nodes and edges"
| If the problem says... | Use this |
|------------------------|----------|
| Shortest path from one source, **no negatives** | Dijkstra |
| Shortest path, **negative weights** possible | Bellman-Ford |
| Shortest path between **all pairs** | Floyd-Warshall |
| **Minimum spanning tree** | Kruskal or Prim |
| Number of islands / connected components | DFS / BFS |
| Shortest path in **unweighted** graph/grid | BFS |
| Detect cycle in directed graph | DFS (with color) |
| Linear ordering of tasks with dependencies | Topological Sort |
| Can every node reach every other node? | Warshall / Kosaraju SCC |
| Strongly connected components | Kosaraju's Algorithm |

### 🟠 Backtracking — "Try all, undo bad choices"
| If the problem says... | Use this |
|------------------------|----------|
| Place N queens with no conflicts | N-Queens |
| Color graph with M colors | Graph Coloring |
| Find path in maze | Rat in a Maze |
| Visit all cities exactly once and return | Hamiltonian Cycle / TSP |
| All possible arrangements of elements | Generate Permutations |
| Solve a constraint satisfaction puzzle | Sudoku Solver |
| Find all subsets that sum to target | Subset Sum Backtracking |
| Find a word in a 2D character grid | Word Search |

### 🟡 Divide & Conquer — "Split → Solve → Merge"
| If the problem says... | Use this |
|------------------------|----------|
| Multiply two matrices faster than O(n³) | Strassen's Algorithm |
| Count inversions in array | Merge Sort based D&C |
| Compute x^n efficiently | Fast Power (D&C) |
| Move n disks with minimum moves | Tower of Hanoi |

### 🔵 Binary Search — "Monotone search space"
| If the problem says... | Use this |
|------------------------|----------|
| Array is sorted, find element | Binary Search |
| Array is sorted + rotated | Modified Binary Search |
| Minimize the **maximum** value | Binary Search on Answer |
| Maximize the **minimum** distance/gap | Binary Search on Answer |
| Find minimum pages/workers for K groups | Painter's Partition |

### 🟣 Sliding Window — "Contiguous subarray/window"
| If the problem says... | Use this |
|------------------------|----------|
| Max/sum in window of size K | Fixed Sliding Window |
| Longest subarray with distinct elements | Variable Sliding Window |
| Longest subarray with at most K distinct | Variable Sliding Window |

### ⚡ Prefix/Two Pointers — "Array traversal tricks"
| If the problem says... | Use this |
|------------------------|----------|
| Trap water between bars | Prefix-Suffix max arrays |
| Count platforms needed at any time | Sort + Two Pointers |
| Maximum subarray sum (contiguous) | Kadane's Algorithm |
| Maximum profit from stock prices | Greedy single pass |

### 🔤 String Matching — "Find pattern P in text T"
| If the problem says... | Use this |
|------------------------|----------|
| Simple pattern search | Naive O(n·m) |
| Fast search with hashing | Rabin-Karp |
| No redundant re-matching | KMP (failure function) |

---

## ⚡ Quick Complexity Reference

### Sorting
| Algorithm | Best | Average | Worst | Space | Stable? |
|-----------|------|---------|-------|-------|---------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | ❌ |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) | ✅ |
| Radix Sort | O(d·n) | O(d·n) | O(d·n) | O(n) | ✅ |

### Graph
| Algorithm | Time | Space | Use Case |
|-----------|------|-------|---------|
| BFS / DFS | O(V+E) | O(V) | Traversal, shortest unweighted |
| Dijkstra | O(V²) | O(V) | SSSP no negatives |
| Bellman-Ford | O(V·E) | O(V) | SSSP with negatives |
| Floyd-Warshall | O(V³) | O(V²) | All-pairs shortest path |
| Kruskal | O(E log E) | O(V) | MST, sparse graph |
| Prim | O(V²) | O(V) | MST, dense graph |
| Kosaraju | O(V+E) | O(V) | Strongly connected components |

### Dynamic Programming
| Problem | Time | Space |
|---------|------|-------|
| 0/1 Knapsack | O(n·W) | O(n·W) |
| LCS / Edit Distance | O(m·n) | O(m·n) |
| LIS | O(n²) | O(n) |
| MCM / Optimal BST | O(n³) | O(n²) |
| Coin Change | O(n·amount) | O(amount) |

### Matrix Multiplication
| Method | Time | Key Idea |
|--------|------|---------|
| Naive (Standard) | O(n³) | Triple nested loop |
| Strassen's D&C | O(n^2.807) | 7 multiplications instead of 8 |
| Matrix Chain (DP) | O(n³) DP | Finds optimal parenthesization *order* |

---

## 📣 Content Farming Guide

Use this for consistent GitHub commits and LinkedIn posts.

### Commit Message Templates

```
feat: add bubble sort with swap counter and early termination
feat: implement dijkstra SSSP with adjacency matrix
feat: solve N-Queens using backtracking with column/diagonal tracking
feat: add KMP string matching with LPS failure function
feat: implement Strassen matrix multiply (D&C, 7 multiplications)
feat: add CS14 aggressive cows — binary search on answer pattern
```

### LinkedIn Post Template

```
🧠 Day [N] of #100DaysOfDSA

Today I implemented [ALGORITHM NAME] in C++.

📌 What it does: [1 sentence]
🔑 Key insight: [1 sentence — the "aha" moment]
⏱️ Time: O(...) | Space: O(...)
💡 When to use: [1 sentence — pattern trigger]

Full code on GitHub → [link]

#DSA #Algorithms #CPlusPlus #[Category] #CodingJourney
```

### Recommended Tags by Category

| Category | Tags |
|----------|------|
| Sorting | `#Sorting #BubbleSort #MergeSort #QuickSort #DSA` |
| DP | `#DynamicProgramming #Knapsack #LCS #Memoization #DSA` |
| Graph | `#GraphAlgorithms #Dijkstra #BFS #DFS #MST` |
| Backtracking | `#Backtracking #NQueens #Recursion #BruteForce` |
| Greedy | `#GreedyAlgorithm #ActivitySelection #Huffman` |
| D&C | `#DivideAndConquer #Strassen #MergeSort #Recursion` |

---

## 🎓 Master Theorem Cheat Sheet

```
T(n) = aT(n/b) + O(n^k)

Case 1: log_b(a) > k  →  O(n^log_b(a))
Case 2: log_b(a) = k  →  O(n^k · log n)
Case 3: log_b(a) < k  →  O(n^k)

Key examples:
  T(n) = T(n/2) + O(1)    →  O(log n)      [Binary Search]
  T(n) = 2T(n/2) + O(n)   →  O(n log n)    [Merge Sort]
  T(n) = 7T(n/2) + O(n²)  →  O(n^2.807)   [Strassen]
  T(n) = T(n-1) + O(1)    →  O(n)           [Linear recursion]
  T(n) = 2T(n-1) + O(1)   →  O(2^n)         [Fibonacci naive]
```

---

## 🚀 How to Use This Repo

### For Students (Lab Exams)
1. Navigate to the relevant folder (e.g., `04_DynamicProgramming/`)
2. Open the `.cpp` file — every line is commented
3. Read the header comment for problem statement and example I/O
4. Compile: `g++ filename.cpp -o out && ./out`

### For Interview Prep
1. Start with the **Pattern Recognition Guide** above
2. Read the problem → identify the pattern → jump to the relevant file
3. Study the approach, not just the code
4. Practice on LeetCode/GFG with the same pattern

### For Viva
1. Read `10_CaseStudies/MASTER_VIVA_GUIDE.txt`
2. Study the Master Theorem and complexity table above
3. Know the **why** behind each algorithm's time complexity

### For Content Creators
1. Pick any algorithm
2. Use the LinkedIn template above
3. Post daily with the suggested hashtags

---

## 🤝 Contributing

Pull requests are welcome! If you find a bug, a better explanation, or want to add a new algorithm:

1. Fork the repository
2. Create a branch: `git checkout -b feat/algorithm-name`
3. Commit with a descriptive message
4. Open a Pull Request

---

## 📄 License

This project is licensed under the **MIT License** — free to use, share, and learn from.

---

<div align="center">

**⭐ Star this repo if it helped you — it keeps the project alive!**

*Made with ❤️ for students who want to understand, not just memorize.*

</div>
