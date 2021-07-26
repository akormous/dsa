// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      // use an unordered set
      unordered_set<int> uset;

      // insert all the elements in this set
      for(int i = 0; i < n; i++)
        uset.insert(arr[i]);
      
      int result = 0;

      // traverse the array now
      for(int i = 0; i < n; i++) {

          // if the element is not present in the set, then it should be the first element in the subsequence
          if(uset.find(arr[i] - 1) == uset.end()) {

              int local_max = 0;
              int cur = arr[i];

              // check how many consecutive numbers are present
              while(uset.find(cur + 1) != uset.end()) {
                  local_max++;
                  cur++;
              }
                
              // check if this subsequence length is more than the global max
              result = max(result, local_max);
          }
      }
      // return global max
      return result;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends