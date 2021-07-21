// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        // create a hash map that has frequency of each number
        unordered_map<int,int> count;
        
        for(int i=0; i < n; i++)
            count[arr[i]]++;
        
        // now, check for a number sum - arr[i]
        int result = 0;
        for(int i=0; i < n; i++)
        {
            result += count[k - arr[i]];
            
            // if sum - arr[i] == arr[i], then we gotta decrease by 1
            if(k - arr[i] == arr[i])
                result--;
        }
            
        return result/2;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends