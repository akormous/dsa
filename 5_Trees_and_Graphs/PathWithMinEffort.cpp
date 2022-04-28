#include<bits/stdc++.h>
using namespace std;

struct compareDist {
    constexpr bool operator()(vector<int> const& a, vector<int> const& b) const noexcept {
        return a[0] > b[0];
    }
};

class Solution {
public:
    /*
    Using Dijkstra's Algorithm to find the shortest path from 0,0 to m-1,n-1
    but the edge weight will be slightly different from the usual Dijkstra's
    */
    vector<vector<int>> DIR = {{0,1}, {1,0}, {0,-1}, {-1,0}};   // Direction vectors
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(); // rows
        int n = heights[0].size();  // cols
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));   // dist array
        
        priority_queue<vector<int>, vector<vector<int>>, compareDist> pq; // stores node_index (x,y) and distance to it from src {w, x, y}
        
        dist[0][0] = 0; // distance to source
        pq.push({0, 0, 0});  // {w, x, y}
        
        while(!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            
            int w = cur[0];
            int x = cur[1], y = cur[2];
            
            if(w > dist[x][y])  continue;
            
            if(x == m-1 && y == n-1)  return w;     // return answer when reached bottom-right
            
            // go to neighbors of current node and update their distance
            for(auto d : DIR) {
                int xx = x + d[0], yy = y + d[1];
                if(xx < 0 || yy < 0 || xx >= m || yy >= n)    continue;
                int newDist = max(w, abs(heights[xx][yy] - heights[x][y]));
                if(dist[xx][yy] > newDist) {
                    dist[xx][yy] = newDist;
                    pq.push({newDist, xx, yy});
                }
            }
        }
        return 0;
    }
};