# 📅 Day 02: Two Pointers

> **Status**: ✅ Completed (5/5 Problems Solved)  
> **Target Problems**: 5  
> **Focus Pattern**: Two Pointers (Quadruplets, Dutch National Flag / 3-Way Partition, Reverse Scanning, Sliding Window Count)

---

## 🎯 Focus Patterns
- **Two Pointers**
  - 4-Pointer Search (Two anchors + Inward scan)
  - 3-Way Partitioning (Dutch National Flag: Low, Mid, High)
  - Reverse Two Pointers (Right-to-left traversal for in-place/skipping operations)
  - Sliding Window (Dynamic boundary expansion and contraction)

---

## 📝 Problem Checklist

- [x] **Problem 1**: [4Sum (LeetCode #18)](https://leetcode.com/problems/4sum/)
  - **Solution File**: [`4Sum`](./4Sum)
  - **Difficulty**: Medium
  - **Pattern**: Two Pointers (Sort + Two Anchors + Two Pointers)
  - **Time Complexity**: $\mathcal{O}(N^3)$
  - **Space Complexity**: $\mathcal{O}(1)$ auxiliary
  - **Approach**: Sort the array. Iterate `i` and `j` in two nested loops, skipping duplicate values for both pointers. Then use two inward pointers `l = j + 1` and `r = n - 1` to find pairs that sum to `target - nums[i] - nums[j]`. Handled 64-bit integer overflow properly by casting the intermediate sum to `long long`.

- [x] **Problem 2**: [Backspace String Compare (LeetCode #844)](https://leetcode.com/problems/backspace-string-compare/)
  - **Solution File**: [`Backspace String Compare.cpp`](./Backspace%20String%20Compare.cpp)
  - **Difficulty**: Easy
  - **Pattern**: Two Pointers (Reverse Right-to-Left Traversal)
  - **Time Complexity**: $\mathcal{O}(N + M)$
  - **Space Complexity**: $\mathcal{O}(1)$ (Optimal, avoids $\mathcal{O}(N+M)$ stack memory)
  - **Approach**: Traverse backwards from the end of both strings using indices `i` and `j`. Maintain counters `skips` and `skipt` for backspace characters `'#'`. Decrement pointers past deleted characters. Compare surviving characters at each step. If a mismatch is found or one string empties before the other, return `false`.

- [x] **Problem 3**: [Sort Colors / Dutch National Flag (LeetCode #75)](https://leetcode.com/problems/sort-colors/)
  - **Solution File**: [`Sort Colors.cpp`](./Sort%20Colors.cpp)
  - **Difficulty**: Medium
  - **Pattern**: 3-Way Partitioning (Dutch National Flag Algorithm)
  - **Time Complexity**: $\mathcal{O}(N)$ single pass
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Maintain three pointers: `low = 0` (boundary of 0s), `mid = 0` (current element), and `high = n - 1` (boundary of 2s). If `nums[mid] == 0`, swap `nums[low]` and `nums[mid]`, then `low++` and `mid++`. If `nums[mid] == 1`, simply `mid++`. If `nums[mid] == 2`, swap `nums[mid]` and `nums[high]`, then `high--` without incrementing `mid`.

- [x] **Problem 4**: [Subarray Product Less Than K (LeetCode #713)](https://leetcode.com/problems/subarray-product-less-than-k/)
  - **Solution File**: [`Subarray Product Less Than K.cpp`](./Subarray%20Product%20Less%20Than%20K.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Two Pointers / Sliding Window
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Handle edge case `if (k <= 1) return 0;`. Expand the right pointer `r` one element at a time, updating `product *= nums[r]`. If `product >= k`, shrink the window by dividing out `nums[l]` and advancing `l++`. For each valid window `[l, r]`, exactly `r - l + 1` contiguous subarrays ending at `r` satisfy the condition.

- [x] **Problem 5**: [3Sum Smaller / Triplet With Smaller Sum (LeetCode #259 / GfG)](https://leetcode.com/problems/3sum-smaller/)
  - **Solution File**: [`Triplate With smaller sum.cpp`](./Triplate%20With%20smaller%20sum.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Two Pointers (Sort + Inward Combinatorial Count)
  - **Time Complexity**: $\mathcal{O}(N^2)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Sort the array. Iterate `i` from $0$ to $n-3$, and use two pointers `j = i + 1` and `k = n - 1`. If `nums[i] + nums[j] + nums[k] < target`, all elements between `j` and `k` will also produce a sum smaller than target with `nums[i]` and `nums[j]`. Add `k - j` to the total count in $\mathcal{O}(1)$ and increment `j++`. If the sum is $\ge target$, decrement `k--`.

---

## 💡 Key Takeaways & Review Notes

1. **Integer Overflow Prevention in 4Sum**:
   - The sum of four large integers (e.g. $10^9$) exceeds the 32-bit signed integer limit ($2^{31}-1 \approx 2.14 \times 10^9$). Using `long long sum = nums[i] + nums[j]; sum += nums[l] + nums[r];` is essential to prevent runtime crashes/UB.
2. **Reverse Scan for In-Place Memory**:
   - Backspace String Compare is easily solved with a stack in $\mathcal{O}(N)$ space, but working backwards with two pointers achieves the gold-standard $\mathcal{O}(1)$ space required in FAANG interviews.
3. **Dutch National Flag Invariant**:
   - When swapping `nums[mid]` with `nums[high]`, do **not** increment `mid`! The number brought in from `high` is unknown and must be evaluated in the next iteration.
4. **Subarray Counting Formula**:
   - When extending a valid contiguous sliding window from `[l, r-1]` to `[l, r]`, the number of new valid subarrays ending at index `r` is exactly `r - l + 1`.
5. **Housekeeping Note**:
   - The file `Day 02/4Sum` is missing its `.cpp` extension. Adding `.cpp` ensures proper syntax highlighting and compiler recognition.
   - Minor typo in filename: `Triplate With smaller sum.cpp` -> `Triplet With Smaller Sum.cpp`.
