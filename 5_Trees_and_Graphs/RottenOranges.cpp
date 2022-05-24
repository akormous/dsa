#include<bits/stdc++.h>
using namespace std;

class Orange {
public:
    int x, y;
    Orange(int ix, int iy) : x(ix), y(iy) {}
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();    // number of rows
        int n = grid[0].size();  // number of cols
        queue<Orange> q = getRottenOranges(grid, m, n);
        int totalOrangesCount = getOrangeCount(grid, m ,n);
        int rottenOrangesCount = q.size();
        if(rottenOrangesCount == totalOrangesCount) return 0;   // all of them are rotten initially
        
        int minutes = 0;    // return value
        
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        while(!q.empty()) {
            // process all rotten oranges at current level
            int rotCount = q.size();
            
            for(int i = 0; i < rotCount; ++i) {
                Orange tmp = q.front(); q.pop();
                int x = tmp.x;
                int y = tmp.y;
                
                // go to neighboring cells
                for(int j = 0; j < 4; ++j) {
                    int xx = x + dx[j];
                    int yy = y + dy[j];
                    
                    if(!isValidCoords(xx, yy, m, n))    continue;
                    if(grid[xx][yy] == 1)    {// fresh neighboring orange
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                        rottenOrangesCount++;
                        
                    }
                }
            }
            minutes++;
            if(rottenOrangesCount == totalOrangesCount)
                return minutes;
        }
        return -1;
    }
private:
    bool isValidCoords(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    queue<Orange> getRottenOranges(vector<vector<int>>& grid, int m, int n) {
        queue<Orange> result;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 2)
                    result.push({i, j});
            }
        }
        return result;
    }
    
    int getOrangeCount(vector<vector<int>>& grid, int m, int n) {
        int result = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1 || grid[i][j] == 2)
                    result++;
            }
        }
        return result;
    }
};