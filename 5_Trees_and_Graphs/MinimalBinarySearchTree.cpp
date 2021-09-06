// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*

Question: 
Given a sorted array, write an algorithm to create a minimal BST
(of minimum height possible)

Approach:

for minimum height, there must be equal number of elements in the left and right subtree

So, the root element will be the middle element of the sorted array

Similary, when the array is divided into two equal parts, then again
the root of the subtree will be the middle element of the sorted part

So, there is kind of a binary search pattern on the array

So apply binary search recursively and create the BST

*/

 // } Driver Code Ends
class Solution {
public:
    void binarySearchInserter(vector<int> nums, int l, int r, vector<int>& result) {
        if(l > r)
            return;
        
        int m = (l + r) / 2;

        result.push_back(nums[m]);

        binarySearchInserter(nums, l, m - 1, result);
        binarySearchInserter(nums, m + 1, r, result);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        // basically this question is to convert from inorder to preorder
        vector<int> result;
        binarySearchInserter(nums, 0, nums.size() - 1, result);
        return result;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends