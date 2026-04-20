# 📦 Sorting Algorithms

> **Category:** Comparison-based & Non-comparison sorting  
> **Files:** 9 algorithms  

---

## 🎯 What is Sorting?

Sorting is the process of arranging data in a defined order (ascending/descending).  
It's the **foundation of all efficient algorithms** — binary search, Kruskal's MST, activity selection — all require sorted input.

## 🔑 When to Use Which Sort?

| Situation | Best Choice |
|-----------|-------------|
| Small array (n < 20) | Insertion Sort |
| Need guaranteed O(n log n) | Merge Sort |
| In-place + fast in practice | Quick Sort |
| Range of values is small (k ≈ n) | Counting Sort |
| Sorting integers digit by digit | Radix Sort |
| Need stable sort + extra space OK | Merge Sort |
| Nearly sorted array | Insertion Sort |
| Cannot use extra space | Heap Sort |

---

## 📋 Algorithm Details

### 1. Bubble Sort — `01_bubble_sort.cpp`
- **Difficulty:** 🟢 Easy
- **Time:** O(n²) worst/avg, O(n) best (with early exit)  | **Space:** O(1)
- **Intuition:** Like bubbles rising — the largest element "bubbles up" to its correct position each pass.
- **Approach:** Compare adjacent pairs, swap if out of order. Repeat n times.
- **Common mistakes:** Forgetting the early-exit optimisation; starting inner loop from wrong index.
- **Example:** `[5,1,4,2,8]` → after pass 1 → `[1,4,2,5,8]`
- **Commit:** `feat: add bubble sort with early-exit optimisation`
- **Tags:** `#BubbleSort #Sorting #DSA #BeginnerAlgorithm`

---

### 2. Selection Sort — `02_selection_sort.cpp`
- **Difficulty:** 🟢 Easy
- **Time:** O(n²) always | **Space:** O(1)
- **Intuition:** Each pass, *select* the minimum element from the unsorted part and place it at the front.
- **Approach:** Find min in `[i..n]`, swap with position i. Repeat.
- **Common mistakes:** Not tracking min index correctly; swapping values instead of using index.
- **Commit:** `feat: implement selection sort with min-index tracking`
- **Tags:** `#SelectionSort #Sorting #DSA`

---

### 3. Insertion Sort — `03_insertion_sort.cpp`
- **Difficulty:** 🟢 Easy
- **Time:** O(n²) worst, O(n) best | **Space:** O(1)
- **Intuition:** Like sorting playing cards — pick one card and insert it into the right position in your already-sorted hand.
- **Approach:** For each element, shift larger elements right and insert current in correct position.
- **Best for:** Nearly-sorted arrays, small datasets, online algorithms.
- **Commit:** `feat: add insertion sort — best for nearly-sorted data`
- **Tags:** `#InsertionSort #Sorting #DSA #AdaptiveSorting`

---

### 4. Merge Sort — `04_merge_sort.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** O(n log n) always | **Space:** O(n)
- **Intuition:** Divide the array in half recursively until size 1, then merge sorted halves.
- **Approach:** Split → recursively sort left and right → merge two sorted arrays.
- **Recurrence:** `T(n) = 2T(n/2) + O(n)` → O(n log n) by Master Theorem
- **Common mistakes:** Off-by-one in merge step; not copying back to original array.
- **Commit:** `feat: implement merge sort with D&C — O(n log n) stable sort`
- **Tags:** `#MergeSort #DivideAndConquer #StableSort #DSA`

---

### 5. Quick Sort — `05_quick_sort.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** O(n log n) avg, O(n²) worst | **Space:** O(log n)
- **Intuition:** Pick a pivot, partition the array so everything left < pivot < everything right. Recurse.
- **Approach:** Choose pivot → partition (Lomuto or Hoare) → recurse on both halves.
- **Common mistakes:** Choosing worst pivot (always min/max); not handling duplicates.
- **Commit:** `feat: add quick sort with Lomuto partition scheme`
- **Tags:** `#QuickSort #Partitioning #InPlace #DSA`

---

### 6. Counting Sort — `06_counting_sort.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** O(n+k) | **Space:** O(k)
- **Intuition:** Count how many times each value appears, then rebuild the array in order.
- **Approach:** Create frequency array of size max-value. Compute prefix sums. Place elements.
- **Limitation:** Only works on non-negative integers with small range k.
- **Commit:** `feat: implement counting sort — O(n+k) non-comparison sort`
- **Tags:** `#CountingSort #LinearSort #DSA #NonComparison`

---

### 7. Heap Sort — `07_heap_sort.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** O(n log n) always | **Space:** O(1)
- **Intuition:** Build a max-heap, then repeatedly extract the max to the end of the array.
- **Approach:** Heapify → extract max n times → sorted in place.
- **Common mistakes:** Wrong heapify direction; starting heapify from leaf instead of last internal node.
- **Commit:** `feat: add heap sort using max-heap extraction`
- **Tags:** `#HeapSort #MaxHeap #InPlace #DSA`

---

### 8. Shell Sort — `08_shell_sort.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** O(n^1.25) to O(n^1.5) | **Space:** O(1)
- **Intuition:** Generalisation of insertion sort — sort elements far apart first, gradually reducing gap.
- **Approach:** Choose gap sequence (n/2, n/4, ..., 1). For each gap, do insertion sort on that gap-spaced subarray.
- **Commit:** `feat: implement shell sort with gap-based insertion`
- **Tags:** `#ShellSort #GapSort #DSA`

---

### 9. Radix Sort — `09_radix_sort.cpp`
- **Difficulty:** 🔴 Hard
- **Time:** O(d·(n+b)) where d = digits, b = base | **Space:** O(n+b)
- **Intuition:** Sort digit by digit from least significant to most significant, using stable counting sort.
- **Approach:** For each digit position: apply counting sort using that digit as the key.
- **Common mistakes:** Not making counting sort stable; forgetting to handle all digit positions.
- **Commit:** `feat: add radix sort — sort integers digit by digit`
- **Tags:** `#RadixSort #LinearSort #DigitSort #DSA`

---

## 📊 Stability & Space Summary

| Algorithm | Stable? | In-Place? | Best Case |
|-----------|---------|-----------|-----------|
| Bubble Sort | ✅ Yes | ✅ Yes | O(n) |
| Selection Sort | ❌ No | ✅ Yes | O(n²) |
| Insertion Sort | ✅ Yes | ✅ Yes | O(n) |
| Merge Sort | ✅ Yes | ❌ No | O(n log n) |
| Quick Sort | ❌ No | ✅ Yes | O(n log n) |
| Counting Sort | ✅ Yes | ❌ No | O(n+k) |
| Heap Sort | ❌ No | ✅ Yes | O(n log n) |
| Shell Sort | ❌ No | ✅ Yes | O(n log n) |
| Radix Sort | ✅ Yes | ❌ No | O(d·n) |

---

*[← Back to Master README](../README.md)*
