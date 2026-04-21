# 💰 Greedy Algorithms

> **Category:** Locally Optimal Choice Strategy  
> **Files:** 4 algorithms  

---

## 🎯 What is Greedy?

A greedy algorithm builds a solution step by step, **always choosing the option that looks best right now**, without reconsidering past choices.

**The key question:** Does the locally optimal choice lead to a globally optimal solution?  
If yes → Greedy works. If no → use Dynamic Programming.

## 🔑 When to Use Greedy?

| Trigger in problem | Greedy approach |
|-------------------|----------------|
| "Maximum non-overlapping" intervals | Sort by end time, pick greedily |
| "Fraction of items" allowed | Sort by value/weight ratio |
| "Schedule jobs before deadlines" | Sort by profit, use latest slot |
| "Build a prefix code / compress" | Always merge two smallest frequencies |
| "Merge K smallest" repeatedly | Min-heap greedy |

---

## 📋 Algorithm Details

### 1. Activity Selection — `01_activity_selection.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** O(n log n) | **Space:** O(1)
- **Real-life intuition:** You have a classroom and multiple classes want to book it. Schedule maximum classes without overlap.
- **Pattern hint:** Any "maximum non-overlapping intervals" problem.
- **Approach:**
  1. Sort activities by **finish time**
  2. Always pick the next activity whose start ≥ last finish
- **Why greedy works:** Picking the earliest finishing activity leaves maximum room for future activities.
- **Common mistakes:** Sorting by start time instead of finish time.
- **Example:** Activities `[(1,4),(3,5),(0,6),(5,7),(8,9)]` → Pick (1,4), (5,7), (8,9) = 3 activities
- **Commit:** `feat: add activity selection — greedy interval scheduling`
- **Tags:** `#ActivitySelection #IntervalScheduling #Greedy #DSA`

---

### 2. Fractional Knapsack — `02_fractional_knapsack.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** O(n log n) | **Space:** O(n)
- **Real-life intuition:** Fill a bag with gold dust — you can take fractions. Take the most valuable per kg first.
- **Pattern hint:** "Items can be split" + "maximize value with weight limit"
- **Approach:**
  1. Compute value/weight ratio for each item
  2. Sort by ratio descending
  3. Fill greedily — take whole item if it fits, else take fraction
- **Key difference from 0/1 Knapsack:** Fractions allowed → Greedy. No fractions → DP.
- **Commit:** `feat: implement fractional knapsack with value/weight ratio sort`
- **Tags:** `#FractionalKnapsack #Greedy #DSA #KnapsackProblem`

---

### 3. Job Sequencing — `03_job_sequencing.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** O(n²) | **Space:** O(n)
- **Real-life intuition:** Freelancer with one slot per day. Each job has a profit and a deadline. Maximize total profit.
- **Approach:**
  1. Sort jobs by profit descending
  2. For each job, assign to the latest available slot ≤ deadline
- **Common mistakes:** Not tracking which slots are used; wrong deadline handling.
- **Commit:** `feat: add job sequencing — greedy deadline scheduling`
- **Tags:** `#JobSequencing #DeadlineScheduling #Greedy #DSA`

---

### 4. Huffman Coding — `04_huffman_coding.cpp`
- **Difficulty:** 🔴 Hard
- **Time:** O(n log n) | **Space:** O(n)
- **Real-life intuition:** Morse code — common letters get short codes, rare letters get long codes. Huffman builds the *optimal* version of this.
- **Pattern hint:** Build optimal prefix-free binary codes for data compression.
- **Approach:**
  1. Create a leaf node for each character with its frequency
  2. Use a min-heap: repeatedly merge the two nodes with lowest frequency
  3. The merged node's frequency = sum of children
  4. Repeat until one node remains (the root)
  5. Left = 0, Right = 1. Read codes from root to each leaf.
- **Why greedy works:** Assigning shorter codes to higher-frequency characters minimises total bits.
- **Common mistakes:** Not using a min-priority queue; confusing the tree structure.
- **Commit:** `feat: implement Huffman coding with min-heap priority queue`
- **Tags:** `#HuffmanCoding #DataCompression #Greedy #PriorityQueue #DSA`

---

## 🆚 Greedy vs Dynamic Programming

| Aspect | Greedy | Dynamic Programming |
|--------|--------|-------------------|
| Choice | Locally optimal | Considers all subproblems |
| Subproblems | Does not revisit | Stores + reuses |
| Knapsack | Fractional only | 0/1 Knapsack |
| Speed | Usually faster | Usually slower |
| Proof needed | Yes (exchange argument) | Optimal substructure |

---

*[← Back to Master README](../README.md)*
