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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* first = nullptr;  // first uncool node
    TreeNode* second = nullptr; // second uncool node
    TreeNode* prev = new TreeNode(INT_MIN); // keep track of the previous node in inorder traversal
    
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        
        inorder(root->left);
        
        if(first == nullptr && root->val < prev->val)
            first = prev;
        
        if(first != nullptr && root->val < prev->val)
            second = root;
        
        prev = root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        swap(first->val, second->val);
        
    }
};