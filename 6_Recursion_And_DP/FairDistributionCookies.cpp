#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCookies;
    Solution() {
        maxCookies = INT_MAX;
    }
    
    void assignCookies(vector<int>& cookies, int cur, vector<int>& val) {
        // if we have assigned all of the cookie bags
        if(cur == cookies.size()) {
            // look for the max cookies a child has
            int localMax = INT_MIN;
            for(auto& num : val)
                localMax = max(localMax, num);
            // minimize our result
            maxCookies = min(localMax, maxCookies);
            return;
        }
        
        // go to each child
        for(int i = 0; i < val.size(); i++) {
            // give the current cookie bag to this child
            val[i] += cookies[cur];
            // recurse for next bag
            assignCookies(cookies, cur+1, val);
            // take back the bag from the child
            val[i] -= cookies[cur];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        // create k sets (1 for each child)
        vector<int> val(k, 0);  // all children have initially 0 cookies
        
        // just generate all possible combinations 
        // and check for the max cookies a child has
        // minimise the max cookies
        assignCookies(cookies, 0, val);
        
        return maxCookies;
    }
};