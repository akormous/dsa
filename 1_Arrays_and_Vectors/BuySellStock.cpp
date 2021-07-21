#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int local_max = 0, global_max = 0;
        // Kadane's Algorithm
        for(int i=1; i < n; i++)
        {
            local_max = max(0, local_max += prices[i] - prices[i-1]);
            global_max = max(local_max, global_max);
        }
        return global_max;
    }
};