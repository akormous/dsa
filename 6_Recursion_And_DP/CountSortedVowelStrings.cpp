#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(6));
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= 5; ++j) {
                dp[i][j] = dp[i][j-1] + (i > 1 ? dp[i-1][j] : 1);
            }
        }
        
        return dp[n][5];
    }
};

// cooler solution
class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        
        while(n > 1) {
            a = a + e + i + o + u;
            e = e + i + o + u;
            i = i + o + u;
            o = o + u;
            u = u;
            n--;
        }
        return a + e + i + o + u;
    }
};