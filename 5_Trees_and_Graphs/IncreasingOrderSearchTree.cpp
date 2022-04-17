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
    TreeNode* prev = nullptr;   // keep track of the previous node in inorder traversal
    TreeNode* head = nullptr;   // keep track of the root node of the final rearranged tree
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr) return root;
        
        increasingBST(root->left);
        
        if(prev != nullptr) {
            root->left = nullptr;   // set left of root to nullptr
            prev->right = root;     // set the root to the right of previous node (prev keeps track of the previous node in inorder)
        }
        
        if(head == nullptr)
            head = root;    // leftmost node in the tree
        
        prev = root;
        
        increasingBST(root->right);
        
        return head;
    }
};