#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int rob(vector<int>& nums) {
        int n = nums.size();    // number of houses
        
        int dp[n+1];
        
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i = 1; i < n; ++i) {
            // optimal value for the next house
            dp[i + 1] = max(
            // just take whatever max was collected until this house
                dp[i], 
            // or get the collection from the previous house and add it to this house
                dp[i-1] + nums[i]);
        }
        
        return dp[n];
    }
};