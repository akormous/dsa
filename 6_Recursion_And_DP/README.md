# Dynamic Programming
It is an optimization over plain recursion. If there is a recursive solution that has repeated calls for same inputs, it can be optimized using Dynamic Programming.

This simple optimization reduces the time complexities from exponential to polynomial.

The two main properties of a problem that suggests Dynamic Programming can be applied on it are:

### 1. Overlapping Subproblems

Like Divide and Conquer, Dynamic Programming combines solutions to sub-problems. It is mainly used when solutions to subproblems are needed again and again. Here, computed solutions to subproblems are stored in a table so that these don't have to be recomputed.

There are 2 ways of storing the results of subproblems
<details>
    <summary>Memoization (Top Down)</summary>

- A lookup array with all values as NIL is initialized
- Whenever we need a solution to a subproblem, we first look into the lookup table
- If precomputed value is there then it is returned, otherwise, the value is calculated and stored in the lookup table
- Table is filled on demand

</details>

<details>
    <summary>Tabulation (Bottom Up)</summary>

- It builds the table in a bottom-up fashion and returns the last entry from the table
- Table is filled from the first entry till last
</details>

### 2. Optimal Substructure

A problem has an Optimal Substructure property if optimal solution of the problems can be obtained by using optimal solutions of its subproblems.

For example, shortest path in a graph, 
If a node _x_ lies in the shortest path from a source node _a_ to destination node _b_ , then the shortest path from _a_ to _b_ is the combination of shortest path from _a_ to _x_ and shortest path from _x_ to _b_ 



