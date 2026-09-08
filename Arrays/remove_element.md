# Remove Element

**LeetCode:** https://leetcode.com/problems/remove-element/description/

**Topic:** Arrays / Two Pointers  
**Difficulty:** Easy

---

## Problem Summary

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` **in-place**. The order of the elements may be changed.

Return `k`, the number of elements in `nums` which are not equal to `val`.

To get accepted, you must:
1. Modify `nums` such that the first `k` elements contain the elements which are not equal to `val`.
2. The remaining elements beyond index `k - 1` do not matter.
3. Do this with **$O(1)$ extra memory**.

---

## Approach 1 — Filter with Extra Vector (Initial Intuition)

The most straightforward initial idea is to create a temporary vector, iterate through `nums`, and only collect elements that are **not** equal to `val`. Afterwards, copy the result back into `nums`.

### Steps:

1. Create a helper vector `count` of the same size as `nums`.
2. Keep a pointer `index = 0` to track the insert position in `count`.
3. Loop through `nums`:
   - If `nums[i] != val`, assign `count[index] = nums[i]` and increment `index`.
4. Copy `nums = count` and return `index` (the count of valid elements).

### Code

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> count(nums.size());
        int index = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                count[index] = nums[i];
                index++;
            }
        }

        nums = count;
        return index;
    }
};
```

### Complexity

- **Time:** `O(n)` — Single pass through `nums` plus the vector copy.
- **Space:** `O(n)` — Allocates an extra vector `count` of size `n`.

### Why Optimize?

While correct and intuitive, this approach violates the core constraint of the problem: **in-place modification with $O(1)$ auxiliary space**.

---

## Thinking Toward In-Place Removal

To avoid allocating extra memory, we have to modify `nums` directly.

A natural thought is:
> *"Whenever I encounter an element equal to `val`, why not delete it and shift all subsequent elements one spot to the left?"*

---

## Approach 2 — In-Place with Left Shifting (O(1) Space, O(n²) Time)

Instead of using an extra vector, we iterate through `nums`. Whenever we find `nums[i] == val`:
1. Shift every element from `i + 1` to `nums.size() - 1` one step to the left.
2. Remove the last element using `nums.pop_back()`.
3. Decrement `i` by 1 (`i--`) so that the newly shifted element now at index `i` will be examined next.

### Code

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                index++;
            } else {
                for(int j = i; j < nums.size() - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                i--;
                nums.pop_back();
            }
        }

        return index;
    }
};
```

### Complexity

- **Time:** `O(n²)` in the worst case — Each time `nums[i] == val`, the inner loop shifts up to `n` elements. If many elements match `val`, the shifting repeated across the array results in quadratic time.
- **Space:** `O(1)` — Modifies the array directly without allocating extra space.

### Why Optimize?

We achieved $O(1)$ space, but at the expense of time complexity (`O(n²)` due to element shifting).

---

## Thinking Toward the Optimal Approach

Re-reading the problem description carefully reveals an important detail:

> **"The order of the elements may be changed."**

This is a crucial clue:
- In Approach 2, we shifted all elements to preserve the original relative order.
- But if **order does not matter**, why pay `O(n)` to shift everything?
- When we find an element equal to `val`, we can simply **replace it with the last element of the array** (`nums.back()`) and shrink the array by 1 using `nums.pop_back()`.

This turns an $O(n)$ shifting operation into an **$O(1)$ replacement**!

---

## Approach 3 — Overwrite with Last Element (Optimal: O(n) Time, O(1) Space)

Whenever `nums[i] == val`:
1. Overwrite `nums[i]` with `nums.back()`.
2. Remove the back element using `nums.pop_back()`.
3. Decrement `i` (`i--`) to ensure the newly placed element at index `i` is checked in the next iteration.

### Code

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                index++;
            } else {
                nums[i] = nums.back();
                i--;
                nums.pop_back();
            }
        }

        return index;
    }
};
```

### Complexity

- **Time:** `O(n)` — Every step either advances `i` or reduces the array size via `pop_back()`. At most `n` steps occur in total. This is especially fast when occurrences of `val` are rare.
- **Space:** `O(1)` — In-place with zero extra memory allocated.

---

## Alternative Canonical Pattern — Two Pointers (Reader & Writer)

In standard DSA interviews, the canonical way to solve this problem without modifying vector size (`pop_back()`) is the **Two-Pointer (Reader / Writer)** pattern:

Notice that in **Approach 1**, we already had this logic:
```cpp
if(nums[i] != val) {
    count[index] = nums[i];
    index++;
}
```
Instead of writing to `count`, we can write directly back to `nums`!

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int writer = 0;

        for(int reader = 0; reader < nums.size(); reader++) {
            if(nums[reader] != val) {
                nums[writer] = nums[reader];
                writer++;
            }
        }

        return writer;
    }
};
```

- **`reader`** scans every element in `nums`.
- **`writer`** keeps track of where the next non-`val` element should be placed.
- Preserves relative order and runs in `O(n)` time with `O(1)` space without resizing the vector.

---

## Optimization Journey Summary

| Approach | Time Complexity | Space Complexity | Pros & Cons |
| :--- | :--- | :--- | :--- |
| **1. Extra Vector** | `O(n)` | `O(n)` | Simple and intuitive, but violates the $O(1)$ space requirement. |
| **2. Left Shifting** | `O(n²)` | `O(1)` | In-place, but shifting elements creates an unnecessary nested loop. |
| **3. Swap with Last** | `O(n)` | `O(1)` | Leverages *"order doesn't matter"* to replace $O(n)$ shifts with $O(1)$ operations. |
| **Two Pointers (Canonical)** | `O(n)` | `O(1)` | Standard in-place filter pattern; no vector resizing needed. |

---

## What I Learned

1. **Read Constraints Carefully:** The statement *"The order of the elements may be changed"* is the key to avoiding costly $O(n)$ shifts.
2. **Cost of Array Deletion:** Removing an element from the middle of an array and shifting subsequent elements is an $O(n)$ operation. Avoiding this shift is key to getting from $O(n^2)$ down to $O(n)$.
3. **From Extra Space to Two Pointers:** When you write `new_array[index++] = arr[i]`, you're already using a two-pointer technique. Rewriting the output into the same array (`arr[writer++] = arr[reader]`) makes it in-place.

---

## Revision Notes

**Pattern:** Two Pointers / In-Place Overwrite  
**Key Trick:** When order doesn't matter, replace `nums[i]` with `nums.back()` and pop back.  
**Brute Force (Extra Space):** `O(n)` time, `O(n)` space  
**In-Place Shifting:** `O(n²)` time, `O(1)` space  
**Optimal (Swap with Last / Two Pointers):** `O(n)` time, `O(1)` space  

---