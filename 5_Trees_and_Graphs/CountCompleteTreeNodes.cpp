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
/*
TC: O(logn * logn)
*/
class Solution {
public:
    // to find left subtree height, go left->left->left ...
    int getLeftHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        return getLeftHeight(root->left) + 1;
    }
    // to find right subtree height, go right->right->right ...
    int getRightHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        return getRightHeight(root->right) + 1;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int leftH = getLeftHeight(root);
        int rightH = getRightHeight(root);
        
        // left and right height are equal. then use the formula number of nodes = (2^h - 1)
        if(leftH == rightH)
            return (1 << leftH) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};