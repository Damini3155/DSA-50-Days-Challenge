# 📅 Day 03: Two Pointers, Fast & Slow Pointers

> **Status**: ✅ Completed (5/5 Problems Solved)  
> **Target Problems**: 5  
> **Focus Pattern**: Fast & Slow Pointers (Floyd's Tortoise and Hare Cycle Detection, Cycle Entrance, Midpoint) & Two Pointers

---

## 🎯 Focus Patterns
- **Fast & Slow Pointers (Floyd's Cycle-Finding Algorithm)**:
  - Cycle Existence Detection (1-step vs 2-step pointers)
  - Cycle Starting Node Detection (Two-phase pointer convergence)
  - Linked List Midpoint Finding (Runner technique)
  - Implicit Graph / State Space Cycle Detection (Happy Number)
- **Two Pointers**:
  - Unsorted Boundary Detection & Subarray Expansion

---

## 📝 Problem Checklist

- [x] **Problem 1**: [Happy Number (LeetCode #202)](https://leetcode.com/problems/happy-number/)
  - **Solution File**: [`Happy Number.cpp`](./Happy%20Number.cpp)
  - **Difficulty**: Easy
  - **Pattern**: Fast & Slow Pointers / Cycle Detection
  - **Time Complexity**: $\mathcal{O}(\log N)$
  - **Space Complexity**: $\mathcal{O}(\log N)$ using `unordered_set` (Can be optimized to $\mathcal{O}(1)$ space using Fast & Slow Pointers)
  - **Approach**: Replace number $n$ with the sum of squares of its digits. If $n$ reaches 1, the number is happy. If a number is encountered that has already been seen, a cycle exists and the function returns `false`.

- [x] **Problem 2**: [Linked List Cycle (LeetCode #141)](https://leetcode.com/problems/linked-list-cycle/)
  - **Solution File**: [`Linked List Cycle.cpp`](./Linked%20List%20Cycle.cpp)
  - **Difficulty**: Easy
  - **Pattern**: Fast & Slow Pointers (Floyd's Cycle Detection)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Initialize two pointers `slow` and `fast` at `head`. Advance `slow` by 1 node and `fast` by 2 nodes in each iteration. If the linked list contains a cycle, the fast pointer will catch up to the slow pointer (`slow == fast`). If `fast` or `fast->next` reaches `nullptr`, there is no cycle.

- [x] **Problem 3**: [Linked List Cycle II (LeetCode #142)](https://leetcode.com/problems/linked-list-cycle-ii/)
  - **Solution File**: [`Linked List Cycle II.cpp`](./Linked%20List%20Cycle%20II.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Fast & Slow Pointers (Floyd's Cycle Detection + Entry Point Theorem)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Phase 1: Detect if a cycle exists using `slow` (1 step) and `fast` (2 steps). Phase 2: Once `slow == fast`, reset `slow` to `head` and keep `fast` at the meeting point. Advance both pointers 1 node at a time. The node where they collide again is mathematically guaranteed to be the start of the cycle.

- [x] **Problem 4**: [Middle of the Linked List (LeetCode #876)](https://leetcode.com/problems/middle-of-the-linked-list/)
  - **Solution File**: [`Middle of the Linked List.cpp`](./Middle%20of%20the%20Linked%20List.cpp)
  - **Difficulty**: Easy
  - **Pattern**: Fast & Slow Pointers (Runner Technique)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Move `slow` by 1 node and `fast` by 2 nodes starting from `head`. When `fast == nullptr` (even length) or `fast->next == nullptr` (odd length), `slow` points precisely to the middle node.

- [x] **Problem 5**: [Shortest Unsorted Continuous Subarray (LeetCode #581)](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)
  - **Solution File**: [`Shortest Unsorted Continuous Subarray.cpp`](./Shortest%20Unsorted%20Continuous%20Subarray.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Two Pointers (Boundary Narrowing + Min/Max Expansion)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Traverse from left to find the first index `i` where the sorting order breaks (`nums[i+1] < nums[i]`). If `i == n - 1`, the array is already sorted, return `0`. Traverse from right to find index `j` where decreasing order breaks. Find the `minval` and `maxval` in window `[i, j]`. Expand `i` leftwards while `nums[i-1] > minval`, and expand `j` rightwards while `nums[j+1] < maxval`. The shortest unsorted subarray length is `j - i + 1`.

---

## 💡 Key Takeaways & Review Notes

1. **Upgrading Happy Number to $\mathcal{O}(1)$ Space**:
   - The current implementation uses an `unordered_set<int>` requiring $\mathcal{O}(\log N)$ space.
   - Using **Fast & Slow pointers** eliminates the set entirely:
     ```cpp
     int getNext(int n) {
         int sum = 0;
         while (n > 0) {
             int d = n % 10;
             sum += d * d;
             n /= 10;
         }
         return sum;
     }

     bool isHappy(int n) {
         int slow = n;
         int fast = getNext(n);
         while (fast != 1 && slow != fast) {
             slow = getNext(slow);
             fast = getNext(getNext(fast));
         }
         return fast == 1;
     }
     ```
2. **Dead Code in `Middle of the Linked List.cpp`**:
   - Notice line 9: `if (left == right) return left;`.
   - In an acyclic list, after the first iteration `slow` is at index 1 and `fast` is at index 2 (for any step $k \ge 1$, $k < 2k$). They will never meet inside the loop! That condition is leftover from cycle detection and can be safely removed.
3. **The Math Behind Floyd's Cycle II**:
   - Let $L_1$ = distance from head to cycle entrance.
   - Let $L_2$ = distance from cycle entrance to meeting point.
   - Let $C$ = cycle length.
   - Distance traveled by slow = $L_1 + L_2$.
   - Distance traveled by fast = $L_1 + L_2 + n \cdot C$.
   - Because fast is twice as fast: $2(L_1 + L_2) = L_1 + L_2 + n \cdot C \implies L_1 = n \cdot C - L_2$.
   - Thus, moving one pointer from `head` and the other from the meeting point at equal speed guarantees they meet at the cycle entrance!
