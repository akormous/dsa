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

struct Node {
    int val;
    Node* left;
    Node* right;
};

struct Node* createNode(int val) {
    Node* temp = new Node;
    temp -> val = val;
    temp -> left = nullptr;
    temp -> right = nullptr;
    return temp;
}

struct Node* insert(struct Node* root, int val) {
    if(root == NULL) {
        return createNode(val);
    }

    if(root -> val > val)
        root -> left = insert(root -> left, val);
    else 
        root -> right = insert(root -> right, val);
    
    return root;
}

vector<int> getPreorderTraversal(Node* root) {
    vector<int> result;

    // preorder - use a stack
    stack<Node*> s;
    
    // insert the root node in the queue
    s.push(root);

    while(!s.empty()) {
        
        Node* cur = s.top();
        s.pop();
        // insert the current node value to the result
        result.push_back(cur -> val);

        // insert the right child and left child of current node
        if(cur -> right)
            s.push(cur -> right);        
        if(cur -> left)
            s.push(cur -> left);
    }
    
    return result;
}

class Solution {
public:
    struct Node* binarySearchInserter(vector<int> nums, int l, int r, Node* root) {
        if(l > r)
            return root;
        
        int m = (l + r)/2;
        root = insert(root, nums[m]);

        root = binarySearchInserter(nums, l, m - 1, root);
        root = binarySearchInserter(nums, m + 1, r, root);
        return root;
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        // creating the minimal binary search tree
        Node* root = NULL;

        root = binarySearchInserter(nums, 0, nums.size() - 1, root);
    
        return getPreorderTraversal(root);
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