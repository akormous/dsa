// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // the catch is to keep track of left and right buildings
        // a two pointer approach
        int l = 0, r = n - 1;
        // and two more variables to keep track of tallest buildings on the left and right at any index
        int left_max = 0, right_max = 0;

        // resulting amount of water that can be stored
        int result = 0;
        while(l <= r) {
            if(arr[l] < arr[r]) {
                if(left_max < arr[l]) {
                    left_max = arr[l];
                }
                else {
                    result += left_max - arr[l];
                }
                l++;
            }
            else {
                if(right_max < arr[r]) {
                    right_max = arr[r];
                }
                else {
                    result += right_max - arr[r];
                }
                r--;
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends