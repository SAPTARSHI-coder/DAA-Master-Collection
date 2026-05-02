================================================================================
      COMPLETE DAA (Design and Analysis of Algorithms) PROGRAM COLLECTION
                         Written in C++ | Beginner Friendly
                    For Lab Exams, Viva, and Easy Revision
                        *** FINAL COMPLETE VERSION ***
================================================================================

TOTAL PROGRAMS: 83 source files + 2 reference/guide files

FOLDER STRUCTURE
================

DAA/
├── 01_Sorting/           (9 algorithms)
│   ├── 01_bubble_sort.cpp          - O(n^2)      - Compare & swap adjacent
│   ├── 02_selection_sort.cpp       - O(n^2)      - Select minimum each pass
│   ├── 03_insertion_sort.cpp       - O(n^2)      - Insert into sorted part
│   ├── 04_merge_sort.cpp           - O(n log n)  - Divide & Merge
│   ├── 05_quick_sort.cpp           - O(n log n)  - Pivot partition
│   ├── 06_counting_sort.cpp        - O(n+k)      - Count frequency
│   ├── 07_heap_sort.cpp            - O(n log n)  - Max-Heap extraction
│   ├── 08_shell_sort.cpp           - O(n log n)  - Gap-based insertion sort
│   └── 09_radix_sort.cpp           - O(d*(n+b))  - Sort digit by digit
│
├── 02_Searching/         (3 algorithms)
│   ├── 01_linear_search.cpp                   - O(n) - Check each element
│   ├── 02_binary_search.cpp                   - O(log n) - Halve search space
│   └── 03_recursive_binary_interpolation.cpp  - Recursive BS + Interpolation search
│
├── 03_Greedy/            (4 algorithms)
│   ├── 01_activity_selection.cpp   - Max non-overlapping activities
│   ├── 02_fractional_knapsack.cpp  - Take fractions to maximize value
│   ├── 03_job_sequencing.cpp       - Schedule jobs to maximize profit
│   └── 04_huffman_coding.cpp       - Optimal prefix codes for compression
│
├── 04_DynamicProgramming/ (14 algorithms)
│   ├── 01_knapsack_01.cpp                       - 0/1 Knapsack (Tabulation)
│   ├── 02_lcs.cpp                               - Longest Common Subsequence
│   ├── 03_matrix_chain_multiplication.cpp       - Optimal matrix multiply order
│   ├── 04_coin_change.cpp                       - Min coins to make amount
│   ├── 05_lis.cpp                               - Longest Increasing Subsequence
│   ├── 06_fibonacci_dp.cpp                      - Fibonacci (Memo + Tabulation)
│   ├── 07_box_stacking.cpp                      - Max height with box rotations
│   ├── 08_subset_sum.cpp                        - Can subset sum to target?
│   ├── 09_longest_common_substring.cpp          - LCS but CONTIGUOUS
│   ├── 10_edit_distance.cpp                     - Min ops to convert strings
│   ├── 11_knapsack_memoization.cpp              - 0/1 Knapsack (Top-Down)
│   ├── 12_longest_palindromic_subsequence.cpp   - LPS = LCS(s, reverse(s))
│   ├── 13_wildcard_matching.cpp                 - '*' and '?' pattern matching
│   └── 14_optimal_bst.cpp                       - Minimize weighted search cost
│
├── 05_GraphAlgorithms/   (11 algorithms)
│   ├── 01_bfs.cpp                           - Breadth First Search
│   ├── 02_dfs.cpp                           - Depth First Search
│   ├── 03_dijkstra.cpp                      - Shortest Path (no negatives)
│   ├── 04_bellman_ford.cpp                  - Shortest Path (with negatives)
│   ├── 05_floyd_warshall.cpp                - All-Pairs Shortest Path
│   ├── 06_kruskal.cpp                       - MST (Edge-based, Union-Find)
│   ├── 07_prim.cpp                          - MST (Vertex-based)
│   ├── 08_topological_sort.cpp              - Linear order of DAG
│   ├── 09_cycle_detection.cpp               - Cycle in directed graph
│   ├── 10_transitive_closure_warshall.cpp   - Reachability between all pairs
│   └── 11_kosaraju_scc.cpp                  - Strongly Connected Components
│
├── 06_Backtracking/      (7 algorithms)
│   ├── 01_n_queens.cpp                - Place N queens (no conflicts)
│   ├── 02_graph_coloring.cpp          - Color graph with M colors
│   ├── 03_rat_in_maze.cpp             - Find path in maze
│   ├── 04_hamiltonian_cycle.cpp       - Visit all vertices and return
│   ├── 05_knights_tour.cpp            - Knight visits every chess square once
│   ├── 06_subset_sum_backtracking.cpp - Print ALL subsets summing to target
│   └── 07_tsp_backtracking.cpp        - Min cost tour visiting all cities
│
├── 07_StringMatching/    (3 algorithms)
│   ├── 01_naive_string_matching.cpp   - O(n*m) brute force
│   ├── 02_rabin_karp.cpp              - O(n+m) hashing-based
│   └── 03_kmp.cpp                     - O(n+m) LPS failure function
│
├── 08_Advanced/          (3 algorithms)
│   ├── 01_painter_partition.cpp       - Binary search on answer
│   ├── 02_stock_buy_sell.cpp          - Greedy max profit
│   └── 03_kadane_max_subarray.cpp     - O(n) max contiguous subarray sum
│
├── 09_DivideAndConquer/  (4 algorithms)
│   ├── 01_tower_of_hanoi.cpp               - Classic recursion (n disks)
│   ├── 02_strassen_matrix.cpp              - Matrix multiply in O(n^2.807) [7 mults]
│   ├── 03_find_max_min.cpp                 - Max+Min in 3n/2 comparisons
│   └── 04_naive_matrix_multiplication.cpp  - Standard O(n^3) triple-loop multiply
│
└── 10_CaseStudies/       (25 case studies + 2 guide files)
    ├── README_CaseStudies.txt         - Index + quick pattern map
    ├── MASTER_VIVA_GUIDE.txt          - COMPLETE viva prep (READ THIS!)
    ├── CS01_meeting_rooms.cpp         - GREEDY: max non-overlapping intervals
    ├── CS02_minimum_platforms.cpp     - GREEDY+2PTR: count overlaps
    ├── CS03_largest_number.cpp        - GREEDY: custom sort comparator
    ├── CS04_gas_station.cpp           - GREEDY: single pass, reset start
    ├── CS05_climbing_stairs.cpp       - DP 1D: Fibonacci recurrence
    ├── CS06_minimum_cost_path.cpp     - DP GRID: right/down min cost
    ├── CS07_rod_cutting.cpp           - DP UNBOUNDED: max revenue
    ├── CS08_egg_drop.cpp              - DP MINIMAX: min worst-case trials
    ├── CS09_count_inversions.cpp      - D&C: inversions during merge sort
    ├── CS10_power_function.cpp        - D&C: x^n in O(log n)
    ├── CS11_number_of_islands.cpp     - GRAPH DFS: connected components
    ├── CS12_shortest_path_grid.cpp    - GRAPH BFS: unweighted shortest path
    ├── CS13_sudoku_solver.cpp         - BACKTRACKING: constraint satisfaction
    ├── CS14_aggressive_cows.cpp       - BINARY SEARCH ON ANSWER
    ├── CS15_trapping_rainwater.cpp    - PREFIX-SUFFIX + TWO POINTERS
    ├── CS16_sliding_window_max_K.cpp  - SLIDING WINDOW (fixed size)
    ├── CS17_word_break.cpp            - DP STRING PARTITION
    ├── CS18_search_rotated_array.cpp  - MODIFIED BINARY SEARCH
    ├── CS19_longest_distinct_subarray.cpp - SLIDING WINDOW (variable)
    ├── CS20_word_search.cpp           - BACKTRACKING: grid path tracking
    ├── CS21_unique_paths.cpp          - DP GRID: count paths
    ├── CS22_jump_game.cpp             - GREEDY: max reach tracking
    ├── CS23_generate_permutations.cpp - BACKTRACKING: all arrangements
    ├── CS24_connect_ropes.cpp         - GREEDY: always merge smallest
    └── CS25_coin_ways_count.cpp       - DP UNBOUNDED: count ways

================================================================================

QUICK COMPLEXITY REFERENCE
============================

SORTING:
  Bubble / Selection / Insertion : O(n^2)        Space O(1)
  Merge Sort                     : O(n log n)    Space O(n)
  Quick Sort                     : O(n log n) avg, O(n^2) worst    Space O(log n)
  Heap Sort                      : O(n log n)    Space O(1)
  Counting Sort                  : O(n + k)      Space O(k)
  Radix Sort                     : O(d*(n+b))    Space O(n+b)
  Shell Sort                     : O(n^1.25)     Space O(1)

SEARCHING:
  Linear Search                  : O(n)          Space O(1)
  Binary Search                  : O(log n)      Space O(1)
  Interpolation Search           : O(log log n)  Space O(1)

DYNAMIC PROGRAMMING:
  0/1 Knapsack                   : O(n*W)        Space O(n*W)
  LCS / Edit Distance            : O(m*n)        Space O(m*n)
  LPS                            : O(n^2)        Space O(n^2)
  MCM / Optimal BST              : O(n^3)        Space O(n^2)
  Coin Change / Climbing Stairs  : O(n*amount)   Space O(amount)
  Wildcard Matching              : O(m*n)        Space O(m*n)

GRAPH:
  BFS / DFS                      : O(V^2) matrix, O(V+E) list
  Dijkstra                       : O(V^2) matrix
  Bellman-Ford                   : O(V*E)
  Floyd-Warshall / Warshall's    : O(V^3)
  Kruskal                        : O(E log E)
  Prim                           : O(V^2)
  Kosaraju SCC                   : O(V^2) matrix

