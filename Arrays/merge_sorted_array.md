# Merge Sorted Array

**LeetCode:** https://leetcode.com/problems/merge-sorted-array/description/

**Topic:** Arrays / Two Pointers / Sorting  
**Difficulty:** Easy

---

## Problem Summary

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

**Constraints:**
- Must modify `nums1` **in-place**.
- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`

---

## Approach 1 — Forward Merge with Extra Result Array (Initial Intuition)

The most intuitive approach is similar to the standard **Merge** step of Merge Sort:
Use two pointers starting at index `0` for both `nums1` and `nums2`, pick the smaller element at each step, and append it to an auxiliary array `result`. Finally, copy `result` back into `nums1`.

### Initial 4-Branch Implementation

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(nums1.size());
        int index = 0;
        int i = 0;
        int j = 0;

        while (i < m || j < n) {
            if (i >= m && j < n) {
                result[index] = nums2[j];
                index++;
                j++;       
            } else if (i < m && j >= n) {
                result[index] = nums1[i];
                index++;
                i++;                
            } else if (nums1[i] <= nums2[j]) {
                result[index] = nums1[i];
                index++;
                i++;
            } else {
                result[index] = nums2[j];
                index++;
                j++;
            }
        }

        nums1 = result;
    }
};
```

### Simplifying the Forward Conditions

Notice that `result` takes from `nums1[i]` whenever:
1. `nums2` is already exhausted (`j >= n`), OR
2. Both have elements remaining (`i < m`), and `nums1[i] <= nums2[j]`.

In all other cases, it takes from `nums2[j]`:

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(nums1.size());
        int index = 0;
        int i = 0;
        int j = 0;

        while (i < m || j < n) {
            if (j >= n || (i < m && nums1[i] <= nums2[j])) {
                result[index] = nums1[i];
                index++;
                i++;
            } else {
                result[index] = nums2[j];
                index++;
                j++;
            }
        }

        nums1 = result;
    }
};
```

### Complexity

- **Time:** `O(m + n)` — Single pass over both arrays plus copying `result` back to `nums1`.
- **Space:** `O(m + n)` — Allocates an auxiliary vector `result` of size `m + n`.

### Why Optimize?

Although `O(m + n)` time is optimal, allocating an extra vector violates the spirit of the problem:
`nums1` already has a total length of `m + n`, with `n` empty slots at the end waiting to be used!

---

## Thinking Toward In-Place Merging

If we try to merge directly into `nums1` from left to right (`index = 0`):
- If `nums2[0] < nums1[0]`, placing `nums2[0]` at `nums1[0]` would **overwrite** `nums1[0]` before we've had a chance to compare or copy it.
- To prevent overwriting, where is the available empty space?
  The free space (the `0`s) is located at the **back** of `nums1` (`m` to `m + n - 1`).

> **Key Realization:**  
> If we place elements from **largest to smallest** starting at the end (`index = m + n - 1`), we fill the empty space first and will **never overwrite** an unprocessed element of `nums1`!

---

## Approach 2 — Backward Three Pointers (In-Place, O(1) Space)

Maintain three pointers:
- `i = m - 1`: points to the last unplaced element in the valid part of `nums1`.
- `j = n - 1`: points to the last unplaced element in `nums2`.
- `index = m + n - 1`: points to the target write position at the end of `nums1`.

### Evolution of Conditions

#### Version 2A — Explicit Boundary Check with Early Exit:
When `j < 0`, all elements of `nums2` are placed. The remaining elements in `nums1` are already in their sorted positions, so we can `break` early:

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = nums1.size() - 1;
        int i = m - 1;
        int j = n - 1;

        while (i >= 0 || j >= 0) {
            if (j < 0 && i >= 0) {
                break;
            } else if (j >= 0 && (i < 0 || nums2[j] >= nums1[i])) {
                nums1[index] = nums2[j];
                j--;
                index--;               
            } else {
                nums1[index] = nums1[i];
                i--;
                index--;    
            }
        }
    }
};
```

---

### Canonical Clean Implementation

Since we only need to continue placing elements until `nums2` is completely merged (`j >= 0`), the loop condition can simply be `while (j >= 0)`:

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int index = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[index--] = nums1[i--];
            } else {
                nums1[index--] = nums2[j--];
            }
        }
    }
};
```

### Steps:

1. Set `i = m - 1`, `j = n - 1`, `index = m + n - 1`.
2. Loop while `j >= 0`:
   - If `i >= 0` and `nums1[i] > nums2[j]`, place `nums1[i]` at `nums1[index]`, decrement `i` and `index`.
   - Otherwise, place `nums2[j]` at `nums1[index]`, decrement `j` and `index`.
3. If `j < 0`, any remaining elements in `nums1` are already in their correct places.

### Complexity

- **Time:** `O(m + n)` — Each comparison places one element in its final position at `index`. At most `m + n` iterations.
- **Space:** `O(1)` — Modifies `nums1` completely in-place without allocating auxiliary memory.

---

## Optimization Journey Summary

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **1A. Forward Merge (Verbose)** | `O(m + n)` | `O(m + n)` | Uses extra array with 4 explicit boundary conditions. |
| **1B. Forward Merge (Clean)** | `O(m + n)` | `O(m + n)` | Combined conditions; still allocates $O(m + n)$ auxiliary space. |
| **2A. Backward Merge (Break on j < 0)** | `O(m + n)` | `O(1)` | In-place backward placement avoiding overwrite with early exit. |
| **2B. Backward Merge (Canonical Clean)** | `O(m + n)` | `O(1)` | Most elegant: runs `while (j >= 0)`, stops as soon as `nums2` is consumed. |

---

## What I Learned

1. **Direction Changes Everything in In-Place Algorithms:** Forward traversal overwrites unread elements in `nums1`. Backward traversal leverages the empty buffer space at the end, eliminating overwrites entirely.
2. **Buffer Utilization:** The padded zeroes at the end of `nums1` provide the exact buffer needed to accumulate the merged array in-place without auxiliary memory.
3. **Loop Termination Insight:** If `nums2` runs out first (`j < 0`), whatever is left in `nums1` is already sorted and already in place (`nums1[0...i]`), meaning no extra work is needed.

---

## Revision Notes

**Pattern:** Two Pointers / Backward In-Place Merge  
**Key Logic:** Compare from the back (`m - 1` vs `n - 1`), write to `m + n - 1`. Run `while (j >= 0)`.  
**Time Complexity:** `O(m + n)`  
**Space Complexity:** `O(1)` in-place  

---