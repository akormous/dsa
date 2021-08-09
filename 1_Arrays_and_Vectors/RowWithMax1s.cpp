// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    /*
        1. In the first row, check at which position the first 1 appears
        2. From that index, go down, if there is a 1, then move left till a 0 appears
        3. repeat till end of rows
        */
       // also keep a track of max 1s because we only need to return the index of first row that has maximum 1s
       int max1s = 0;
       int ans = 0;
       // find the index of first 1 in the 0th row
       int i;
       for(i = 0; i < m; i++)
        if(arr[0][i] == 1)
            break;
       
       int pos = i;
       if(pos == 0)
        return ans;

        max1s = m - pos;
        if(pos == m) {
            pos--;
        }    
        


       // now i is the position from where we need to go down the matrix
       // go down, if its zero then ignore
       // else move left till we find a 1 and update ans
       for(i = 1; i < n; i++) {
           if(arr[i][pos] == 1) {
               while(pos >= 0 && arr[i][pos] == 1)
                pos--;
               
               pos++;
               if(max1s < (m - pos)) {
                   ans = i;
                   max1s = m - pos;
               }
           }
       }
       if(max1s == 0)
        return -1;
	    return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends