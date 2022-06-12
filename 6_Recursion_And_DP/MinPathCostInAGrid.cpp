#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& cost, vector<vector<int>>& memo) {
        // if we are at the last row, then just return teh grid value
        if(i == grid.size() - 1)
            return grid[i][j];
        
        // if the answer at this i,j is already calculated and cached, then return it
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int ans = INT_MAX;  // for the current starting column (row = 0); minimize this cost
        // try to go to each col in the next row, and add the expense in the process
        for(int col = 0; col < grid[0].size(); col++) {
            ans = min(ans,
                      grid[i][j] + cost[grid[i][j]][col] + dfs(i+1, col, grid, cost, memo)
                     );
        }
        
        // cache the ans
        memo[i][j] = ans;
        return memo[i][j];
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        // DFS + memoization
        int m = grid.size();    // number of rows
        int n = grid[0].size(); // number of cols
        
        vector<vector<int>> memo(m, vector<int>(n, -1));  // memo cache
        int ans = INT_MAX;  // result; minimize this
        
        // go to each col and start a dfs from there
        for(int col = 0; col < n; col++) {
            ans = min(ans, dfs(0, col, grid, moveCost, memo));
        }
        return ans;
    }
};