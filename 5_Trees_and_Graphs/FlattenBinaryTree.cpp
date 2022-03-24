#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    bool isLeaf(TreeNode* node) {
        return (node->left == nullptr && node->right == nullptr);
    }
    
    TreeNode* utility(TreeNode* root) {
        
        if(root == nullptr)
            return nullptr;
    
        // tail of left Flattened subtree
        TreeNode* L = utility(root->left);
        
        // tail of right flattened subtree
        TreeNode* R = utility(root->right);
        
        if(R && L) {
            L->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            return R;
        }
        else if(L) {
            root->right = root->left;
            root->left = nullptr;
            return L;
        }
        else if(R)
            return R;        
         
        return root;
    }
    
    void flatten(TreeNode* root) {
        
        utility(root);
                
    }
};