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
    // Since this is a binary search tree
    // the inorder traversal will be sorted
    int diff = INT_MAX;
    int val = -1;
    
    int getMinimumDifference(TreeNode* root) {
        // if left is valid, go left
        if(root->left)
            getMinimumDifference(root->left);
        
        // the value of node prior to root node in inorder traversal
        // when root is root, val will the value of its left child
        // when root is right child, val will be the value of its root
        if(val >= 0)
            diff = min( diff, root->val - val );
        
        val = root->val;
        
        // if right is valid, go right
        if(root->right)
            getMinimumDifference(root->right);
        
        return diff;
    }
};