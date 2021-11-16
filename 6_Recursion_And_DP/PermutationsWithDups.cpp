#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
   
    
    void helper(vector<int> nums, int index) {
        if(index >= nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); ++i) {
            if( i != index && nums[i] == nums[index] )
                continue;
            
            swap(nums[i], nums[index]);
            
            helper(nums, index+1);    
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return result;
    }
};