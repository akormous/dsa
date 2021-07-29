// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // a two pointer approach
        // go to a position in the arr where sum of subarr > x
        int l = 0, r = 0;
        int min_len = n + 1;
        int sum = 0;
        while(r < n) {
            while(sum <= x && r < n)
                // add elements till sum is greater than x
                sum += arr[r++];

            while(sum > x && l < n) {
                // check if min_len subarr is possible
                if(min_len > r - l) {
                    min_len = r - l;
                }
                // subtract elements from the start
                sum -= arr[l++];
            }
        }
        return min_len;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends