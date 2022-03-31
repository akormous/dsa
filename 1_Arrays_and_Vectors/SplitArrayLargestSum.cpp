#include<bits/stdc++.h>
using namespace std;

/*

IMPORTANT QUESTION

Look at this explanation to understand:
https://leetcode.com/problems/split-array-largest-sum/discuss/89819/C%2B%2B-Fast-Very-clear-explanation-Clean-Code-Solution-with-Greedy-Algorithm-and-Binary-Search

*/

class Solution {
public:
    
    bool doable(vector<int>& nums, int cuts, int max) {
        
        int acc = 0;
        for(int num : nums) {
            
            if(num > max)
                return false;
            
            else if(acc + num <= max)
                acc += num;
            
            else {
                cuts--;
                acc = num;
                
                if(cuts < 0)
                    return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long maximum = INT_MIN, sum = 0;
        
        for(int num : nums) {
            maximum = num > maximum ? num : maximum;
            sum += num;
        }
        
        int left = maximum;
        int right = sum;
        
        while(left < right) {
            
            int mid = (left + right)/2;
            
            if( doable(nums, m - 1, mid) )
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};