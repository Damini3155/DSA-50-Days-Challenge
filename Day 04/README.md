# 📅 Day 04: Fast & Slow Pointers, Sliding Window

> **Status**: ✅ Completed (5/5 Problems Solved)  
> **Target Problems**: 5  
> **Focus Patterns**: Fast & Slow Pointers (Linked List Midpoint, Reversal & Interleaving, Cycle on Array Graph) & Sliding Window / Prefix Traversal (Dynamic Window, Kadane's Algorithm)

---

## 🎯 Focus Patterns
- **Fast & Slow Pointers (Floyd's Tortoise & Hare)**:
  - Finding Midpoint of Linked List ($1$-step vs $2$-step)
  - In-place Linked List Reversal & Three-Phase Manipulations
  - Circular Array State Traversal & Cycle Detection
- **Sliding Window & Dynamic Prefix**:
  - Variable-size Sliding Window (Shortest Valid Subarray)
  - Kadane's Algorithm (Dynamic prefix reset for Maximum Subarray)

---

## 📝 Problem Checklist

- [x] **Problem 1**: [Reorder List (LeetCode #143)](https://leetcode.com/problems/reorder-list/)
  - **Solution File**: [`143. Reorder List.cpp`](./143.%20Reorder%20List.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Fast & Slow Pointers (Midpoint) + In-Place Reversal + Two-Pointer Alternating Merge
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: 
    1. Use fast and slow pointers to locate the middle of the linked list.
    2. Split the list into two halves by setting `slow->next = NULL`.
    3. Reverse the second half in-place using iterative three-pointer reversal (`prev`, `curr`, `next`).
    4. Splice and merge nodes alternately from the first and second reversed halves.

- [x] **Problem 2**: [Minimum Size Subarray Sum (LeetCode #209)](https://leetcode.com/problems/minimum-size-subarray-sum/)
  - **Solution File**: [`209. Minimum Size Subarray Sum.cpp`](./209.%20Minimum%20Size%20Subarray%20Sum.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Sliding Window (Dynamic Contraction)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: 
    1. Expand the `right` pointer and accumulate `sum += nums[right]`.
    2. Once `sum >= target`, greedily shrink the window from the left: update `mini = min(mini, right - left + 1)`, subtract `nums[left]`, and increment `left++`.
    3. Return `0` if `mini` remains `INT_MAX`, otherwise return `mini`.

- [x] **Problem 3**: [Palindrome Linked List (LeetCode #234)](https://leetcode.com/problems/palindrome-linked-list/)
  - **Solution File**: [`234. Palindrome Linked List.cpp`](./234.%20Palindrome%20Linked%20List.cpp)
  - **Difficulty**: Easy
  - **Pattern**: Fast & Slow Pointers + In-Place Half Reversal
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$ (Optimal, avoids $\mathcal{O}(N)$ auxiliary vector)
  - **Approach**: 
    1. Find the middle node using `slow` ($1$ step) and `fast` ($2$ steps).
    2. Reverse the second half of the linked list starting from `slow`.
    3. Compare values node-by-node between the first half (`head`) and the reversed second half (`prev`). If any mismatch occurs, return `false`; otherwise return `true`.

- [x] **Problem 4**: [Circular Array Loop (LeetCode #457)](https://leetcode.com/problems/circular-array-loop/)
  - **Solution File**: [`457. Circular Array Loop.cpp`](./457.%20Circular%20Array%20Loop.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Fast & Slow Pointers (Floyd's Cycle Detection on Circular Graph)
  - **Time Complexity**: $\mathcal{O}(N^2)$ (or $\mathcal{O}(N)$ with visited marking)
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: 
    1. Helper `getNext(nums, i)` handles circular indexing: `(i + nums[i]) % n` normalized for negative wraps.
    2. For every starting node `i`, run `slow` ($1$ step) and `fast` ($2$ steps).
    3. Validate loop conditions: all movements must follow the same direction (all forward or all backward), and loop length must be $> 1$ (`slow != nextslow` and `nextfast1 != nextfast2`).
    4. If `slow == fast`, a valid cycle is found; return `true`.

- [x] **Problem 5**: [Maximum Subarray (LeetCode #53)](https://leetcode.com/problems/maximum-subarray/)
  - **Solution File**: [`53. Maximum Subarray.cpp`](./53.%20Maximum%20Subarray.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Kadane's Algorithm / Dynamic Prefix Reset
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: 
    1. Maintain `sum = 0` and `maxi = INT_MIN`.
    2. Iterate through each element: add `nums[i]` to `sum` and update `maxi = max(maxi, sum)`.
    3. If `sum < 0`, reset `sum = 0` to discard negative prefixes that would reduce future subarray sums.
    4. Handles arrays with all negative numbers correctly because `maxi` updates before `sum` resets.

---

## 💡 Key Takeaways & Review Notes

1. **The Three-Phase Linked List Pattern**:
   - Both **Reorder List** and **Palindrome Linked List** share the same 3-step master workflow:
     1. Find midpoint using `slow` & `fast`.
     2. In-place reverse second half.
     3. Two-pointer traversal (either merge or compare).
   - Mastering this pattern solves multiple tricky Linked List problems in optimal $\mathcal{O}(1)$ space without extra data structures.

2. **Dynamic Sliding Window Contraction**:
   - In **Minimum Size Subarray Sum**, even though there is a nested `while` loop, each element enters the window once via `right` and leaves at most once via `left`, making the total runtime strictly $\mathcal{O}(2N) = \mathcal{O}(N)$.

3. **Circular Array Traversal Nuances**:
   - In circular arrays, `% n` in C++ can produce negative numbers for negative displacements (e.g., `-1 % 5 == -1`). Adding `n` ensures non-negative modulo index: `(i + nums[i]) % n + (next < 0 ? n : 0)`.
   - Direction consistency (`nums[i] > 0`) and avoiding 1-element loops (`i == next`) are critical interview edge cases.

4. **Kadane's Ordering Matters**:
   - Always update `maxi = max(maxi, sum)` **before** checking `if (sum < 0) sum = 0;`. This guarantees that if the input contains only negative numbers (e.g., `[-3, -2, -5]`), the maximum single element (`-2`) is captured rather than `0`.
