# 🔍 Searching Algorithms

> **Category:** Sequential & Logarithmic Search  
> **Files:** 3 algorithms  

---

## 🎯 What is Searching?

Searching means finding the position of a target element within a data structure.  
The right search algorithm can reduce work from **O(n) to O(log n)** or even **O(log log n)**.

## 🔑 When to Use Which?

| Situation | Algorithm |
|-----------|-----------|
| Array is **unsorted** | Linear Search |
| Array is **sorted** | Binary Search |
| Array is sorted and **uniformly distributed** | Interpolation Search |

---

## 📋 Algorithm Details

### 1. Linear Search — `01_linear_search.cpp`
- **Difficulty:** 🟢 Easy
- **Time:** O(n) | **Space:** O(1)
- **Intuition:** Check every element one by one until you find the target.
- **Approach:** Traverse array from left to right. Return index when match found.
- **Common mistakes:** Not handling the case where element isn't found.
- **Example:** Search 7 in `[3,1,7,9,2]` → checks 3,1,7 → found at index 2
- **Commit:** `feat: add linear search — O(n) sequential scan`
- **Tags:** `#LinearSearch #Search #DSA #BruteForce`

---

### 2. Binary Search — `02_binary_search.cpp`
- **Difficulty:** 🟢 Easy
- **Time:** O(log n) | **Space:** O(1) iterative, O(log n) recursive
- **Intuition:** Like finding a word in a dictionary — open to the middle, if too high go left, if too low go right.
- **Approach:** Maintain `low` and `high`. Check `mid = (low+high)/2`. Eliminate half each step.
- **Prerequisite:** Array **must be sorted**.
- **Recurrence:** `T(n) = T(n/2) + O(1)` → O(log n)
- **Common mistakes:** Integer overflow with `(low+high)/2` → use `low + (high-low)/2`. Wrong boundary conditions.
- **Example:** Search 7 in `[1,3,5,7,9,11]` → mid=5, too low → mid=9, too high → mid=7 ✅
- **Commit:** `feat: implement binary search — O(log n) on sorted array`
- **Tags:** `#BinarySearch #LogarithmicSearch #DSA #DivideAndConquer`

---

### 3. Recursive Binary + Interpolation Search — `03_recursive_binary_interpolation.cpp`
- **Difficulty:** 🟡 Medium
- **Time:** Binary O(log n) | Interpolation O(log log n) avg, O(n) worst | **Space:** O(log n)
- **Intuition (Interpolation):** Instead of always checking the middle, estimate *where* the target likely is based on its value, like a human would open a dictionary closer to 'Z' when searching for 'zebra'.
- **Approach:** `pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low])`
- **Prerequisite:** Array must be sorted AND uniformly distributed for interpolation to beat binary search.
- **Commit:** `feat: add recursive binary search + interpolation search`
- **Tags:** `#BinarySearch #InterpolationSearch #RecursiveSearch #DSA`

---

## 📊 Comparison

| Algorithm | Time (avg) | Time (worst) | Requires Sorted? |
|-----------|-----------|-------------|-----------------|
| Linear Search | O(n) | O(n) | ❌ No |
| Binary Search | O(log n) | O(log n) | ✅ Yes |
| Interpolation Search | O(log log n) | O(n) | ✅ Yes + Uniform |

---

*[← Back to Master README](../README.md)*
