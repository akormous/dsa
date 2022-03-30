#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void floodFill(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        if(grid[i][j] == 1)
            return;
        
        grid[i][j] = 1;
        
        floodFill(grid, i-1, j);
        floodFill(grid, i+1, j);
        floodFill(grid, i, j-1);
        floodFill(grid, i, j+1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        // flood fill all the islands connected to the edge of the grid
        int m = grid.size();
        int n = grid[0].size();
        
        // delete islands along the vertical axis
        for(int i = 0; i < m; ++i) {
            if(grid[i][0] == 0)
                floodFill(grid, i, 0);
            if(grid[i][n-1] == 0)
                floodFill(grid, i, n-1);
        }
        
        // delete islands along the horizontal axis
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 0)
                floodFill(grid, 0, j);
            if(grid[m-1][j] == 0)
                floodFill(grid, m-1, j);
        }
        
        int count = 0;
        
        // count rest of the remaining islands
        for(int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++) {
                if(grid[i][j] == 0) {
                    count++;
                    floodFill(grid, i, j);
                }
            }
        }
        return count;
    }
};