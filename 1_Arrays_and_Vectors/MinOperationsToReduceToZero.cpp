#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;  // total sum of the array
        for(int& num : nums)    total += num;
        
        int target = total - x; // 2-diff target
        if(target == 0) return nums.size();
        
        unordered_map<int,int> mp;
        mp[0] = -1; // when prefixSum - target == 0, then this will come in action
        
        int prefixSum = 0;
        int maxLen = INT_MIN;   // maximum length of a subarray having sum = target
        
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];   // calculate prefix sum
            int req = prefixSum - target;   // required sum
            
            if(mp.find(req) != mp.end()) {  // if req is already encountered before
                maxLen = max(maxLen, i - mp[req]);  // then update maxLen subarray
            }
            
            mp[prefixSum] = i;  // store the prefix sum in the map
        }
        return maxLen == INT_MIN ? -1 : nums.size() - maxLen;
    }
};