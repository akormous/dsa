#include<bits/stdc++.h>
using namespace std;

/*

Given a grid, find the shortest path from top-left to bottom-right (coords (0,0) to (R-1, C-1))
In the grid, a 1 represents a blocked cell, so you cannot go to that cell
for example

0 0 0
1 1 0
1 1 0

Approach- BFS
BFS runs in a layered fashion in a grid, if you can imagine
So, when we visit all the nodes in the current layer, we have to move, so the path length increases
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // number of rows and cols
        int R = grid.size();
        int C = grid[0].size();

        // if src or dest is blocked
        if((grid[0][0] == 1) || (grid[R-1][C-1] == 1))
            return -1;

        // Queue for storing coords
        queue<pair<int,int>> q;

        // a boolean matrix representing visited nodes
        vector<vector<int>> visited(R, vector<int>(C, 0));

        // length of path
        int length = 0;
        // since we are starting from 0,0 number of nodes in current layer = 1
        int nodesInCurLayer = 1;
        int nodesInNextLayer = 0;
        
        // a flag that represents if end is reached
        bool endReached = false;

        // direction vectors all 8-direction
        vector<int> dr = {-1, -1, 0, 1, 1,  1,  0, -1};
        vector<int> dc = { 0,  1, 1, 1, 0, -1, -1, -1};

        // insert the source node to the queue
        q.push({0,0});

        // BFS starts here
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // if this is the end, break from BFS, do not go any further
            if(r == R-1 && c == C-1) {
                endReached = true;
                break;
            }

            // go in all 8 directions
            for(int i = 0; i < 8; ++i) {
                int rr = r + dr[i];
                int cc = c + dc[i];

                // if rr and cc are out of bounds
                if(rr < 0 || cc < 0 || rr >= R && cc >= C)  continue;
                // if it is already visited
                if(visited[rr][cc]) continue;
                // if it is blocked
                if(grid[rr][cc] == 1)   continue;

                // visit this node, push it to the queue
                visited[rr][cc] = true;
                q.push({rr,cc});
                // increase the number of nodes in next layer
                nodesInNextLayer++;
            }
            // decrease node in cur layer, because it is visited completely
            nodesInCurLayer--;
            // if no more nodes available in current layer
            if(nodesInCurLayer == 0) {
                // go to the next layer
                nodesInCurLayer = nodesInNextLayer;
                nodesInNextLayer = 0;
                // increase path length
                length++;
            }
        }
        if(endReached)
            return length;
        return -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};

    cout<<s.shortestPathBinaryMatrix(grid);
    return 0;
}