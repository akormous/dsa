#include<bits/stdc++.h>
using namespace std;

/*
Given a bunch of islands, return the area of minimum island (count if pixels)

Neighbor node = up, down, left, right
*/

bool isInbound(int r, int c, int m, int n) {
    if(r >= 0 && r < m &&
        c >= 0 && c < n)
        return true;
    return false;
}

int exploreIsland(vector<vector<char>>& grid, int r, int c, int m, int n) {
    if(!isInbound(r, c, m, n))
        return 0;

    if(grid[r][c] == 'W')
        return 0;

    int size = 1;

    grid[r][c] = 'W';

    size += exploreIsland(grid, r-1, c, m, n);
    size += exploreIsland(grid, r+1, c, m, n);
    size += exploreIsland(grid, r, c-1, m, n);
    size += exploreIsland(grid, r, c+1, m, n);

    return size;

}

int minimumIsland(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    
    if(m == 0)
        return -1;
    
    int minArea = INT_MAX;
    int curArea = 0;

    // reach every part of the area
    for(int r = 0; r < m; ++r) {
        for(int c = 0; c < n; ++c) {
            if(grid[r][c] == 'L') {
                curArea = exploreIsland(grid, r, c, m, n);
                minArea = min(minArea, curArea);
            }
        }
    }
    return minArea;
}

int main() {
    // solution
    // L = land, W = water
    vector<vector<char>> grid = {
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W', 'L', 'L', 'W', 'W'},
        {'L', 'L', 'W', 'W', 'W', 'L', 'W', 'W', 'W'},
        {'L', 'L', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'L', 'W'},
        {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'W', 'W', 'W', 'W', 'L'},
        {'W', 'L', 'L', 'L', 'W', 'W', 'W', 'W', 'L'},
    };

    cout << minimumIsland(grid) << endl;
    return 0;
}