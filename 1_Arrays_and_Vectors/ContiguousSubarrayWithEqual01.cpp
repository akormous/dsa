#include<bits/stdc++.h>
using namespace std;

/*

Question: Find the largest subarray having equal number of 0s and 1s

Approach:
prefix sum approach
consider 0 as -1

now there can be 2 cases in which we have equal number of 0s and 1s
1. When we encounter a cumulative sum of 0 at some point,
   it means that from index 0 till that point, there are equal number of 0s and 1s
2. When we encounter a cumulative sum which has already been encountered,
   how do we check this ? you got it, using a hash map,
   hash map with key as cumulative sum and index as value

*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0)
                nums[i] = -1;
        }
        int maxLen = 0;
        
        // a map which has prefix sum as key and index as val
        unordered_map<int,int> map;
        
        // prefix sum
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            
            // if prefix sum is 0 at some point
            if(sum == 0) {
                maxLen = max(maxLen, i + 1);
            }
            
            // if this prefix sum is encountered before
            if(map.find(sum) != map.end()) {
                maxLen = max(maxLen, i - map[sum]);
            }
            else {
                map[sum] = i;
            } 
                
        }
        return maxLen;
    }
};