# Two Sum

**LeetCode:** https://leetcode.com/problems/two-sum/description/

**Topic:** Hash Table / Arrays  
**Difficulty:** Easy

---

## Problem Summary

You are given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

---

## Approach 1 — Brute Force (Nested Loops)

Check every possible pair of numbers in the array to see if their sum matches `target`.

### Steps:

1. Use an outer loop running from `i = 0` to `nums.size() - 2`.
2. Use an inner loop running from `j = i + 1` to `nums.size() - 1`.
3. If `nums[i] + nums[j] == target`, return indices `{i, j}`.
4. If no pair adds up to `target`, return an empty vector `{}`.

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```

### Complexity

- **Time:** `O(n^2)` — Checking all pairs takes quadratic time.
- **Space:** `O(1)` — No auxiliary data structures are used.

---

## Approach 2 — One-Pass Hash Map (Complement Lookup) — Optimal

Instead of checking every other element with a nested loop, we check whether the complement `needed = target - nums[i]` has already been seen and stored in a hash map.

### Steps:

1. Initialize an `unordered_map<int, int> mp` to store `{value -> index}`.
2. Iterate through each index `i` and element `nums[i]`.
3. Compute `int needed = target - nums[i]`.
4. If `needed` already exists in `mp` (`mp.find(needed) != mp.end()`), return `{mp[needed], i}`.
5. Otherwise, store the current element's index in the map: `mp[nums[i]] = i`.
6. Return `{}` if no solution is found.

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];
            if(mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }            
            mp[nums[i]] = i;
        }
        return {};
    }
};
```

### Complexity

- **Time:** `O(n)` — Single pass over `nums` with `O(1)` average lookup and insertion time in `unordered_map`.
- **Space:** `O(n)` — In the worst case, stores up to `n` elements in the hash map.

---

## What I Learned

- **Complement Search Pattern:** Instead of asking "which pair sums to target?", rephrase to "have we seen `target - current` earlier?".
- **One-Pass Insertion Order:** By looking up the complement *before* inserting `nums[i]` into the map, we naturally prevent an element from matching with itself.

---

## Revision Notes

**Pattern:** Complement Lookup / Hash Map  
**Key Logic:** `int needed = target - nums[i]; if (mp.find(needed) != mp.end()) return {mp[needed], i};`  
**Brute Force Time:** `O(n^2)`  
**Optimal Time:** `O(n)`  
**Space Complexity:** `O(n)`  

---