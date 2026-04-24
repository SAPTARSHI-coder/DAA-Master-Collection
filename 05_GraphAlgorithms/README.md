# 🌐 Graph Algorithms

> **Category:** Node & Edge Traversal, Shortest Path, MST, SCC  
> **Files:** 11 algorithms  

---

## 🎯 What are Graph Algorithms?

Graphs model relationships between entities — cities, networks, dependencies, social connections.  
A graph has **vertices (V)** and **edges (E)** connecting them.

## 🔑 When to Use Which?

| Problem type | Algorithm |
|-------------|-----------|
| Explore all nodes / find connected components | BFS or DFS |
| Shortest path in **unweighted** graph | BFS |
| Shortest path, **no negative weights** | Dijkstra |
| Shortest path, **negative weights OK** | Bellman-Ford |
| Shortest path between **ALL pairs** | Floyd-Warshall |
| **Minimum Spanning Tree** (sparse graph) | Kruskal |
| **Minimum Spanning Tree** (dense graph) | Prim |
| Linear order of tasks with dependencies | Topological Sort |
| Check if there's a **cycle** in directed graph | DFS (color marking) |
| Can node u reach node v? (all pairs) | Warshall's Transitive Closure |
| Find **Strongly Connected Components** | Kosaraju's Algorithm |

---

## 📋 Algorithm Details

### 1. BFS — `01_bfs.cpp`
- **Difficulty:** 🟢 Easy | **Time:** O(V+E) | **Space:** O(V)
- **Intuition:** Explore layer by layer — like ripples spreading from a stone in water.
- **Uses a Queue.** Level = distance from source.
- **Use for:** Shortest path in unweighted graph, level-order traversal, connectivity check.
- **Commit:** `feat: implement BFS with queue — O(V+E) traversal`
- **Tags:** `#BFS #GraphTraversal #Queue #DSA`

---

### 2. DFS — `02_dfs.cpp`
- **Difficulty:** 🟢 Easy | **Time:** O(V+E) | **Space:** O(V)
- **Intuition:** Go as deep as possible down one path before backtracking — like exploring a maze.
- **Uses a Stack (or recursion).** 
- **Use for:** Cycle detection, topological sort, SCC, path finding.
- **Commit:** `feat: implement DFS recursively — O(V+E) graph traversal`
- **Tags:** `#DFS #GraphTraversal #Recursion #DSA`

---

### 3. Dijkstra's SSSP — `03_dijkstra.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(V²) matrix | **Space:** O(V)
- **Intuition:** Like GPS navigation — always explore the nearest unvisited city next.
- **Approach:** Greedy — use a visited array and dist[] array. Update distances greedily.
- **Limitation:** Does NOT work with negative weight edges.
- **Common mistakes:** Not marking nodes as visited; forgetting to initialise dist[] to infinity.
- **Commit:** `feat: implement Dijkstra SSSP with adjacency matrix`
- **Tags:** `#Dijkstra #ShortestPath #Greedy #Graph #DSA`

---

### 4. Bellman-Ford — `04_bellman_ford.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(V·E) | **Space:** O(V)
- **Intuition:** Relax all edges V-1 times. If you can still relax on the V-th iteration, a negative cycle exists.
- **Advantage over Dijkstra:** Handles negative weight edges. Can detect negative cycles.
- **Approach:** For each of V-1 passes: for every edge (u,v,w) → `dist[v] = min(dist[v], dist[u]+w)`
- **Commit:** `feat: implement Bellman-Ford SSSP with negative cycle detection`
- **Tags:** `#BellmanFord #ShortestPath #NegativeWeights #Graph #DSA`

---

### 5. Floyd-Warshall APSP — `05_floyd_warshall.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(V³) | **Space:** O(V²)
- **Intuition:** Try every vertex k as an intermediate hop between all pairs (i,j).
- **Approach:** `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
- **Use when:** You need shortest path between ALL pairs of vertices.
- **Commit:** `feat: implement Floyd-Warshall all-pairs shortest path`
- **Tags:** `#FloydWarshall #APSP #DP #Graph #DSA`

