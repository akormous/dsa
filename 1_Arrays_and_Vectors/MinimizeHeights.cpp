// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
/*

Question: Minimize the heights of towers by adding or subtracting k from each tower once

*/
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int maxEle, minEle;
        // getting the difference between max and min height
        int res = arr[n-1] - arr[0];
        for(int i=1; i<n; i++)
        {
            if(arr[i] >= k && arr[n-1] >= k)
            {
                // keeping track of max element as we add or subtract k
                maxEle = max(arr[i-1] + k, arr[n-1] - k);
                // keeping track of min element
                minEle = min(arr[0] + k, arr[i] - k);
                // updating the difference
                res = min(res, maxEle - minEle);
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends