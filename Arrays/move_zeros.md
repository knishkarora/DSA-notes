# Move Zeroes

**LeetCode:** https://leetcode.com/problems/move-zeroes/

**Topic:** Arrays / Two Pointers  
**Difficulty:** Easy

---

## Problem Summary

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Constraints:**
- You must do this **in-place** without making a copy of the array.
- Minimize the total number of operations.

---

## Approach 1 — Two Passes (Shift Non-Zeros & Backfill Zeros)

The most direct in-place intuition is to do this in two passes:
1. In the first pass, compress all non-zero elements to the front using a pointer `index`.
2. In the second pass, fill the remainder of the array (from `index` to the end) with `0`.

### Steps:

1. Initialize `index = 0` to track the insertion point for non-zero elements.
2. Iterate `i` from `0` to `n - 1`:
   - If `nums[i] != 0`, assign `nums[index] = nums[i]` and increment `index`.
3. In a second loop, iterate from `n - 1` down to `index` (or `index` up to `n - 1`), setting each `nums[i] = 0`.

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }

        for (int i = n - 1; i >= index; i--) {
            nums[i] = 0;
        }
    }
};
```

### Complexity

- **Time:** `O(n)` — Two sequential linear passes over the array of size `n`.
- **Space:** `O(1)` — Modifies the array in-place without allocating extra space.

---

## Approach 2 — Two Passes with Explicit Zero Counter

A variation of the two-pass approach where we explicitly count how many zeros are encountered during the first pass.

### Steps:

1. Initialize `index = 0` and `zeros = 0`.
2. Loop through `nums`:
   - If `nums[i] != 0`, assign `nums[index] = nums[i]` and increment `index`.
   - Else, increment `zeros`.
3. In the second pass, fill the last `zeros` positions (from `n - 1` down to `n - zeros`) with `0`.

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int zeros = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            } else {
                zeros++;
            }
        }

        for (int i = n - 1; i >= n - zeros; i--) {
            nums[i] = 0;
        }
    }
};
```

### Complexity

- **Time:** `O(n)` — Two sequential passes over the array.
- **Space:** `O(1)` — In-place modification with minimal integer state variables.

---

## Approach 3 — Single Pass (Immediate Zero Clearing)

Instead of waiting for a second loop to backfill zeros, we can clear them in the same pass.

Whenever we find a non-zero element at index `i`, we move it to `nums[index]`. If `i != index` (which indicates that at least one zero was skipped earlier), the position at `i` is vacated and can immediately be set to `0`.

### Steps:

1. Initialize `index = 0`.
2. Traverse `i` from `0` to `n - 1`:
   - If `nums[i] != 0`:
     - Assign `nums[index] = nums[i]`.
     - If `i != index`, set `nums[i] = 0`.
     - Increment `index`.

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[index] = nums[i];
                if (i != index) {
                    nums[i] = 0;
                }
                index++;
            }
        }
    }
};
```

### Complexity

- **Time:** `O(n)` — Accomplished in a single pass over the array.
- **Space:** `O(1)` — Modifies elements in-place with no additional data structures.

---

## Alternative Canonical Pattern — Two Pointers with Swap

In standard interviews, the canonical one-pass implementation uses `std::swap`:

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[index], nums[i]);
                index++;
            }
        }
    }
};
```

- **`index` (Writer):** Points to the position where the next non-zero element should go (or the first known zero).
- **`i` (Reader):** Scans forward looking for non-zero elements.
- Swapping automatically places the non-zero element at `index` and pushes the `0` to index `i`, eliminating any conditional checks.

---

## Optimization Journey Summary

| Approach | Time Complexity | Space Complexity | Passes | Description |
| :--- | :--- | :--- | :--- | :--- |
| **1. Overwrite & Fill Remaining** | `O(n)` | `O(1)` | 2 passes | Shift non-zeros forward, then fill remaining slots with `0`. |
| **2. Overwrite & Count Zeros** | `O(n)` | `O(1)` | 2 passes | Track zero count, then fill the last `zeros` positions with `0`. |
| **3. Immediate Zero Clearing** | `O(n)` | `O(1)` | 1 pass | Overwrite at `index`, clear at `i` if `i != index`. |
| **Two Pointers with Swap** | `O(n)` | `O(1)` | 1 pass | Standard canonical solution using `swap(nums[index++], nums[i])`. |

---

## What I Learned

1. **Reader / Writer Separation:** Using a separate read index (`i`) and write index (`index`) allows filtering or partitioning an array in-place without losing data.
2. **One Pass vs Two Passes:** A second pass to fill trailing zeros is conceptually simple, but combining write-and-clear (or swapping) compresses the logic into a clean single pass.
3. **Power of `swap`:** Swapping avoids needing an `if (i != index)` branch or separate clearing assignment, naturally pushing zeros towards the end.

---

## Revision Notes

**Pattern:** Two Pointers (Reader / Writer / Partition)  
**Key Logic:** `swap(nums[index++], nums[i])` when `nums[i] != 0`  
**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)`  

---
