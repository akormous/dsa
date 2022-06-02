#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        
        vector<vector<int>> dp(l1+1 , vector<int>(l2+1, 0));
        
        for(int i = l1-1; i >= 0; --i) {
            for(int j = l2-1; j >= 0; --j) {
                
                // if the characters match
                if(text1[i] == text2[j]) {
                    // take the diagonal down and add 1
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                // if the characters dont match
                else {
                    // take the max of right and bottom
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};