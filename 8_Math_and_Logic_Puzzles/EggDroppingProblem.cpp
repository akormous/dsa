#include<bits/stdc++.h>
using namespace std;

/*
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

*/

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        // n = number of eggs
        // k = floors

        // create a table keeping track of minimum number of tries required to determine the threshold floor, with i eggs and j floors
        int dp[n + 1][k + 1];

        // 0th floor we need 0 tries, no matter how many eggs we got
        // 1st floor we need 1 try, no matter how many eggs we got
        for(int i = 1; i <= n; i++) {
            dp[i][1] = 1;
            dp[i][0] = 0;
        }

        // also for jth floor and only 1 egg, we need j tries (brute force)
        for(int j = 0; j <= k; ++j) {
            dp[1][j] = j;
        }

        int res;
        // this is the juice
        for(int i = 2; i <= n; ++i) {
            for(int j = 2; j <= k; j++) {
                // assume the max possible tries
                dp[i][j] = INT_MAX;
                for(int x = 1; x <= j; ++x) {
                    res = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                    if(res < dp[i][j])
                        dp[i][j] = res;
                }

            }
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends