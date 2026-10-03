# 📅 Day 05: Sliding Window

> **Status**: ✅ Completed (4/4 Problems Solved)  
> **Target Problems**: 4  
> **Focus Pattern**: Sliding Window (Variable-Length Windows, Distinct Character Tracking, Frequency Invariants)

---

## 🎯 Focus Patterns
- **Sliding Window (Variable Size / Dynamic Expansion & Contraction)**:
  - Non-repeating character substring tracking
  - At-most / Exactly $K$ distinct elements (Window state contraction)
  - Character replacement with maximum frequency invariant
  - Constrained distinct types (Fruit into Baskets: at most 2 types)

---

## 📝 Problem Checklist

- [x] **Problem 1**: [Longest Substring Without Repeating Characters (LeetCode #3)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
  - **Solution File**: [`3. Longest Substring Without Repeating Characters.cpp`](./3.%20Longest%20Substring%20Without%20Repeating%20Characters.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Sliding Window + Direct Address Frequency Array
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$ ($\mathcal{O}(\min(N, 128))$ ASCII table)
  - **Approach**: 
    1. Maintain a window `[l, r]` and a direct-mapped frequency table `vector<int> freq(128, 0)`.
    2. Expand `r` and increment `freq[s[r]]++`.
    3. If `freq[s[r]] > 1`, shrink window from the left by decrementing `freq[s[l]]--` and incrementing `l++` until duplicate is eliminated.
    4. Maximize window length with `maxi = max(maxi, r - l + 1)`.

- [x] **Problem 2**: [Longest Substring with At Most K Distinct Characters (LeetCode #340 / GfG)](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/)
  - **Solution File**: [`340. Longest Substring with At Most K Distinct Characters.cpp`](./340.%20Longest%20Substring%20with%20At%20Most%20K%20Distinct%20Characters.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Sliding Window + Hash Map State Tracking
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(K)$
  - **Approach**: 
    1. Expand `r` and track character counts in an `unordered_map<char, int> mp`.
    2. Whenever `mp.size() > k`, contract the window from left: decrement `mp[s[l]]--`, erase key if count hits `0`, and increment `l++`.
    3. Update `maxi` when valid window condition is satisfied.

- [x] **Problem 3**: [Longest Repeating Character Replacement (LeetCode #424)](https://leetcode.com/problems/longest-repeating-character-replacement/)
  - **Solution File**: [`424. Longest Repeating Character Replacement.cpp`](./424.%20Longest%20Repeating%20Character%20Replacement.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Sliding Window + Max Frequency Invariant
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$ ($\mathcal{O}(26)$ uppercase alphabets)
  - **Approach**: 
    1. For any window `[l, r]`, the minimum number of replacements needed to make all characters identical is `(window length) - maxfreq`.
    2. If `(r - l + 1) - maxfreq > k`, the current window is invalid: decrement `freq[s[l] - 'A']--` and increment `l++`.
    3. Maximize valid window length `maxi = max(maxi, r - l + 1)`. Notice `maxfreq` never needs to be recalculated downward because smaller frequencies cannot yield a longer valid window.

- [x] **Problem 4**: [Fruit Into Baskets (LeetCode #904)](https://leetcode.com/problems/fruit-into-baskets/)
  - **Solution File**: [`904. Fruit Into Baskets.cpp`](./904.%20Fruit%20Into%20Baskets.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Sliding Window (At Most 2 Distinct Elements)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$ (Hash map holds at most 3 distinct fruit types)
  - **Approach**: 
    1. Equivalent to finding the longest contiguous subarray with at most 2 unique numbers.
    2. Expand `r` and increment fruit count in `mp[fruits[r]]++`.
    3. While `mp.size() > 2`, shrink window from `l`: decrement count, erase if `0`, and advance `l++`.
    4. Maximize collected fruits count with `maxi = max(maxi, r - l + 1)`.

---

## 💡 Key Takeaways & Review Notes

1. **Direct Array vs. Hash Map**:
   - In **Problem 3**, using `vector<int> freq(128, 0)` is substantially faster than `unordered_map` because it avoids hashing, collisions, and dynamic heap allocations.

2. **The `maxfreq` Invariant in Character Replacement**:
   - In **LC #424**, you do not need to recompute `maxfreq` when shrinking the window with `l++`. A window can only break the current maximum length record if a higher `maxfreq` is discovered in the future.

3. **Handling Corner Case for $K$ Distinct Characters**:
   - In `340. Longest Substring with At Most K Distinct Characters.cpp`, if the problem requires exactly $k$ distinct characters (GfG variation) and no such window exists, `maxi` would remain `INT_MIN`. Always guard return value with `return maxi == INT_MIN ? -1 : maxi;`.

4. **Code Cleanliness Tip in Fruit Into Baskets**:
   - In `904. Fruit Into Baskets.cpp`, the `if (mp.size() > 2)` wrapping `while (mp.size() > 2)` is redundant since the `while` loop condition already performs this exact check.
