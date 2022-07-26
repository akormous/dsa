#include<bits/stdc++.h>
using namespace std;

/*

FLOYD_WARSHALL
Leetcode 1334

*/

#define INFIN 100000
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // DP memo setup
        vector<vector<int>> dp(n, vector<int>(n, INFIN));
        for(int i = 0; i < n; i++)  dp[i][i] = 0;
        for(auto& e : edges) {
            int src = e[0], dest = e[1], wt = e[2];
            dp[src][dest] = wt;
            dp[dest][src] = wt;
        }
        
        // FLOYD-WARSHALL
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        int res = -1;       // result city
        int minCount = INFIN; // count of reachable cities from result city
        // count number cities within threshold from a city i,
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(dp[i][j] <= distanceThreshold)
                    count++;
            }
            if(count <= minCount) {
                minCount = count;
                res = i;
            }
        }
        return res;
    }
};