BACKTRACKING:
  N-Queens                       : O(N!)
  Hamiltonian Cycle / TSP        : O(N!)
  Knight's Tour                  : O(8^(N^2))
  Sudoku Solver                  : O(9^empty_cells)

DIVIDE & CONQUER:
  Tower of Hanoi                 : O(2^n)
  Naive Matrix Multiply (NxN)    : O(n^3)        Space O(n^2)
  Strassen's Matrix Multiply     : O(n^2.807)    Space O(n^2)  [7 mults vs 8]
  Find Max+Min                   : O(n)   [3n/2 comparisons]
  Fast Power x^n                 : O(log n)

MATRIX MULTIPLICATION COMPARISON:
  Naive (Standard)               : O(n^3)        — 8 multiplications per step
  Strassen's D&C                 : O(n^2.807)    — 7 multiplications per step
  Matrix Chain Multiplication    : O(n^3) DP     — finds optimal parenthesization order
  (MCM does NOT multiply; it finds the ORDER that minimizes total multiplications)

================================================================================

MASTER THEOREM (For viva — recurrence to complexity)
====================================================
  T(n) = T(n/2) + O(1)   =>  O(log n)       [Binary Search]
  T(n) = 2T(n/2) + O(n)  =>  O(n log n)     [Merge Sort]
  T(n) = 7T(n/2) + O(n^2)=>  O(n^2.807)     [Strassen Matrix Multiply]
  T(n) = T(n-1) + O(1)   =>  O(n)            [Simple tail recursion]
  T(n) = 2T(n-1) + O(1)  =>  O(2^n)          [Fibonacci naive]

MATRIX MULTIPLICATION RECURRENCES:
  Naive      : No D&C recurrence — flat O(m*p*n) triple loop, no subproblems
  Strassen's : T(n) = 7T(n/2) + O(n^2)  =>  O(n^2.807)  (one fewer multiply per step)
  MCM (DP)   : T(n) = O(n^3) tabulation — no recurrence, solved bottom-up

================================================================================
