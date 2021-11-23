#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> in;
    void inorder(TreeNode* root, int k) {
        if(root == NULL)    return;
        
        inorder(root->left, k);
        if(k == 0)
            return;
        in.push_back(root->val);
        k--;
        inorder(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root, k);
        return in[k - 1];
    }
};