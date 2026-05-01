# 🔤 String Matching Algorithms

> **Category:** Pattern Search in Text  
> **Files:** 3 algorithms  

---

## 🎯 What is String Matching?

Given a **text** T (length n) and a **pattern** P (length m), find all positions where P appears in T.

Used in: text editors (Ctrl+F), DNA sequence analysis, plagiarism detection, search engines.

## 🔑 When to Use Which?

| Situation | Algorithm |
|-----------|-----------|
| Simple search, small strings | Naive O(n·m) |
| Need average O(n+m) with hashing | Rabin-Karp |
| Need guaranteed O(n+m) | KMP |

---

## 📋 Algorithm Details

### 1. Naive String Matching — `01_naive_string_matching.cpp`
- **Difficulty:** 🟢 Easy | **Time:** O(n·m) | **Space:** O(1)
- **Intuition:** Slide the pattern across the text one position at a time and check for a match.
- **Approach:** For each position i in text (0 to n-m), compare text[i..i+m-1] with pattern[0..m-1].
- **Common mistakes:** Wrong loop bounds (should stop at n-m, not n).
- **Example:** Text=`AABABCABAB`, Pattern=`ABAB` → found at index 5
- **Commit:** `feat: add naive string matching — O(n*m) brute force`
- **Tags:** `#StringMatching #BruteForce #NaiveSearch #DSA`

---

### 2. Rabin-Karp — `02_rabin_karp.cpp`
- **Difficulty:** 🟡 Medium | **Time:** O(n+m) avg, O(n·m) worst | **Space:** O(1)
- **Intuition:** Instead of comparing characters, compare **hash values** of the pattern and each window. Only do a full character comparison when hashes match (to confirm, avoiding false positives).
- **Key trick:** Rolling hash — slide the window and update hash in O(1):
  `new_hash = (old_hash - text[i] * h) * d + text[i+m]`
- **Common mistakes:** Not handling hash collisions (spurious hits); modular arithmetic overflow.
- **Commit:** `feat: implement Rabin-Karp string matching with rolling hash`
- **Tags:** `#RabinKarp #RollingHash #StringMatching #DSA`

---

### 3. KMP — `03_kmp.cpp`
- **Difficulty:** 🔴 Hard | **Time:** O(n+m) guaranteed | **Space:** O(m)
- **Intuition:** When a mismatch occurs, use knowledge of the pattern itself to skip redundant comparisons. The **failure function (LPS array)** tells us how far back to jump.
- **LPS = Longest Proper Prefix which is also a Suffix** for each prefix of pattern.
- **Approach:**
  1. Precompute `lps[]` array for the pattern — O(m)
  2. Use lps to skip characters in text on mismatch — O(n)
- **Example:** Pattern `ABABC` → lps = `[0,0,1,2,0]`
- **Common mistakes:** Wrong lps construction; not resetting correctly on mismatch.
- **Commit:** `feat: implement KMP with LPS failure function — O(n+m)`
- **Tags:** `#KMP #KnuthMorrisPratt #FailureFunction #StringMatching #DSA`

---

## 📊 Comparison

| Algorithm | Time (avg) | Time (worst) | Space | Key Idea |
|-----------|-----------|-------------|-------|---------|
| Naive | O(n·m) | O(n·m) | O(1) | Slide and compare |
| Rabin-Karp | O(n+m) | O(n·m) | O(1) | Rolling hash |
| KMP | O(n+m) | O(n+m) | O(m) | Skip with LPS array |

---

*[← Back to Master README](../README.md)*
