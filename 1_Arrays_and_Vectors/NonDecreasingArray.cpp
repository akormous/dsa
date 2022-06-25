#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return true;
        int prev = INT_MIN; // prev number to nums[a]
        int a = 0, b = 1;   // indices of first 2 numbers
        bool changeApplied = false; // keeps track of that one change that we are allowed
        while(b < n) {
            // if a decreasing pair is encountered
            if(nums[b] < nums[a]) {
                if(changeApplied)   // and if we have consumed the change, then return false
                    return false;

                if(nums[b] < prev)  // check which to one to change at a or at b ?
                    nums[b] = nums[a];
                else
                    nums[a] = nums[b];
                changeApplied = true;
            }
            prev = nums[a];
            a++; b++;
        }
        return true;
    }
};