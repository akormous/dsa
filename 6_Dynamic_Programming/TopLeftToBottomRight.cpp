// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        ll dp[m][n];
        
        // put 1 in the 0th row and 0th col
        for(ll i = 0; i < m; i++)
            dp[i][0] = 1;
        
        for(ll j = 0; j < n; j++)
            dp[0][j] = 1;
        
        for(ll i = 1; i < m; i++) {
            for(ll j = 1; j < n; j++) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
            }
        }
        return dp[m-1][n-1]%1000000007;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends