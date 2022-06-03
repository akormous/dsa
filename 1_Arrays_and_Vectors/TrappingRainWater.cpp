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
            // if the left building height is minimum among (arr[l], arr[r]) Why ? 
            // because the water that can stored, can only be against the building which has lesser height among(arr[l], arr[r])
            // so there is no point of knowing the rmax when we have already established that the left building is of less height
            if(arr[l] < arr[r]) {
                if(left_max < arr[l]) { // update left max if a taller building appears
                    left_max = arr[l];
                }
                else {
                    result += left_max - arr[l];    // else add the water that can be stored
                }
                l++;
            }
            // else the right building height is minimum among (arr[l], arr[r])
            else {  
                if(right_max < arr[r]) {    // update right max if a taller building appears
                    right_max = arr[r];
                }
                else {
                    result += right_max - arr[r];   // else add the water that can be stored
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