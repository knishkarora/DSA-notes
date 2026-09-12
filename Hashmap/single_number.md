# Single Number

**LeetCode:** https://leetcode.com/problems/single-number/description/

**Topic:** Hash Table / Bit Manipulation  
**Difficulty:** Easy

---

## Problem Summary

Given a non-empty array of integers `nums`, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

---

## Approach 1 — Hash Map (Frequency Counter)

Count occurrences of each number using an `unordered_map`, then find the element that appeared exactly once.

### Steps:

1. Initialize an `unordered_map<int, int> mp`.
2. First pass: iterate through `nums` and increment frequency `mp[nums[i]]++`.
3. Second pass: iterate through `nums` again and check if `mp[nums[i]] == 1`.
4. Return `nums[i]` if found; return `0` if not found.

### Code

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]] == 1) {
                return nums[i];
            }
        }
        return 0;
    }
};
```

### Complexity

- **Time:** `O(n)` — Two passes over the array of length `n`, with `O(1)` average map operations.
- **Space:** `O(n)` — The hash map stores frequencies for up to `n / 2 + 1` unique elements.

---

## Approach 2 — Bit Manipulation (XOR Operation) — Optimal

Use the properties of the bitwise XOR (`^`) operator:
1. `x ^ x = 0` (any number XORed with itself becomes `0`)
2. `x ^ 0 = x` (any number XORed with `0` remains unchanged)
3. XOR is associative and commutative.

Since every number except one appears exactly twice, all pairs cancel out to `0`, leaving only the unique single number.

### Steps:

1. Initialize `result = nums[0]`.
2. Iterate through the array starting from index `1` to `nums.size() - 1`.
3. XOR each element with `result`: `result = result ^ nums[i]`.
4. Return `result`.

### Code

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            result = result ^ nums[i];
        }
        return result;
    }
};
```

### Complexity

- **Time:** `O(n)` — Single pass over `nums` performing `O(1)` bitwise operations.
- **Space:** `O(1)` — Only a single integer variable `result` is used, satisfying the constant extra space requirement.

---

## What I Learned

- **XOR Self-Inverse Property:** XOR is ideal for pairing / cancellation problems where duplicates occur in even counts.
- **Constraint Awareness:** The problem requires `O(1)` auxiliary space. While the Hash Map approach is intuitive and linear in time, it violates the constant space constraint; XOR satisfies both conditions.

---

## Revision Notes

**Pattern:** Bit Manipulation / XOR cancellation  
**Key Logic:** `result ^= nums[i]` (duplicates cancel: `a ^ a = 0`)  
**Hash Map Time / Space:** `O(n)` time, `O(n)` space  
**Optimal Time / Space:** `O(n)` time, `O(1)` space  

---