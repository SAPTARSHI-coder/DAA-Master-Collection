# ⚙️ Advanced Algorithms

> **Category:** Specialized Techniques — Binary Search on Answer, Sliding Window, Greedy Scanning  
> **Files:** 3 algorithms  

---

## 🎯 What's in This Folder?

Algorithms that don't fit neatly into a single category but combine multiple paradigms:

| File | Paradigm |
|------|---------|
| Painter's Partition | Binary Search on Answer |
| Stock Buy & Sell | Greedy Single Pass |
| Kadane's Algorithm | Dynamic Programming / Greedy |

---

## 📋 Algorithm Details

### 1. Painter's Partition — `01_painter_partition.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(n log(sum)) | **Space:** O(1)
- **Intuition:** K painters must paint n boards. Each painter paints a contiguous section. Minimize the time taken by the **slowest painter** (minimize the maximum work assigned).
- **Pattern:** "Minimize the maximum" or "Minimize the largest partition" → **Binary Search on Answer**
- **Approach:**
  1. Answer lies in range `[max(boards), sum(boards)]`
  2. Binary search on the answer (mid = maximum load per painter)
  3. Check: can K painters finish all work with max load = mid?
  4. If yes, try smaller; if no, try larger
- **Common mistakes:** Wrong feasibility check; off-by-one in binary search.
- **Real-world:** Load balancing, job scheduling across workers.
- **Commit:** `feat: solve painter's partition with binary search on answer`
- **Tags:** `#PainterPartition #BinarySearchOnAnswer #LoadBalancing #DSA`

---

### 2. Stock Buy & Sell — `02_stock_buy_sell.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n) | **Space:** O(1)
- **Intuition:** Buy on the cheapest day before a rise, sell on the peak. Track running minimum price and max profit so far.
- **Pattern:** "Maximize profit / difference in array"
- **Approach:** Single pass — maintain `min_price` seen so far. For each day: `profit = price[i] - min_price`. Update max profit.
- **Common mistakes:** Allowing buying and selling on same day; not resetting min when price drops.
- **Example:** `[7,1,5,3,6,4]` → Buy at 1, sell at 6 → profit = 5
- **Commit:** `feat: maximize stock profit with single-pass greedy`
- **Tags:** `#StockBuySell #Greedy #SinglePass #DSA`

---

### 3. Kadane's Algorithm — `03_kadane_max_subarray.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n) | **Space:** O(1)
- **Intuition:** For each position, decide: extend the previous subarray or start a new one from here?
- **Pattern:** "Maximum sum contiguous subarray"
- **Approach:** `current = max(arr[i], current + arr[i])` at each step. Track global max.
- **Why it works:** If current sum becomes negative, it can only hurt any future extension → reset to current element.
- **Common mistakes:** Not initialising max with arr[0] (fails for all-negative arrays).
- **Example:** `[-2,1,-3,4,-1,2,1,-5,4]` → subarray `[4,-1,2,1]` → max sum = 6
- **Commit:** `feat: implement Kadane's algorithm for max subarray sum`
- **Tags:** `#Kadane #MaxSubarray #DP #Greedy #DSA`

---

## 🧠 Binary Search on Answer — The Key Pattern

When you see **"minimize the maximum"** or **"maximize the minimum"**:

```
low = minimum possible answer
high = maximum possible answer

while low <= high:
    mid = (low + high) / 2
    if feasible(mid):
        answer = mid
        high = mid - 1  # try smaller
    else:
        low = mid + 1   # need larger
```

Other problems using this pattern:
- Aggressive Cows (CS14) — maximize minimum distance
- Allocate Books — minimize maximum pages
- Kth Smallest in Matrix

---

*[← Back to Master README](../README.md)*
