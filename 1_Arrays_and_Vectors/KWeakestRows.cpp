#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int getStrength(vector<int> row) {
        
        auto s = lower_bound(row.begin(), row.end(), 0, greater<int>());
        
        return (s - row.begin());
        
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        set<pair<int,int>> mySet;
        
        for(int i = 0; i < mat.size(); ++i) {
            int count = getStrength(mat[i]);
            
            mySet.emplace(count, i);
            
            if(mySet.size() > k)
                mySet.erase(--mySet.end());
        }
        
        vector<int> result;
        
        for(auto p : mySet) {
            result.push_back(p.second);
        }
        
        
        
        return result;
    }
};