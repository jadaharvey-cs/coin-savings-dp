# Cent Savings Optimization (Dynamic Programming, C++)

## Description
This project solves an optimization problem where a sequence of item prices must be divided into groups to minimize total cost after rounding.

Each group of items is summed and then rounded to the nearest multiple of 10 cents. The goal is to determine the optimal placement of dividers to achieve the lowest total cost.

---

## Problem
Given:
- `n` items with prices in cents
- up to `d` dividers (which create `d + 1` groups)

You must:
- split the items into groups (without changing order)
- round each group's total to the nearest multiple of 10
- minimize the total cost after rounding

### Example
- 94 → 90  
- 95 → 100  

---

## Approach
- Used **dynamic programming** to compute the minimum cost
- Defined a DP table where each state represents the minimum cost for the first `i` items using `k` groups
- Used **prefix sums** to efficiently calculate group totals
- Considered all valid partition points to find the optimal solution

---

## Features
- Efficient solution compared to brute force approaches
- Handles up to 2000 items and 20 dividers
- Demonstrates real-world use of dynamic programming and optimization

---

## Technologies
- C++
- Problem from Kattias
---

## Contributions
Worked in a team of 4 to design and implement the solution.  
Contributed to implementing the dynamic programming logic and testing.
