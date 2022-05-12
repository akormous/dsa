#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& result, vector<int>& nums, int pos) {
        if(pos == nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); ++i) {
            if(i > pos && nums[i] == nums[pos]) continue;
            swap(nums[i], nums[pos]);
            helper(result, nums, pos + 1);
        }
        
        // restore nums
        for(int i = nums.size() - 1; i > pos; i--) {
            swap(nums[i], nums[pos]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        helper(result, nums, 0);
        return result;
    }
};