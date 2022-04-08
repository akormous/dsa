#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // BFS approach
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // insert all 0 coords in the queue
                if(mat[i][j] == 0)
                    q.push({i,j});
                // and set all 1 coords to infinity (because we have to minimize this)
                else
                    mat[i][j] = INT_MAX;
            }
        }
        
        // direction vectors (4 way)
        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, 1, 0, -1};
        
        // start bfs
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            
            q.pop();
            
            // go in each direction
            for(int i = 0; i < 4; ++i) {
                int xx = x + dirX[i];
                int yy = y + dirY[i];
                
                if(xx < 0 || xx >= m || yy < 0 || yy >= n)  continue;
                
                // if distance of the neighbor can be minimized
                if(mat[xx][yy] > mat[x][y] + 1) {
                    // then minimize it
                    mat[xx][yy] = mat[x][y] + 1;
                    // push this coords to the queue
                    // since they are changed
                    q.push({xx, yy});
                }
            }
            
        }
        /*
        Time Complexity: O(M*N)
        */
        return mat;
    }
};