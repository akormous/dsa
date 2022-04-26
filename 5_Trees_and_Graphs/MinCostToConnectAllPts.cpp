#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct compareEdgeWt {
        constexpr bool operator()(pair<int,int> const& a, pair<int,int> const& b) const noexcept {
            return a.first > b.first;
        }
    };

    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); // number of points
        vector<bool> visited(n, false); // keep track of visited coordinate
        int i = 0;  // initial coordinate, 0th index in points array
        int connected = 0;  // connected edges
        // to connect 'n' coordinates, 'n-1' edges are required
        
        int result = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, compareEdgeWt> pq; // min-heap that stores [edgeWt, pointIndex]
        
        while(connected < n-1) {
            visited[i] = true;  // visit the current coordinate
            for(int j = 0; j < n; j++) {
                if(!visited[j]) { // go to every non-visited coordinate
                    int manDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);  // calculate manhattan distance between i and j
                    pq.push({manDist, j});  // push to heap with point index
                }
            }
            // remove all the visited coordinates from the top of the heap
            while( visited[pq.top().second] )
                pq.pop();
            
            // add the edgeWt to final result
            result += pq.top().first;   // this will be the minimum edge wt from i to some non-visited coordinate
            i = pq.top().second; // move to the neighbor of i, which is pq.top().second
            pq.pop(); // pop from heap
            connected++;    // increment connected edges
        }
        return result;
    }
};