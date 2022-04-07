#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // a max-heap
        priority_queue<int> q(begin(stones), end(stones));
        
        // loop until there are 2 or more elements in the heap
        while(q.size() > 1) {
            // pop the top 2 stones
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            
            if(x > y)
                q.push(x-y);
        }
        
        // if there is 1 stone left, return it
        if(q.size() == 1)
            return q.top();
        
        // else return 0;
        return 0;
    }
};