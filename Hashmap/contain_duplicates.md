# Contains Duplicate

**LeetCode:** https://leetcode.com/problems/contains-duplicate/description/

**Topic:** Hash Table / Arrays  
**Difficulty:** Easy

---

## Problem Summary

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

---

## Approach 1 — Brute Force (Nested Loops)

Check every possible pair in the array to see if any two elements are equal.

### Steps:

1. Use an outer loop running from `i = 0` to `nums.size() - 2`.
2. Use an inner loop running from `j = i + 1` to `nums.size() - 1`.
3. If `nums[i] == nums[j]`, a duplicate exists; return `true`.
4. If loops finish without finding any duplicate, return `false`.

### Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

### Complexity

- **Time:** `O(n^2)` — Comparing every pair of elements takes quadratic time.
- **Space:** `O(1)` — No extra auxiliary data structures used.

---

## Approach 2 — Hash Map (Tracking Seen Elements)

Store the elements seen so far in an `unordered_map`. Before storing each element, check if it already exists in the map.

### Steps:

1. Initialize an `unordered_map<int, int> mp`.
2. Iterate through each element `nums[i]`.
3. Check if `nums[i]` is already in `mp` (`mp.find(nums[i]) != mp.end()`).
4. If found, return `true`.
5. Otherwise, store `mp[nums[i]] = i`.
6. If the iteration finishes without finding any duplicate, return `false`.

### Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) != mp.end()) {
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
```

### Complexity

- **Time:** `O(n)` — Hash map lookups and insertions take `O(1)` average time.
- **Space:** `O(n)` — In the worst case (all elements distinct), the hash map stores all `n` elements.

---

## Approach 3 — Hash Set (Optimal & Idiomatic)

Since we only need to track the presence of elements and don't need indices or counts, an `unordered_set` is the most suitable and memory-efficient container.

### Steps:

1. Initialize an `unordered_set<int> st`.
2. Iterate through each number in `nums`.
3. If `nums[i]` already exists in `st`, return `true`.
4. Otherwise, insert `nums[i]` into `st`.
5. If the loop completes without finding duplicates, return `false`.

### Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            if(st.find(nums[i]) != st.end()) {
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};
```

### Complexity

- **Time:** `O(n)` — Average `O(1)` lookup and insertion per element across `n` elements.
- **Space:** `O(n)` — Stores up to `n` elements in the set.

---

## What I Learned

- **Set vs Map:** When you only need to check for existence of elements, `unordered_set` is cleaner and uses less memory overhead than `unordered_map`.
- **Trading Space for Time:** Moving from nested loops (`O(n^2)`) to hashing (`O(n)`) significantly improves runtime at the cost of `O(n)` memory.

---

## Revision Notes

**Pattern:** Hash Set / Hash Map existence check  
**Key Logic:** `if (st.find(x) != st.end()) return true; st.insert(x);`  
**Brute Force Time:** `O(n^2)`  
**Optimal Time:** `O(n)`  
**Space Complexity:** `O(n)` (or `O(1)` if sorting in-place in `O(n log n)` time)

---