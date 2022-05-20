#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));   // dp[m+1][n+1] - this allows us to write only 1 for loop
        
        dp[0][1] = 1;   // just to make sure that dp[1][1] (which actually represents grid[0][0]) has a start
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(obstacleGrid[i-1][j-1] == 0) // if there is NO obstacle at current position
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]; // then number of path = diagonal up + diagonal left
            }
        }
        return dp[m][n];
    }
};