# Plus One

**LeetCode:** https://leetcode.com/problems/plus-one/

**Topic:** Arrays / Math / Simulation  
**Difficulty:** Easy

---

## Problem Summary

You are given a large integer represented as an integer array `digits`, where each `digits[i]` is the $i$-th digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading `0`'s.

Increment the large integer by one and return the resulting array of digits.

---

## Approach 1 — Right-to-Left Traversal with In-Place Mutation & Insertion

Since addition starts from the least significant digit (the rightmost digit), we traverse the array backwards starting from `digits.size() - 1` down to `0`.

### Steps:

1. Traverse backwards from `i = digits.size() - 1` down to `0`:
   - If `digits[i] != 9`, simply increment `digits[i]++` and `break` (no further carry).
   - If `digits[i] == 9`, set `digits[i] = 0` (carry propagates to the left).
2. After the loop, check if `digits[0] == 0`:
   - This occurs only when all digits were `9` (e.g., `999` becomes `000`).
   - Insert `1` at the beginning using `digits.insert(digits.begin(), 1)`.
3. Return `digits`.

### Code

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                break;
            } else {
                digits[i] = 0;
            }
        }

        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1); 
        }

        return digits;
    }
};
```

### Complexity

- **Time:** `O(n)` in the worst case (when all digits are `9`, requiring traversal of `n` elements and an `O(n)` front insertion). On average, `O(1)` if the last digit is not `9`.
- **Space:** `O(1)` auxiliary space (in-place modification, though `vector::insert` at the beginning may reallocate the vector buffer).

---

## Approach 2 — Early Return & Clean Vector Reallocation (Canonical Pattern)

Instead of breaking and checking `digits[0] == 0` after the loop, we can return immediately as soon as a non-9 digit is incremented. If the loop completes, all digits were `9`, so we can cleanly construct a new vector of size `n + 1` with a leading `1` and trailing zeros.

### Steps:

1. Loop backwards from `i = n - 1` down to `0`:
   - If `digits[i] < 9`:
     - Increment `digits[i]++`.
     - Immediately return `digits`.
   - Otherwise, set `digits[i] = 0`.
2. If the loop finishes without returning, all digits were `9` (e.g., `999 -> 1000`):
   - Allocate a new vector of size `n + 1` filled with `0`.
   - Set `result[0] = 1`.
   - Return `result`.

### Code

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // All digits were 9 (e.g., 99 -> 100)
        vector<int> result(n + 1, 0);
        result[0] = 1;
        return result;
    }
};
```

### Complexity

- **Time:** `O(n)` worst case (all 9s), `O(1)` best/average case.
- **Space:** `O(1)` auxiliary space for general cases; `O(n)` space to allocate the new vector only when all digits overflow.

---

## Optimization Journey Summary

| Approach | Time Complexity | Space Complexity | Description |
| :--- | :--- | :--- | :--- |
| **1. Backwards Loop + `insert`** | `O(n)` worst / `O(1)` avg | `O(1)` aux | Mutates in-place; handles all-9s using `digits.insert(begin, 1)`. |
| **2. Early Return + Sized Vector** | `O(n)` worst / `O(1)` avg | `O(1)` aux | Returns immediately when carry ends; builds `vector(n + 1, 0)` for overflow. |

---

## What I Learned

1. **Right-to-Left Carry Propagation:** Addition with carry naturally flows from the least significant digit (end of array) to the most significant digit (start of array).
2. **Early Exit on Non-9:** Carry only ripples as long as consecutive digits from the right are `9`. The first digit `< 9` absorbs the carry, allowing an immediate exit.
3. **The All-9s Boundary Case:** When all digits are `9` (e.g., `999`), the resulting number has `n + 1` digits, always taking the form `1` followed by `n` zeroes (`1000`).
4. **`insert()` vs Vector Sizing:** Inserting at the beginning of a `std::vector` is an `O(n)` operation because all elements must shift right. Constructing `vector<int>(n + 1, 0)` with `result[0] = 1` is cleaner and avoids element shifts.

---

## Revision Notes

**Pattern:** Right-to-Left Traversal / Carry Simulation  
**Key Logic:** Increment and return if `< 9`, otherwise set to `0`. If loop finishes, return `[1, 0, 0, ...]`.  
**Time Complexity:** `O(n)` worst case, `O(1)` average case  
**Space Complexity:** `O(1)` auxiliary space (or `O(n)` for all-9s case)

---