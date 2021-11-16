#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void permuteHelper(vector<int> nums, int index) {
        if(index >= nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); ++i) {
            swap(nums[i], nums[index]);
            
            permuteHelper(nums, index+1);
            
            swap(nums[i], nums[index]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permuteHelper(nums, 0);
        return result;
    }
};