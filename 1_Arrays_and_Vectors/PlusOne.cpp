/* https://practice.geeksforgeeks.org/problems/plus-one/1 */
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int N) {
        // code here
        if(arr.back() != 9)
        {
            arr[arr.size()-1]++;
            return arr;
        }
        arr[arr.size()-1] = 0;
        for(int i = arr.size()-2; i >= 0; i--)
        {
            if(arr[i] != 9)
            {
                arr[i]++;
                return arr;
            }
            else
            {
                arr[i] = 0;
            }
        }
        arr.insert(arr.begin(), 1);
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends