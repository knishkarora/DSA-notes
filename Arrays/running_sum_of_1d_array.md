# Running Sum of 1d Array

**LeetCode:** https://leetcode.com/problems/running-sum-of-1d-array/description/

**Topic:** Arrays / Prefix Sum  
**Difficulty:** Easy

---

## Problem Summary

Given an array `nums`, we define a running sum of an array as:

```text
runningSum[i] = sum(nums[0] … nums[i])
```

Return the running sum of `nums`.

---

## Approach 1 — Running Sum with Extra Result Array

Keep an accumulator variable `sum` that stores the running total of elements as we iterate through the array, and store each step's total into a new vector.

### Steps:

1. Create a result vector `runningSum` of size `nums.size()`.
2. Initialize `sum = 0`.
3. Loop through `i` from `0` to `nums.size() - 1`:
   - Add `nums[i]` to `sum`.
   - Store `sum` into `runningSum[i]`.
4. Return `runningSum`.

### Code

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> runningSum(nums.size());
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum = nums[i] + sum;
            runningSum[i] = sum;
        }

        return runningSum;
    }
};
```

### Complexity

- **Time:** `O(n)` — Single loop through the array of length `n`.
- **Space:** `O(n)` — To store and return the output array `runningSum` (`O(1)` auxiliary space).

---

## Approach 2 — In-Place Prefix Sum (O(1) Auxiliary Space)

If we are allowed to mutate the input array `nums`, we don't even need an extra vector or accumulator variable.

Every running sum at index `i` is just the previous running sum plus the current element:

```text
nums[i] = nums[i] + nums[i - 1]
```

### Code

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
```

### Complexity

- **Time:** `O(n)` — One pass starting from index `1`.
- **Space:** `O(1)` — Overwrites input array in-place without allocating any extra memory.

---

## What I Learned

- **Prefix Sum Foundation:** This is the canonical introduction to the **Prefix Sum** pattern.
- **Range Queries:** Precomputing prefix sums allows calculating the sum of any subarray between indices `L` and `R` in `O(1)` time:
  ```text
  sum(L, R) = prefix[R] - prefix[L - 1]
  ```
- **In-Place Optimization:** Reusing prior results (`nums[i - 1]`) eliminates redundant work and extra variables.

---

## Revision Notes

**Pattern:** Prefix Sum  
**Core Formula:** `runningSum[i] = runningSum[i - 1] + nums[i]`  
**Time Complexity:** `O(n)`  
**Space Complexity:** `O(n)` with new array / `O(1)` in-place

---