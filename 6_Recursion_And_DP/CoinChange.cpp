#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX = amount + 1;   // avoid using INT_MAX as it may cause int overflow when doing dp[i] + 1;
        vector<int> dp(amount+1, MAX);
        // we need 0 coins to make 0 amount
        dp[0] = 0;
        // try to minimize the number of coins for each amount from 1 .. amount
        for(int i = 1; i <= amount; ++i) {
            // take each coin
            for(int coin : coins) {
                if(coin > i)    continue;  // if coin is bigger than the amount, then skip it
                // use min number of coins of previous amounts 
                // to minimize the number of coins for current amount
                // number of coins required in (amount - curCoinDenomination), and add 1
                dp[i] = min(dp[i], dp[i - coin] + 1);   
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; 
    }
};