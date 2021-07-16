// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        // we need 0 jumps to get to the starting of the index
        if(n <= 1)
            return 0;
        // if we cant even go anywhere from 0th position
        if(arr[0] == 0)
            return -1;
        
        // how far can we go
        int maxReach = arr[0];
        // how many steps we have in hand to use
        int step = arr[0];
        // jumps taken if any
        int minJumps = 1;

        // traversing the array
        for(int i=1; i < n; i++)
        {
            if(i == n-1)
                return minJumps;
            // maximizing the reachable index
            maxReach = max(maxReach, i + arr[i]);
            // consumed one step
            step--;

            if(step == 0)
            {
                minJumps++;
                // cant go any further aka no reach left
                if(i >= maxReach)
                    return -1;
                
                step = maxReach - i;
            }
        }
        return minJumps;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends