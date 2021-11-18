/*

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.
*/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    static bool comparator(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort each cuboid lenght width and height
        for(int i = 0; i < cuboids.size(); ++i) {
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        
        // topmost cuboid
        cuboids.push_back({0, 0, 0});
        
        // sort cuboids based on the first element in each vector
        sort(cuboids.begin(), cuboids.end());
        
        // number of cuboids that we have
        int n = cuboids.size();
        int res = 0;
        
        // a table where we will keep track of the maximum height that can be acheived
        int dp[n];
        memset(dp, 0, sizeof(dp));
        
        
        for(int j = 1; j < n; j++) {
            // try every cuboid smaller than the cur cuboid
            for(int i = 0; i < j; i++) {
                // check if it is smaller
                if(cuboids[i][0] <= cuboids[j][0] &&
                   cuboids[i][1] <= cuboids[j][1] &&
                   cuboids[i][2] <= cuboids[j][2]
                  )
                {
                    // update height 
                    dp[j] = max(dp[j], dp[i] + cuboids[j][2]);
                    res = max(res, dp[j]);
                }
                
            }
        }
        return res;
    }
};