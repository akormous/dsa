#include<bits/stdc++.h>
using namespace std;
/*
Peak and Valley concept
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int peak = 1;
        int valley = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                peak = 1 + valley;
            }
            else if(nums[i] < nums[i-1]) {
                valley = 1 + peak;
            }
        }
        return max(peak, valley);
    }
};