# Find Numbers with Even Number of Digits

**LeetCode:** https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

**Topic:** Arrays / Math  
**Difficulty:** Easy

---

## Problem Summary

Given an array `nums` of integers, return how many of them contain an **even number of digits**.

---

## My First Approach — Brute Force (Tail-Recursive Count with Accumulator)

My initial idea was to count the number of digits in each element using a recursive helper function with an accumulator `c`.

### Steps:

1. For each number in `nums`, call helper `count(nums[i], 0)`.
2. In the helper:
   - Base case: If `num <= 0`, return accumulated count `c`.
   - Recursive step: Integer divide `num` by `10`, increment `c`, and recurse.
3. Check if the returned digit count is even (`get % 2 == 0`).
4. If even, increment `counter`.
5. Return `counter`.

### Brute Force Code

```cpp
class Solution {
public:
    int count(int num, int c) {
        if(num <= 0) {
            return c;
        }

        num = num / 10;
        c++;

        return count(num, c);
    }

    int findNumbers(vector<int>& nums) {
        int counter = 0;

        for(int i = 0; i < nums.size(); i++) {
            int get = count(nums[i], 0);

            if(get % 2 == 0) {
                counter++;
            }
        }

        return counter;
    }
};
```

### Complexity

- **Time:** `O(n * d)` — Where `n` is the number of elements and `d` is the number of digits of each element (since `nums[i] <= 10^5`, `d <= 6`).
- **Space:** `O(d)` — Call stack space for recursion (up to `d` frames).

---

## Cleaner Recursive Approach — Pure Recursive Counting

We can simplify the recursive function by removing the accumulator parameter. 

### Insight:

- Base Case: If `num < 10`, it is a single digit, so return `1`.
- Recursive Case: The number of digits in `num` is `1 + count(num / 10)`.

This makes the recursion cleaner and avoids passing extra state.

### Code

```cpp
class Solution {
public:
    int count(int num) {
        if(num < 10) {
            return 1;
        }
        return 1 + count(num / 10);
    }

    int findNumbers(vector<int>& nums) {
        int counter = 0;

        for(int i = 0; i < nums.size(); i++) {
            int get = count(nums[i]);
            if(get % 2 == 0) {
                counter++;
            }
        }

        return counter;
    }
};
```

### Complexity

- **Time:** `O(n * d)` — Same time complexity, visiting each digit once per number.
- **Space:** `O(d)` — Call stack space for recursion up to the number of digits.

---

## Alternative Ways to Count Digits

Beyond recursion, two other common patterns exist for digit counting:

1. **Iterative While-Loop (O(1) auxiliary space):**
   ```cpp
   int count = 0;
   while(num > 0) {
       count++;
       num /= 10;
   }
   ```
2. **Logarithmic Formula (O(1) time per number):**
   ```cpp
   int digits = floor(log10(num)) + 1;
   ```

---

## What I Learned

- **Simplifying Base Cases:** Checking `num < 10` as a base case returning `1` avoids having to recurse all the way down to `0` and removes the need for an accumulator variable.
- **Recursion vs Iteration for Digits:** While recursion is intuitive, iterative division or `log10` avoids stack overhead entirely.

---

## Revision Notes

**Pattern:** Digit counting / Modulo arithmetic  
**Even Condition:** `(digitCount % 2) == 0`  
**Brute Force Time:** `O(n * d)`  
**Optimal Time:** `O(n * d)` (or `O(n)` with `log10`)  
**Space:** `O(d)` recursive stack (`O(1)` if iterative)

---