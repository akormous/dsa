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
    bool result;

    // function returns height in bottom up manner, go to the deepest node and decrease height by 1 from there
    int dfsUtility(TreeNode* root) {
        // leaf node - height = 0
        if(root == nullptr)
            return 0;
        
        // if result is flipped to false - just break from the recursion stack
        if(!result)
            return 0;

        // height of left subtree
        int leftH = dfsUtility(root->left);
        // height of right subtree
        int rightH = dfsUtility(root->right);
        
        // difference in height
        if(abs(leftH - rightH) > 1)
            result = false;

        return max(leftH, rightH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        // initially assuming the tree to be balanced
        result = true;
        dfsUtility(root);
        return result;
        
    }
};