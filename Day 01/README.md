# 📅 Day 01: Two Pointers

> **Status**: ✅ Completed (5/5 Problems Solved)  
> **Target Problems**: 5  
> **Focus Pattern**: Two Pointers (Opposite Ends, Same Direction / Slow-Fast, Triplet Search)

---

## 🎯 Focus Patterns
- **Two Pointers**
  - Opposite Ends (Inward convergence: $L \to \leftarrow R$)
  - Same Direction (Slow & Fast / In-place rewrite)
  - Anchored Two Pointers (Fix one element, scan remainder with 2 pointers)

---

## 📝 Problem Checklist

- [x] **Problem 1**: [Two Sum II - Input Array Is Sorted (LeetCode #167)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
  - **Solution File**: [`Two Sum II - Input Array Is Sorted.c++`](./Two%20Sum%20II%20-%20Input%20Array%20Is%20Sorted.c%2B%2B)
  - **Difficulty**: Medium
  - **Pattern**: Two Pointers (Inward Convergence)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Array is already sorted. Place pointer `l = 0` and `r = n - 1`. If `numbers[l] + numbers[r] == target`, return 1-based indices `{l + 1, r + 1}`. If the sum is greater than `target`, decrement `r` to reduce sum; if less, increment `l`.

- [x] **Problem 2**: [Remove Duplicates from Sorted Array (LeetCode #26)](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
  - **Solution File**: [`Remove Duplicates from Sorted Array.c++`](./Remove%20Duplicates%20from%20Sorted%20Array.c%2B%2B)
  - **Difficulty**: Easy
  - **Pattern**: Two Pointers (Slow & Fast / In-place Overwrite)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Maintain slow pointer `l = 0` representing the boundary of unique elements and fast pointer `r = 1` exploring upcoming values. Whenever `nums[r] != nums[l]`, increment `l` and assign `nums[l] = nums[r]`. Returns `l + 1` unique elements.

- [x] **Problem 3**: [Squares of a Sorted Array (LeetCode #977)](https://leetcode.com/problems/squares-of-a-sorted-array/)
  - **Solution File**: [`977. Squares of a Sorted Array.c++`](./977.%20Squares%20of%20a%20Sorted%20Array.c%2B%2B)
  - **Difficulty**: Easy
  - **Pattern**: Two Pointers (Inward Convergence to Output Array)
  - **Time Complexity**: $\mathcal{O}(N)$
  - **Space Complexity**: $\mathcal{O}(1)$ auxiliary ($\mathcal{O}(N)$ output array)
  - **Approach**: The largest squares can appear either at the extreme left (large negative numbers) or extreme right (large positive numbers). Compare `nums[l]^2` and `nums[r]^2`, place the larger value at index `i = n - 1` down to `0`, and move the corresponding pointer inward.

- [x] **Problem 4**: [3Sum (LeetCode #15)](https://leetcode.com/problems/3sum/)
  - **Solution Files**:
    - ⚡ **Optimal**: [`15. 3Sum.cpp`](./15.%203Sum.cpp) ($\mathcal{O}(N^2)$ Time, $\mathcal{O}(1)$ Space)
    - 🟡 **Hash Set**: [`15. 3Sum Brute N2.c++`](./15.%203Sum%20Brute%20N2.c%2B%2B) ($\mathcal{O}(N^2 \log K)$ Time, $\mathcal{O}(N + K)$ Space)
    - 🔴 **Brute Force**: [`15. 3Sum Brute.cpp`](./15.%203Sum%20Brute.cpp) ($\mathcal{O}(N^3 \log K)$ Time)
  - **Difficulty**: Medium
  - **Pattern**: Two Pointers (Sort + Anchor + Two Pointers)
  - **Time Complexity**: $\mathcal{O}(N^2)$
  - **Space Complexity**: $\mathcal{O}(1)$ auxiliary (excluding output)
  - **Approach**: Sort the array. Iterate `i` from $0$ to $n-1$, skipping duplicates where `nums[i] == nums[i-1]`. For each fixed element `nums[i]`, initialize `j = i + 1` and `k = n - 1` to search for pairs summing to `-nums[i]`. When a triplet is found, advance both pointers and skip subsequent duplicate values for both `j` and `k`.

- [x] **Problem 5**: [3Sum Closest (LeetCode #16)](https://leetcode.com/problems/3sum-closest/)
  - **Solution File**: [`3Sum Closest.cpp`](./3Sum%20Closest.cpp)
  - **Difficulty**: Medium
  - **Pattern**: Two Pointers (Sort + Anchor + Two Pointers with Difference Tracking)
  - **Time Complexity**: $\mathcal{O}(N^2)$
  - **Space Complexity**: $\mathcal{O}(1)$
  - **Approach**: Sort the array. For each index `i`, run two pointers `j = i + 1` and `k = n - 1`. Calculate `sum = nums[i] + nums[j] + nums[k]`. If `sum == target`, return immediately. Track and minimize `diff = abs(sum - target)`. If `sum < target`, increment `j`; if `sum > target`, decrement `k`.

---

## 💡 Key Takeaways & Review Notes

1. **Power of Sorting**:
   - In Two Pointers, sorting upfront ($\mathcal{O}(N \log N)$) enables monotonic decisions (`sum < target` means only increasing `left` can help, and `sum > target` means only decreasing `right` can help).
2. **Duplicate Avoidance without Sets**:
   - In 3Sum, skipping duplicates directly via pointer increments (`while (j < k && nums[j] == nums[j-1]) j++;`) avoids high memory overhead and $\log K$ overhead of `std::set`.
3. **Early Termination in 3Sum**:
   - Since the array is sorted, if `nums[i] > 0`, any sum `nums[i] + nums[j] + nums[k]` must be $> 0$. You can immediately `break` out of the loop.
4. **Code Quality Tip**:
   - In `Remove Duplicates from Sorted Array`, `r++` was duplicated in both `if` and `else` branches. Refactoring to a simple `for (int r = 1; r < nums.size(); r++)` removes redundancy.
