#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    this solution makes use of the monotonic stack, kinda
    here we are not storing the actual increasing or decreasing sequence
    rather we just need the largest and smallest index out of place
    */
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        
        int end = 0;
        int prev = nums[0];
        // find the largest index which is out of place in the sorted array;
        // logic is similar to monotonic stack
        for(int i = 1; i < n; ++i) {
            if(nums[i] < prev)
                end = i;
            else
                prev = nums[i];
        }
        
        int start = n-1;
        prev = nums[n-1];
        // find the smallest index which is out of place in the sorted array;
        for(int i = n-2; i >= 0; --i) {
            if(nums[i] > prev)
                start = i;
            else
                prev = nums[i];
        }
        
        return end == 0 ? 0 : end - start + 1;
    }
};