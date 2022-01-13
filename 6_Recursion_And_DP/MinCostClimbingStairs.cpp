#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
        The point is you can either take 1 step or 2 step,
        Now the minimum cost at any position will be the cost that
        you paid 1 step earlier or 2 step earlier,
        initially you paid cost[0] and cost[1] for 0th and 1st step
        so
        
        for the 2nd step you will pay
        dp[2] = cost[2] + min(dp[0], dp[1]);

        for 3rd step
        dp[3] = cost[3] + min(dp[1], dp[2]);

        and so on

        also at the end, you can just hop 2 steps, so min(dp[n-1],dp[n-2])
        */
       if(cost.size() == 2)
        return min(cost[0], cost[1]);

       int n = cost.size();
       
       int dp[n];
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};