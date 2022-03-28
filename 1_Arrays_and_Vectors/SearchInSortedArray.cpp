#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r) {
            
            while(l < r && nums[l] == nums[l + 1])
                ++l;
            
            while(r > l && nums[r] == nums[r-1])
                --r;
            
            int m = (l + r)/2;
            
            if(target == nums[m])
                return true;
            
            if(nums[l] <= nums[m]) {
                if(nums[l] <= target && target <= nums[m])
                    r = m-1;
                else
                    l = m+1;
            }
            
            else if(nums[m] <= nums[r]) {
                if(nums[m] <= target && target <= nums[r])
                    l = m+1;
                else
                    r = m-1;
            }
        }
        return false;
    }
};