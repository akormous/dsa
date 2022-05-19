#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(dp[i][j] != 0)   return dp[i][j];    // if max length is already calculated and cached for cell (i,j)

        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};  // direction vector
        int maxLength = 1;  // keep track of the max length increasing path starting from cell i,j
        // goto each direction
        for(auto dir : directions) {
            int rr = i + dir.first;
            int cc = j + dir.second;
            
            // if out of bounds or the neighbor is less than current
            if(rr < 0 || cc < 0 || rr >= m || cc >= n || matrix[rr][cc] <= matrix[i][j])    continue;
            
            // increasing path length by 1, because we found a bigger number in its neighbors
            int len = 1 + dfs(matrix, rr, cc, m, n, dp);
            maxLength = max(maxLength, len);    // get the max length possible
        }
        
        // cache the max length in dp
        dp[i][j] = maxLength;
        return maxLength;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // stores the max length increasing path starting from each cell (i,j)
        // cache - memoization
        vector<vector<int>> dp(m, vector<int>(n, 0));   
        // max length is at least 1
        int maxLength = 1;
        // go to each cell
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int len = dfs(matrix, i, j, m, n, dp);    // call dfs on each cell
                maxLength = max(maxLength, len);
            }
        }
        return maxLength;
    }
};