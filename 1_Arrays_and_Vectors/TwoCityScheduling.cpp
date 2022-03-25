#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compareTotal(const vector<int>& a, const vector<int>& b) {
        return abs(a[0] - a[1]) > abs(b[0] - b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compareTotal);
            
        int aCount = 0, bCount = 0;
        int n = costs.size()/2;
        int result = 0;
        int i = 0;
        
        while(aCount < n && bCount < n && i < costs.size()) {
            
            int aCost = costs[i][0];
            int bCost = costs[i][1];
            
            if(aCost < bCost) {
                result += aCost;
                aCount++;
            }
            else {
                result += bCost;
                bCount++;
            }
            i++;
        }
        
        while(aCount < n) {
            result += costs[i][0];
            aCount++;
        }
        
        while(bCount < n) {
            result += costs[i][1];
            bCount++;
        }
        return result;
    }
    
};