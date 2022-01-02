// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 class Solution {
public:
    bool isInbound(int r, int c, int m, int n) {
        if(r >= 0 && r < m &&
          c >= 0 && c < n)
            return true;
        return false;
    }
    // neighbor nodes = up, down, left, right
    void exploreIsland(vector<vector<char>>& grid, int r, int c, int m, int n) {
        if(!isInbound(r, c, m, n)) return;
        
        if(grid[r][c] == '0') return;
        
        grid[r][c] = '0';
        
        exploreIsland(grid, r-1, c, m, n);
        exploreIsland(grid, r+1, c, m, n);
        exploreIsland(grid, r, c-1, m, n);
        exploreIsland(grid, r, c+1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // cols
            
        int count = 0;
        
        // reach every node
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    exploreIsland(grid, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};