================================================================================
          COMPLETE DAA CASE STUDIES — PATTERN RECOGNITION GUIDE
        "Learn to identify the algorithm, not just memorize the code"
================================================================================

HOW TO USE THIS FOLDER
=======================
Each file follows this structure:
  1. Problem Statement (real-life scenario)
  2. Pattern Recognition (WHY this algorithm fits)
  3. Category mapping
  4. Step-by-step thinking in beginner-friendly language
  5. Clean C++ code with detailed comments
  6. Time & Space Complexity
  7. Real-life interpretation
  8. Similar problems using the same pattern

================================================================================

INDEX OF ALL CASE STUDIES
===========================

GREEDY PATTERN:
  CS01_meeting_rooms.cpp          - Schedule max meetings in a room
  CS02_minimum_platforms.cpp      - Min train platforms needed
  CS03_largest_number.cpp         - Arrange to form the largest number
  CS04_gas_station.cpp            - Can you complete the circular trip?

DYNAMIC PROGRAMMING PATTERN:
  CS05_climbing_stairs.cpp        - Ways to reach top (1 or 2 steps)
  CS06_minimum_cost_path.cpp      - Min cost to reach bottom-right of grid
  CS07_rod_cutting.cpp            - Max profit by cutting a rod
  CS08_word_break.cpp             - Can string be segmented into words?
  CS09_egg_drop.cpp               - Min trials to find critical floor

DIVIDE AND CONQUER PATTERN:
  CS10_find_peak_element.cpp      - Find a peak element in array
  CS11_count_inversions.cpp       - Count inversions in array (merge sort)
  CS12_power_function.cpp         - Fast exponentiation (x^n)

GRAPH PATTERN:
  CS13_number_of_islands.cpp      - Count connected land regions (BFS/DFS)
  CS14_shortest_path_grid.cpp     - Shortest path in a maze (BFS)
  CS15_detect_cycle_undirected.cpp - Detect cycle using Union-Find

BACKTRACKING PATTERN:
  CS16_sudoku_solver.cpp          - Solve a 9x9 Sudoku puzzle
  CS17_word_search.cpp            - Find word in 2D character grid
  CS18_generate_parentheses.cpp   - Generate all valid bracket sequences

BINARY SEARCH PATTERN:
  CS19_search_rotated_array.cpp   - Binary search in rotated sorted array
  CS20_aggressive_cows.cpp        - Place cows with max minimum distance

SLIDING WINDOW / TWO POINTER PATTERN:
  CS21_max_sum_subarray_k.cpp     - Max sum of subarray of size k
  CS22_longest_subarray_distinct.cpp - Longest subarray with distinct elements

MIXED / ADVANCED:
  CS23_trapping_rainwater.cpp     - Calculate trapped rainwater
  CS24_minimum_spanning_scenarios.cpp - MST real-world applications

================================================================================

PATTERN RECOGNITION CHEAT SHEET
=================================

PROBLEM SAYS...                          USE THIS...
------------------------------------------------------------
"Maximum/Minimum" + "local choice"    -> GREEDY
"All combinations/subsets/paths"      -> BACKTRACKING
"Count ways" or "Min/Max of total"    -> DYNAMIC PROGRAMMING
"Sorted array" + "find element"       -> BINARY SEARCH
"Graph traversal" + "shortest"        -> BFS (unweighted) / DIJKSTRA
"Connected components"                -> DFS / BFS / UNION-FIND
"Repeated subproblems"                -> DYNAMIC PROGRAMMING
"Divide into halves"                  -> DIVIDE AND CONQUER
"Contiguous subarray"                 -> SLIDING WINDOW
"Pair of elements"                    -> TWO POINTERS

================================================================================
