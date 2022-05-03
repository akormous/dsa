#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(n, -1); // resulting final price array
        stack<int> incrSt;  // increasing monotonic stack
        
        for(int i = 0; i < prices.size(); ++i) {
            while(!incrSt.empty() && prices[i] <= prices[ incrSt.top() ]) {
                result[ incrSt.top() ] = prices[incrSt.top()] - prices[i];
                incrSt.pop();
            }
            incrSt.push(i);
        }
        
        while(!incrSt.empty()) {
            result[ incrSt.top() ] = prices[ incrSt.top() ];
            incrSt.pop();
        }
        return result;
    }
};