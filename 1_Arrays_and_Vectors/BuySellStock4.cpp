class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(k+1, vector<int>(n, 0)); // dp array of size (k+1) x (n), initialized to 0
        // dp[k][i] = maximum profits that can be achieved with k transactions and 0 .. i prices
        // if we have 0 transactions to perform, then profits = 0
        // if we are just at the 0th day, then profits = 0
        
        for(int t = 1; t <= k; t++) {   // for each number of transactions
            int minPrice = prices[0];
            
            for(int i = 1; i < n; i++) {
                dp[t][i] = max(dp[t][i-1], prices[i] - minPrice);
                minPrice = min(minPrice, prices[i] - dp[t-1][i-1]);
            }
            
        }
        return dp[k][n-1];
    }
};