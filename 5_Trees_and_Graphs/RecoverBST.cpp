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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    // initialize prev element as INT_MIN val
    TreeNode* prev = new TreeNode(INT_MIN);
    
    void inorder(TreeNode* root) {
        if(root == nullptr)
            return;
        
        inorder(root->left);
        
        // our business is to check out of order nodes
        if(first == nullptr && prev->val > root->val)
            first = prev;
        
        if(first != nullptr && prev->val > root->val)
            second = root;
        
        prev = root;
        
        inorder(root->right);

    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        // swap the values of first and second
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};