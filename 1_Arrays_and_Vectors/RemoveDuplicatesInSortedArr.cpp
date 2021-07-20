#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ct = 0;
        int n = nums.size();
        for(int i=1; i < n; i++)
        {
            if(nums[i] == nums[i-1])
                ct++;
            else
                nums[i - ct] = nums[i];
        }
        return (n - ct);
    }
};