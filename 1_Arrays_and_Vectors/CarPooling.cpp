#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> kmap;  // keeps the kms points in sorted way
        
        for(auto& trip : trips) {
            kmap[trip[1]] += trip[0];   // at pickup point, add the passengers
            kmap[trip[2]] -= trip[0];   // at drop off, subtract the passengers
        }
        
        for(auto& p : kmap) {
            capacity -= p.second;
            if(capacity < 0)    return false;   // no capacity
        }
        return true;
    }
};