# 🔄 Backtracking Algorithms

> **Category:** Systematic Exhaustive Search with Pruning  
> **Files:** 7 algorithms  

---

## 🎯 What is Backtracking?

Backtracking explores **all possible solutions** by building them incrementally and **abandoning (backtracking)** a path as soon as it's determined to be invalid.

Think of it as a **smart brute-force** — it prunes invalid branches early instead of exploring everything.

**Template:**
```
solve(state):
    if valid complete solution: record it / return true
    for each choice:
        if choice is valid:
            apply choice
            solve(next state)
            undo choice  ← THIS is the backtrack
```

## 🔑 When to Use Backtracking?

| Trigger | Algorithm |
|---------|-----------|
| "Place N queens with no conflicts" | N-Queens |
| "Color graph with M colors" | Graph Coloring |
| "Find path through maze" | Rat in a Maze |
| "Visit all nodes exactly once" | Hamiltonian Cycle |
| "Minimum cost tour" | TSP |
| "All possible arrangements" | Permutations |
| "Find all subsets summing to K" | Subset Sum |
| "Solve constraint puzzle" | Sudoku |
| "Find word in 2D grid" | Word Search |

---

## 📋 Algorithm Details

### 1. N-Queens — `01_n_queens.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(N!) | **Space:** O(N)
- **Intuition:** Place N chess queens on an N×N board so no two queens attack each other (no same row, col, or diagonal).
- **Approach:** Place one queen per row. For each column, check if placing is safe. Recurse. Backtrack if no safe column.
- **Key check:** Safe = no queen in same column, no queen in same diagonal (`|row1-row2| == |col1-col2|`)
- **Common mistakes:** Wrong diagonal check; not resetting state on backtrack.
- **Commit:** `feat: solve N-Queens with backtracking and safety check`
- **Tags:** `#NQueens #Backtracking #Chess #DSA`

---

### 2. Graph Coloring — `02_graph_coloring.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(M^V) | **Space:** O(V)
- **Intuition:** Color vertices of a graph with M colors such that no two adjacent vertices share the same color. (Used in map coloring, register allocation.)
- **Approach:** Assign color 1 to vertex 0. For each next vertex, try all M colors. Check adjacent vertices. Backtrack if none works.
- **Common mistakes:** Not checking ALL adjacent vertices before committing.
- **Commit:** `feat: solve graph M-coloring with backtracking`
- **Tags:** `#GraphColoring #Backtracking #ChromaticNumber #DSA`

---

### 3. Rat in a Maze — `03_rat_in_maze.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(4^(n²)) | **Space:** O(n²)
- **Intuition:** A rat starts at (0,0) and must reach (n-1,n-1). Cells are either open (1) or blocked (0). Find a path.
- **Approach:** From current cell, try all 4 directions (U/D/L/R). Mark cell as visited. Recurse. Backtrack if dead end.
- **Common mistakes:** Not marking cells as unvisited on backtrack (causes wrong paths).
- **Commit:** `feat: solve rat in maze with DFS backtracking`
- **Tags:** `#RatInMaze #Backtracking #PathFinding #DSA`

---

### 4. Hamiltonian Cycle — `04_hamiltonian_cycle.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(N!) | **Space:** O(N)
- **Intuition:** Find a cycle that visits every vertex exactly once and returns to the start. (TSP without weights.)
- **Approach:** Try adding each unvisited adjacent vertex to the path. If all vertices added and last connects to start → cycle found. Backtrack otherwise.
- **NP-Complete:** No efficient algorithm known for large N.
- **Commit:** `feat: find Hamiltonian cycle using backtracking`
- **Tags:** `#HamiltonianCycle #Backtracking #NP #Graph #DSA`

---

### 5. Knight's Tour — `05_knights_tour.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(8^(N²)) | **Space:** O(N²)
- **Intuition:** A chess knight must visit every square on an N×N board exactly once.
- **Approach:** From current position, try all 8 L-shaped moves. Mark as visited. Recurse. Backtrack.
- **Optimization:** Warnsdorff's heuristic — always move to the square with fewest onward moves (reduces backtracking dramatically).
- **Commit:** `feat: solve Knight's Tour with backtracking`
- **Tags:** `#KnightsTour #Backtracking #Chess #DSA`

---

### 6. Subset Sum (Backtracking) — `06_subset_sum_backtracking.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(2^n) | **Space:** O(n)
- **Intuition:** Print ALL subsets of the array that sum exactly to the target (not just yes/no).
- **Difference from DP subset sum:** DP answers YES/NO. Backtracking **prints all subsets**.
- **Approach:** At each index, either include or exclude the element. If sum == target, print subset.
- **Commit:** `feat: print all subsets summing to target with backtracking`
- **Tags:** `#SubsetSum #Backtracking #AllSubsets #DSA`

---

### 7. TSP (Backtracking) — `07_tsp_backtracking.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(N!) | **Space:** O(N)
- **Intuition:** Find the minimum cost tour that visits all cities exactly once and returns to the start.
- **Approach:** Try all permutations of cities. Calculate total cost for each. Track minimum.
- **NP-Hard:** For large N, use DP (Held-Karp) or approximations. Backtracking is exact but slow.
- **Commit:** `feat: solve TSP exactly using backtracking — O(N!)`
- **Tags:** `#TSP #TravelingSalesman #Backtracking #NP #DSA`

---

## 📊 Backtracking vs Brute Force

| Aspect | Brute Force | Backtracking |
|--------|-------------|-------------|
| Explores | All possibilities | Prunes invalid branches early |
| Speed | Slower | Faster (same worst-case, better avg) |
| Strategy | Generate then check | Check as you build |
| Space | Often O(1) | O(depth) for recursion stack |

---

*[← Back to Master README](../README.md)*
