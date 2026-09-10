# Remove Duplicates from Sorted Array

**LeetCode:** https://leetcode.com/problems/remove-duplicates-from-sorted-array/

**Topic:** Arrays / Two Pointers  
**Difficulty:** Easy

---

## Problem Summary

Given an integer array `nums` sorted in **non-decreasing order**, remove the duplicates **in-place** such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in `nums` to be `k`. After removing duplicates, return `k`.

To get accepted, you must:
1. Modify `nums` such that the first `k` elements contain the unique elements in the order they were present initially.
2. The remaining elements beyond index `k - 1` do not matter.
3. Do this with **$O(1)$ extra memory**.

---

## Approach 1 — Brute Force with Extra Vector (Initial Intuition)

My initial idea was to create an auxiliary vector `unique`, and for each element in `nums`, check if it had already been stored in `unique` by linearly searching through it.

### Steps:

1. Create a helper vector `unique` of size `nums.size()`.
2. Maintain `index = 0` to track the count of unique elements placed.
3. Iterate through `nums` with `i`:
   - Linearly scan `unique` from `0` to `index - 1` to see if `nums[i]` is already present.
   - If not found, assign `unique[index] = nums[i]` and increment `index`.
4. Copy `unique` back to `nums` and return `index`.

### Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> unique(nums.size());
        int index = 0;

        for (int i = 0; i < nums.size(); i++) {
            bool found = false;
            for (int j = 0; j < index; j++) {
                if (nums[i] == unique[j]) {
                    found = true;
                    break;
                }
            }
            if (found == false) {
                unique[index] = nums[i];
                index++;
            }
        }

        nums = unique;
        return index;
    }
};
```

### Complexity

- **Time:** `O(n²)` — For each element, a linear search across the accumulated `unique` list is performed.
- **Space:** `O(n)` — Allocates an extra vector `unique` of size `n`.

### Why Optimize?

- Fails the problem constraint: Requires **$O(1)$ auxiliary space**.
- Does not leverage the fact that `nums` is already **sorted**.
- Quadratic time complexity makes it too slow for large inputs.

---

## Approach 2 — Attempted In-Place Left Shifting (Why It Was Dropped)

Next, I attempted an in-place approach without an extra vector by checking whether the current element appeared previously, and if so, shifting the neighboring element left:

### Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            bool found = false;
            for (int j = 0; j < i; j++) {
                if (nums[i] == nums[j]) {
                    found = true;
                    break;
                }
            }
            if (found == true) {
                nums[i] = nums[i + 1];
                i--;
            } else {
                index++;
            }
        }

        return index;
    }
};
```

### Why This Idea Failed & Was Dropped:

1. **Partial Shift:** `nums[i] = nums[i + 1]` only shifts a single neighbor, leaving the rest of the array unshifted and causing duplicate/stale values.
2. **Ignored Sorted Property:** Scanning `j < i` is an $O(n^2)$ check that ignores the fact that duplicates in a sorted array are always grouped next to each other.
3. **Index Instability:** Decrementing `i` inside the loop while mutating elements creates tricky edge cases and potential boundary issues.

---

## Approach 3 — Two Pointers Leveraging Sorted Property (Optimal)

### Key Realization:

Because the array is **sorted**, all duplicate elements are strictly adjacent to one another! 

We do **not** need to search backwards through earlier elements or maintain a separate array. We only need to compare each element against the last recorded unique element.

### Steps:

1. Maintain an `index = 0` representing the position of the last confirmed unique element.
2. Iterate `i` from `1` to `nums.size() - 1`:
   - If `nums[index] != nums[i]`, we found a new unique number.
   - Advance `index` by 1 and write `nums[index] = nums[i]`.
3. Return `index + 1` (the total count of unique elements).

### Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[index] != nums[i]) {
                nums[index + 1] = nums[i];
                index++;
            }
        }

        return index + 1;
    }
};
```

### Complexity

- **Time:** `O(n)` — A single pass through the array from left to right.
- **Space:** `O(1)` — Overwrites duplicates directly in-place with no extra memory allocated.

---

## Alternative Canonical Pattern — Reader / Writer Pointers

A slightly different and common interview phrasing of the same two-pointer idea:

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int writer = 1;

        for (int reader = 1; reader < nums.size(); reader++) {
            if (nums[reader] != nums[reader - 1]) {
                nums[writer] = nums[reader];
                writer++;
            }
        }

        return writer;
    }
};
```

- **`reader`:** Scans every element starting from index 1.
- **`writer`:** Tracks the next slot where a new unique element should be written.
- Whenever `nums[reader] != nums[reader - 1]`, a new unique block begins.

---

## Optimization Journey Summary

| Approach | Time Complexity | Space Complexity | Status | Pros & Cons |
| :--- | :--- | :--- | :--- | :--- |
| **1. Extra Vector + Linear Search** | `O(n²)` | `O(n)` | Working | Intuitive first thought, but violates $O(1)$ space and is $O(n²)$. |
| **2. In-Place Left Shifting** | `O(n²)` | `O(1)` | Dropped | Buggy; shifting single neighbors does not compact the array properly. |
| **3. Two Pointers (Last Unique)** | `O(n)` | `O(1)` | **Optimal** | Leverages sorted property; single pass, clean in-place overwrite. |
| **Reader / Writer Pattern** | `O(n)` | `O(1)` | **Optimal** | Clean canonical form comparing adjacent elements (`reader` vs `reader - 1`). |

---

## What I Learned

1. **Leverage Array Properties:** Sorted arrays mean duplicates are adjacent. You never need to search globally when local adjacency gives you the answer in $O(1)$.
2. **Two-Pointer Compaction:** The fast pointer (`i` / `reader`) explores new data, while the slow pointer (`index` / `writer`) maintains the boundary of the processed unique subarray.
3. **Avoid Manual Shifting:** Shifting elements manually one-by-one is almost always an antipattern for array filtering; write-pointer overwrites achieve the same result in $O(n)$ time.

---

## Revision Notes

**Pattern:** Two Pointers (Slow & Fast / In-Place Compaction)  
**Key Condition:** Since array is sorted, check `nums[i] != nums[index]` (or `nums[reader] != nums[reader - 1]`)  
**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)`  

---