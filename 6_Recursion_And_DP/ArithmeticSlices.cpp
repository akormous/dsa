#include<bits/stdc++.h>
using namespace std;

/*

An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

    For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.

Given an integer array nums, return the number of arithmetic subarrays of nums.

*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        
        vector<int> dp(n, 0);
        
        if(nums[2] - nums[1] == nums[1] - nums[0])
            dp[2] = 1;
        
        int total = dp[2];
        
        for(int i = 3; i < n; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
                dp[i] = dp[i-1] + 1;
            total += dp[i];
        }
        return total;
    }
};