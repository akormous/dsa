/*
Find if an array contains a subarr with given sum
Calculate number of subarrays with given sum
NOTE: The array can contain negative numbers as well 
*/
// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    int subArraySum(int arr[], int n, int sum)
    {
    	// a hashmap that stores the number of time a sum has been encountered.
    	unordered_map<int,int> umap;

    	int cur_sum = 0;
        // number of subarrays aka answer
    	int count = 0;
    	
    	for(int i = 0; i < n; i++) {
    	    cur_sum += arr[i];

    	    if(cur_sum == sum)
    	        count++;

    	    if(umap.find(cur_sum - sum) != umap.end())
    	        count += umap[cur_sum - sum];
    	    
            // increase the frequency of a particular sum
    	    umap[cur_sum]++;
    	}
    	return count;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    cin>>sum;
	    Solution ob;
	    cout<<ob.subArraySum(arr, n, sum);
	    cout<<'\n';
	}
	return 0;
}  // } Driver Code Ends