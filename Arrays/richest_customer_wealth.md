# Richest Customer Wealth

**LeetCode:** https://leetcode.com/problems/richest-customer-wealth/description/

**Topic:** Arrays / 2D Matrix  
**Difficulty:** Easy

---

## Problem Summary

You are given an `m x n` integer grid `accounts` where `accounts[i][j]` is the amount of money the `i`-th customer has in the `j`-th bank.

Return the wealth that the richest customer has.

A customer's wealth is the total sum of money they have across all their bank accounts (the sum of the `i`-th row). The richest customer is the one with the maximum wealth.

---

## Approach — Row Sum with Running Maximum

Each customer corresponds to a row in the 2D grid, and each bank account is a column in that row. 

To find the richest customer:
1. Calculate the total wealth for each customer by summing all values in their row.
2. Keep a running track of the highest wealth seen so far.

### Steps:

1. Initialize `maxwealth = 0`.
2. Iterate through each customer `i` from `0` to `accounts.size() - 1`.
3. Initialize an accumulator `wealth = 0` for customer `i`.
4. Iterate through each bank `j` from `0` to `accounts[i].size() - 1`, adding `accounts[i][j]` to `wealth`.
5. If `wealth > maxwealth`, update `maxwealth = wealth` (or use `maxwealth = max(maxwealth, wealth)`).
6. After checking all customers, return `maxwealth`.

### Code

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxwealth = 0;

        for(int i = 0; i < accounts.size(); i++) {
            int wealth = 0;
            for(int j = 0; j < accounts[i].size(); j++) {
                wealth = accounts[i][j] + wealth;
            }
            if(wealth > maxwealth) {
                maxwealth = wealth;
            }
        }

        return maxwealth;
    }
};
```

### Complexity

- **Time:** `O(m * n)` — Where `m` is the number of customers (rows) and `n` is the number of banks (columns). We visit every cell in the grid exactly once.
- **Space:** `O(1)` — No extra data structures are created; only integer variables are maintained.

---

## Alternative Modern C++ Style

Using range-based for loops and `std::max`:

```cpp
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;

        for (const auto& customer : accounts) {
            int currentWealth = 0;
            for (int bank : customer) {
                currentWealth += bank;
            }
            maxWealth = max(maxWealth, currentWealth);
        }

        return maxWealth;
    }
};
```

---

## What I Learned

- **2D Vector Traversal:** Nested loops naturally mirror rows and columns: outer loop selects the row (customer), inner loop processes elements of that row (bank balances).
- **Independent Accumulation:** Resetting `wealth = 0` at the start of each row iteration is crucial so sums don't bleed into the next customer.

---

## Revision Notes

**Pattern:** 2D Matrix / Row-wise sum with running maximum  
**Key Logic:** `maxWealth = max(maxWealth, sum(row))`  
**Time Complexity:** `O(m * n)`  
**Space Complexity:** `O(1)`

---