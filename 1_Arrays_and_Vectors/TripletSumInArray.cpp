// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        if(n < 3) {
            return false;
        }
        // sort the array and use two pointers?
        sort(A, A + n);
        for(int i = 0; i < n - 2; i++) {
            int j = i + 1; // just the next element from i
            int k = n - 1; // largest element in the array (cuz we sorted it)

            while(j < k) {
                int sum = A[i] + A[j] + A[k];
                // if we have reached some numbers whose sum is X, then return true
                if(sum == X)
                    return true;
                // else if sum > X, then decrease k by 1
                if(sum > X)
                    k--;
                // else if sum < X, then increase j by 1
                else if(sum < X)
                    j++;
            }
        }
        // if unable to find sum, then return false
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends