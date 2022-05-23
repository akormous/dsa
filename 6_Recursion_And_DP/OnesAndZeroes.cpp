#include<bits/stdc++.h>
using namespace std;
/*
LC 474
Dynamic Programming Knapsack question
TC: O(strs.size() * m * n)
*/
/*
Bottom-up (Tabuation)
*/
class Solution1 {
public:   
    int findMaxForm(vector<string>& strs, int m, int n) {
        // calculate the freq of 0 and 1 in each string and store it
        vector<pair<int,int>> freq(strs.size());
        for(int i = 0; i < strs.size(); i++) {
            int zeroCount = 0, oneCount = 0;
            for(char c : strs[i])
                c == '0' ? zeroCount++ : oneCount++;
            freq[i] = {zeroCount, oneCount};
        }
        
        // bottom-up dp
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // go through each string
        for(auto strCount : freq) {
            int nZero = strCount.first;
            int nOne = strCount.second;
            
            for(int i = m; i >= nZero; --i) {
                for(int j = n; j >= nOne; --j) {
                    // get maximum subset size, among the two options
                    // consider the current string OR DON'T consider the current string in the subset
                    dp[i][j] = max(dp[i][j], 1 + dp[i-nZero][j-nOne]);
                    
                }
            }
        }
        return dp[m][n];
    }
};
/*
Memoized solution
*/
class Solution2 {
public:
    int knapsack(vector<pair<int,int>>& freq, int zeroes, int ones, int curIndex, vector<vector<vector<int>>>& dp) {
        // if curIndex is out of bound or number of remaining zeroes and ones are not available
        if(curIndex == freq.size() || (zeroes == 0 && ones == 0))
            return 0;
        
        if(dp[zeroes][ones][curIndex] > -1)
            return dp[zeroes][ones][curIndex];
        
        // if the remaining zeroes and ones cannot support the number of 0s and 1s in curIndex string, 
        // then skip it (there is no other option)
        if(freq[curIndex].first > zeroes || freq[curIndex].second > ones)
            return dp[zeroes][ones][curIndex] = knapsack(freq, zeroes, ones, curIndex + 1, dp);
        
        // consider the curIndex string in the subset
        int consider = 1 + knapsack(freq, zeroes - freq[curIndex].first, ones - freq[curIndex].second, curIndex + 1, dp);
        
        // skip the curIndex string
        int skip = knapsack(freq, zeroes, ones, curIndex + 1, dp);
        
        dp[zeroes][ones][curIndex] = max(consider, skip);
        return dp[zeroes][ones][curIndex];
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        // calculate the freq of 0 and 1 in each string and store it
        vector<pair<int,int>> freq(strs.size());
        for(int i = 0; i < strs.size(); i++) {
            int zeroCount = 0, oneCount = 0;
            for(char c : strs[i])
                c == '0' ? zeroCount++ : oneCount++;
            freq[i] = {zeroCount, oneCount};
        }
        
        // adding memoization to the recursive solution
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size(), -1)));
        
        return knapsack(freq, m, n, 0, dp);
    }
};