#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return 0;
        unordered_map<int,int> mp;
        int result = 0;
        for(auto& num : nums) {
            if(mp[num] > 0) { // 2: when required number is found,
                result++;  // increment the result count
                mp[num]--; // decrease freq of the required number
            }
            else {
                mp[k - num]++;  // 1: increase the frequency of the required number (k - num)
            }
        }
        return result;
    }
};