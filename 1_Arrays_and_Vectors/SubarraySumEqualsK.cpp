#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int preSum = 0;
        int count = 0;
        // a hashmap to store pre sum and number of arrays having that sum
        unordered_map<int,int> mp;
        // a sum of 0 can be acheived by an empty subarray
        mp[0] = 1;
        

        for(auto num : nums) {
            // calculate prefix sum
            preSum += num;
            
            // here required sum = preSum - k
            // if its present in the map, then add the count to the final count
            count += mp[preSum - k];
            
            // store it in the map
            mp[preSum]++;
        }
        return count;
        
    }
};