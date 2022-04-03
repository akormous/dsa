#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return;
        
        // Step 1: find the number from the end, which is smaller than its next neighbor
        int k;
        
        for(k = n-2; k >= 0; k--) {
            if(nums[k] < nums[k+1])
                break;
        }
        
        // if k == -1, meaning that the array is in descending order, then reverse it and return it
        if(k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 2: find the number from the end, which is just greater than k
        // since we can deduce that the array from (k + 1 .. n) is sorted in descending order
        // so a number just greater than nums[k] will be the first number which is greater than nums[k]
        int l;
        for(l = n-1; l > k; l--) {
            if(nums[l] > nums[k])
                break;
        }
        
        // swap nums[k] and nums[l]
        swap(nums[k], nums[l]);
        
        // sort the array from (k+1 .. n)
        sort(nums.begin() + k + 1, nums.end());
    }
};
