/*

Coins: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and
pennies (1 cent), write code to calculate the number of ways of representing n cents.
Generic question: Given an array of denominations

Approach:

Let m = number of denominations
Let n = given n cents to make from those m denominations



*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

    long long int count(int S[], int m, int n) {
        long long int table[n+1][m];

        // for making 0 money, there is only 1 way (no coins)
        for(int j = 0; j < m; j++)
            table[0][j] = 1;
        
        // bottom-up DP
        // start by making 1 cent from the given coins, then move up the ladder
        for(int i = 1; i < n+1; ++i) {
            // take each coin one by one
            for(int j = 0; j < m; j++) {
                // count of solutions including S[j]
                long long int x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

                // count of solutions excluding S[j]
                long long int y = ( j >= 1 ) ? table[i][j-1] : 0;

                table[i][j] = x + y;
            }
        }
        return table[n][m-1];
    }

    
    long long int count2(int S[], int m, int n) {
        int table[n + 1];

        memset(table, 0, sizeof(table));

        // base case - number of ways to make 0 cents
        table[0] = 1;

        // take coins one by one
        for(int i = 0; i < m; i++) {
            // for each sum of money, the number of solutions will be
            // existing_solutions + table[sum - S[i]]
            // start from the coin to avoid negative stuff
            for(int j = S[i]; j <= n; j++) {
                table[j] = table[j] + table[j - S[i]];
            }
        }
        return table[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends