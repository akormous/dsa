/*

Find the length of the longest increasing subsequence

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    /*
    TIME COMPLEXITY = O(n^2)
    */
    int longestSubsequence2(int n, int a[]) {
        // create dp
        // dp[i] stores the length of the longest increasing subsequence ending at ith index
        int dp[n];

        // overall maximum length LIS
        int gMax = 0;

        for(int i = 0; i < n; i++) {
            // stores the length of LIS ending at ith index
            int lMax = 0;

            for(int j = 0; j < i; j++) {
                if(a[i] > a[j]) {
                    lMax = max(lMax, dp[j]);
                }
            }

            dp[i] = lMax + 1;

            gMax = max(gMax, dp[i]);

        }
        return gMax;
        
    }

    //Function to find length of longest increasing subsequence.
    /*
    TIME COMPLEXITY = O(n * logn)
    */
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> seq;
       // insert the first element in the sequence
       seq.push_back(a[0]);
       
       // traverse the array 
       for(int i = 1; i < n; i++) {
           if(a[i] <= seq.back()) {
               // get the index of element which is just greater than or equal to a[i]
               int idx = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
               
               // place a[i] at its suitable position in the sorted seq
               seq[idx] = a[i];
           }
           else {
               seq.push_back(a[i]);
           }
       }
       return seq.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence2(n, a) << endl;
    }
}
  // } Driver Code Ends