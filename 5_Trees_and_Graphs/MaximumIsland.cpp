#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getArea(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return 0;
        
        if(grid[i][j] == 0)
            return 0;
        
        grid[i][j] = 0;
        
        return 1 + getArea(grid, i+1, j) + getArea(grid, i-1, j) + getArea(grid, i, j+1) + getArea(grid, i, j-1) ;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, getArea(grid, i, j));
            }
        }
        return maxArea;
    }
};