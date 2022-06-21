#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        int i;
        /*
        The idea is to jump the lesser height diffs using bricks
        and the bigger height diffs using ladders, this is a greedy approach
        and can be applied using a min heap
        Store the height diffs in a min heap, and pop the minimum height diff when pq size > ladders
        */
        for(i = 0; i < n-1; i++) {  // start traversing
            int d = heights[i+1] - heights[i];  // height difference
            if(d <= 0)  continue;   // skip negative diff
            pq.push(d); // push it to min heap
            if(pq.size() > ladders) {   // if all ladders are consumed
                bricks -= pq.top(); // then try to jump the minimum difference using bricks
                pq.pop();
            }
            if(bricks < 0)  // if bricks are exhausted, then return
                break;
        }
        return i;
    }
};