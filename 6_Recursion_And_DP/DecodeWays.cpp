#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        
        for(int i = n-1; i >= 0; i--) {
            // if a single digit number can be made starting at index i
            if(s[i] != '0')
                dp[i] += dp[i+1];
            // if a two digit number can be made starting at index i
            if( i+1 < n and (s[i] == '1' or (s[i] == '2' and s[i+1] <= '6') ) )
                dp[i] += dp[i+2];
        }
        return dp[0];
    }
};