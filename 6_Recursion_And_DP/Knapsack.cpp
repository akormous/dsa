#include<bits/stdc++.h>
using namespace std;

/*
Given a bunch of items, each having a weight and a value
You have a knapsack (bag), which can hold a certain amount of weight
You have to maximize the value in your bag, without going over the weight limit
Input:
wt[] = {3,5,2,7,8,5}
val[] = {5,4,2,6,7,2}

Output:
MaxValue
*/

/**
 * @brief returns the maximum value that can be put in the knapsack
 * 
 * @param n number of items
 * @param wts weight of items
 * @param vals value if items
 * @param limit knapsack weight limit
 * @return int 
 */
int knapsack(int n, vector<int>& wts, vector<int>& vals, int limit) {
    // a 2-D array with rows = number of items, cols = limit of knapsack
    // stores the max value that can be obtained for a given number of items (i) and limit (j)
    vector<vector<int>> dp(n + 1, vector<int>(limit+1, 0));
    
    // core solution
    for(int i = 0; i <= n; ++i) {
        for(int capacity = 0; capacity <= limit; ++capacity) {
            // if we have 0 items OR 0 capacity, then no value can be obtained
            if(i == 0 || capacity == 0) {
                dp[i][capacity] = 0;
            }
            else if(wts[i-1] <= capacity) { // if current capacity can hold the weight of current item
                dp[i][capacity] = max(dp[i-1][capacity], vals[i-1] + dp[i-1][capacity - wts[i-1]]);
            }
            else 
                dp[i][capacity] = dp[i-1][capacity];    // else we cannot include it with this capacity
        }
    }
    return dp[n][limit];
}

int main() {
    // solution
    vector<int> wt = {5,4,6,3};
    vector<int> val = {10,40,30,50};
    int limit = 10;

    cout << knapsack(wt.size(), wt, val, limit) << endl; 

    return 0;
}