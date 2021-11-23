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

        int maxLen = 0; // length of largest subarray with equal 0s and 1s
        int endIndex = -1; // index at which the desired subarray ends

        // a map which has cumulative sum as key and index as value
        unordered_map<int,int> mp;

        // set all 0s to -1
        for(int i = 0; i < n; i++) 
            nums[i] = (nums[i] == 0 ? -1 : 1);

        // calculate prefix sum
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];

            // if prefix sum is 0 at some point
            if(sum == 0) {
                maxLen = i + 1;
                endIndex = i;
            }

            // if this cumulative sum is encountered before
            if(mp.find(sum) != mp.end()) {
                // check if length of this subarray is greater than maxLen so far
                if( i - mp[sum] > maxLen ) {
                    maxLen= i - mp[sum];
                    endIndex = i;
                }
            }
            else 
                mp[ sum ] = i;
        }

        return maxLen;
    }
};