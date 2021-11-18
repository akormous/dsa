// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        int res = 0;
        
        // for every box, there can be max 3 unique configs
        // so lets consider every unique config of a box as new box
        
        // making a data structure that will be easier to work with
        vector<vector<int>> boxes;
        // index 0 = width
        // index 1 = length
        // index 2 = height
        for(int i = 0; i < n; ++i) {
            // config 1 - original
            boxes.push_back(
                {
                    max(width[i], length[i]),
                    min(width[i], length[i]),
                    height[i]
                }
            );
            
            // config 2 - swap width and height
            boxes.push_back(
                {
                    max(length[i], height[i]),
                    min(length[i], height[i]),
                    width[i]
                }
            );
            
            // config 3 - swap length and height
            boxes.push_back(
                {
                    max(width[i], height[i]),
                    min(width[i], height[i]),
                    length[i]
                }
            );
        }
        
        // push a hypothetical box of dimensions {0,0,0}
        boxes.push_back({0,0,0});
        
        // sort the boxes in increasing order of width
        sort(begin(boxes), end(boxes));
        
        int N = boxes.size();
        // store the max height
        int dp[N];
        memset(dp, 0, sizeof(dp));
        int maxH = 0;
        
        for(int j = 1; j < N; j++) {
            for(int i = 0; i < j; i++) {
                // check if ith box can be placed on top of jth box
                if(boxes[i][0] < boxes[j][0] &&
                    boxes[i][1] < boxes[j][1]) {
                        
                    dp[j] = max(dp[j], dp[i] + boxes[j][2]);
                    maxH = max(maxH, dp[j]);
                }
            }
        }
        
        return maxH;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends