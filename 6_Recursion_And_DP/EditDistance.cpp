#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        cout << "hello " << endl;
        // when word 1 is empty string
        for(int j = 0; j <= l2; j++)
            dp[l1][j] = l2-j;
            
        // when word 2 is empty string
        for(int i = 0; i <= l1; i++)
            dp[i][l2] = l1-i;
            
        for(int i = l1-1; i >= 0; i--) {
            for(int j = l2-1; j >= 0; j--) {
                if(word1[i] == word2[j])
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = 1 + min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]});
            }
        }
        return dp[0][0];
    }
};