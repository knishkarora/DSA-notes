# Kids With the Greatest Number of Candies

**LeetCode:** https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/submissions/2132101161/

**Topic:** Arrays  
**Difficulty:** Easy

---

## Problem Summary

Given an array `candies` and an integer `extraCandies`, determine for each child whether giving all the extra candies to that child would make them have at least as many candies as the child who currently has the most candies.

Return a `vector<bool>` where each position represents whether that child can have the greatest number of candies.

---

## My First Approach — Brute Force

My first thought was to check each child against **every other child**.

For each child:

1. Add `extraCandies` to their current candies.
2. Compare that total with every element in the array.
3. If I find someone with more candies, mark the result as `false` and stop checking that child.
4. Otherwise, mark it as `true`.

### Brute Force Code

```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());

        for(int i = 0; i < candies.size(); i++) {
            int totalcandies = extraCandies + candies[i];

            for(int j = 0; j < candies.size(); j++) {
                if(totalcandies < candies[j]) {
                    result[i] = false;
                    break;
                }
                else {
                    result[i] = true;
                }
            }
        }

        return result;
    }
};
```

### Complexity

- **Time:** `O(n²)` in the worst case
- **Space:** `O(n)`

The nested loops are the reason for the `O(n²)` time complexity.

---

## Thinking Toward the Optimal Approach

Instead of comparing every child with every other child, I asked:

> **Do I really need to compare against everyone?**

The condition is:

```text
candies[i] + extraCandies >= every candies[j]
```

If I need to be greater than or equal to **everyone**, then I only need to beat the child with the **maximum number of candies**.

So I realized I could first find:

```text
maxCandies
```

Then, for every child, I only need to check:

```text
candies[i] + extraCandies >= maxCandies
```

This removes the need for the inner loop.

### Important Insight

> If something needs to be greater than or equal to every element, comparing it with the **maximum element** is enough.

---

## Optimal Approach

### Step 1 — Find the maximum

Go through the array once and find the child with the most candies.

### Step 2 — Check each child

Go through the array again.

For each child:

- If `candies[i] + extraCandies >= maxCandies`, store `true`.
- Otherwise, store `false`.

### Final Solution

```cpp
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());

        int maxcandies = 0;

        // Find the maximum number of candies
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] > maxcandies) {
                maxcandies = candies[i];
            }
        }

        // Check whether each child can reach the maximum
        for(int j = 0; j < candies.size(); j++) {
            if(extraCandies + candies[j] < maxcandies) {
                result[j] = false;
            }
            else {
                result[j] = true;
            }
        }

        return result;
    }
};
```

---

## Complexity

There are two separate loops, but they are **not nested**.

- First loop: `O(n)`
- Second loop: `O(n)`

Therefore:

```text
O(n) + O(n) = O(2n) = O(n)
```

### Final Complexity

- **Time:** `O(n)`
- **Space:** `O(n)` for the result vector

---

## What I Learned

The main thing I learned from this problem was not just how to find the maximum.

My important takeaway was:

> **When a condition asks whether something is at least as large as every element, look for a way to summarize the whole array with an extreme value such as the maximum or minimum.**

I also learned that moving from brute force to an optimal solution often starts by questioning the repeated work:

> **"Am I really required to check every element?"**

That question helped me recognize that the inner loop was unnecessary.

---

## Revision Notes

**Pattern:** Find an extreme value → use it to simplify comparisons.

**Key trick:**  
`value >= every element` → `value >= maximum`

**Brute Force:** `O(n²)`  
**Optimized:** `O(n)`

---


