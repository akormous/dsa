#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // number of rows
        int m = grid.size();
        // number of cols
        int n = grid[0].size();
        
        int dp[m][n];
        
        // going down down down
        bool flag = 0;
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1)
                flag = 1;
            
            dp[i][0] = flag == 1? 0 : 1;
        }
        // going right right right
        flag = 0;
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 1)
                flag = 1;
            dp[0][j] = flag == 1? 0 : 1;
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(grid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};