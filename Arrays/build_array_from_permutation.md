# Build Array from Permutation

**LeetCode:** https://leetcode.com/problems/build-array-from-permutation/

**Topic:** Arrays  
**Difficulty:** Easy

---

## Problem Summary

Given a zero-based permutation `nums` (0-indexed), build an array `ans` of the same length where `ans[i] = nums[nums[i]]` for each `0 <= i < nums.length` and return it.

A zero-based permutation `nums` is an array of distinct integers from `0` to `nums.length - 1` (inclusive).

---

## Approach — Direct Mapping with Extra Array

The problem statement gives the formula directly:

```text
ans[i] = nums[nums[i]]
```

### Steps:

1. Create a new vector `ans` of the same size as `nums`.
2. Iterate through each index `i` from `0` to `nums.size() - 1`.
3. For each index `i`, find `nums[i]` and use it as the index to get `nums[nums[i]]`.
4. Assign `ans[i] = nums[nums[i]]`.
5. Return the resulting vector `ans`.

### Code

```cpp
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};
```

### Complexity

- **Time:** `O(n)` — A single pass over the array of size `n`.
- **Space:** `O(n)` — Extra vector `ans` of size `n` to store the result (`O(1)` auxiliary space if output array is not counted).

---

## Thinking Further — In-Place O(1) Extra Space Follow-up

A common follow-up question for this problem is: *Can we do it in `O(1)` extra space without allocating another array?*

### The Mathematical Encoding Trick

Because each element is in the range `[0, n - 1]` where `n = nums.size()`:
We can store two numbers in one position using Euclidean division:

```text
nums[i] = old_value + n * (new_value % n)
```

- When reading the **old value**: `nums[i] % n`
- When extracting the **new value**: `nums[i] / n`

This enables modifying the array in-place without overwriting data needed for upcoming lookups.

---

## What I Learned

- **Dual Nature of Permutations:** Each number `nums[i]` acts both as a value and as a target index.
- **Direct Translation:** Some problems require straightforward translation of the given specification into code without overcomplicating.

---

## Revision Notes

**Pattern:** Array Indexing / Permutation Mapping  
**Formula:** `ans[i] = nums[nums[i]]`  
**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)` (or `O(1)` auxiliary with in-place encoding)

---