---

### 6. Kruskal's MST — `06_kruskal.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(E log E) | **Space:** O(V)
- **Intuition:** Sort all edges by weight. Add the cheapest edge that doesn't create a cycle.
- **Uses:** Union-Find (Disjoint Set Union) to detect cycles efficiently.
- **Best for:** Sparse graphs (few edges).
- **Commit:** `feat: implement Kruskal MST with Union-Find`
- **Tags:** `#Kruskal #MST #UnionFind #Greedy #Graph #DSA`

---

### 7. Prim's MST — `07_prim.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(V²) matrix | **Space:** O(V)
- **Intuition:** Grow the MST from any vertex — always add the cheapest edge connecting the tree to a new vertex.
- **Best for:** Dense graphs (many edges).
- **Difference from Kruskal:** Vertex-based (Prim) vs Edge-based (Kruskal).
- **Commit:** `feat: implement Prim's MST with key/parent arrays`
- **Tags:** `#Prim #MST #Greedy #Graph #DSA`

---

### 8. Topological Sort — `08_topological_sort.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(V+E) | **Space:** O(V)
- **Intuition:** Linear ordering of tasks where each task must come after its prerequisites (like course prerequisites or build systems).
- **Approach:** DFS-based: push to stack after all neighbours visited. Reverse stack = topo order.
- **Only valid for:** Directed Acyclic Graphs (DAG).
- **Commit:** `feat: implement topological sort with DFS and stack`
- **Tags:** `#TopologicalSort #DAG #DFS #Graph #DSA`

---

### 9. Cycle Detection — `09_cycle_detection.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(V+E) | **Space:** O(V)
- **Intuition:** During DFS, if you reach a node that's currently being processed (on the recursion stack), a cycle exists.
- **Approach:** Use three states: WHITE (unvisited), GRAY (in stack), BLACK (done). Cycle = reaching GRAY node.
- **Commit:** `feat: detect cycle in directed graph using DFS coloring`
- **Tags:** `#CycleDetection #DFS #Graph #DSA`

---

### 10. Warshall's Transitive Closure — `10_transitive_closure_warshall.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(V³) | **Space:** O(V²)
- **Intuition:** Can node i reach node j? Compute reachability for all pairs.
- **Approach:** Same as Floyd-Warshall but with boolean OR instead of min: `reach[i][j] |= reach[i][k] & reach[k][j]`
- **Commit:** `feat: compute transitive closure with Warshall's algorithm`
- **Tags:** `#TransitiveClosure #Warshall #Graph #Reachability #DSA`

---

### 11. Kosaraju's SCC — `11_kosaraju_scc.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(V+E) | **Space:** O(V)
- **Intuition:** A Strongly Connected Component (SCC) is a group where every node can reach every other node.
- **Approach:**
  1. Run DFS on original graph, record finish times
  2. Transpose the graph (reverse all edges)
  3. Run DFS in decreasing finish time order on transposed graph
  4. Each DFS tree = one SCC
- **Commit:** `feat: implement Kosaraju's SCC with double DFS`
- **Tags:** `#Kosaraju #SCC #DFS #Graph #DSA`

---

## 📊 Graph Algorithm Summary

| Algorithm | Time | Handles Negative? | Use Case |
|-----------|------|------------------|---------|
| BFS | O(V+E) | — | Shortest path (unweighted) |
| DFS | O(V+E) | — | Cycle detect, topo sort |
| Dijkstra | O(V²) | ❌ | SSSP (no negatives) |
| Bellman-Ford | O(V·E) | ✅ | SSSP (with negatives) |
| Floyd-Warshall | O(V³) | ✅ | All-pairs shortest path |
| Kruskal | O(E log E) | — | MST (sparse) |
| Prim | O(V²) | — | MST (dense) |
| Kosaraju | O(V+E) | — | Strongly connected components |

---

*[← Back to Master README](../README.md)*
