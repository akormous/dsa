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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        
        // Approach : BFS
        // push the root node
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            
            // swap the left and right subtree
            TreeNode* left = cur->left;
            cur->left = cur->right;
            cur->right = left;
            
            // if left child is valid
            if(cur->left)   q.push(cur->left);
            // if right child is valid
            if(cur->right)  q.push(cur->right);
        }
        
        return root;
    }
};