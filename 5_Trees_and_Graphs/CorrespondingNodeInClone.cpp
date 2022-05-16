#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * @brief Depth First Search
 * 
 */
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == nullptr) return nullptr;
        
        if(original == target)  return cloned;
        
        TreeNode* l = getTargetCopy(original->left, cloned->left, target);
        TreeNode* r = getTargetCopy(original->right, cloned->right, target);
        
        return l == nullptr ? r : l;
    }
};

/**
 * @brief Breadth First Search
 * 
 */
class Solution2 {
public:
    TreeNode* getTargetCopy(TreeNode* root1, TreeNode* root2, TreeNode* target) {
        queue<TreeNode*> q1;    q1.push(root1); // bfs on root1
        queue<TreeNode*> q2;    q2.push(root2); // bfs on root2
        
        while(!q1.empty()) {
            TreeNode* cur1 = q1.front();
            q1.pop();
            TreeNode* cur2 = q2.front();
            q2.pop();
            if(cur1 == target) {
                return cur2;
            }
            
            if(cur1->left) {
                q1.push(cur1->left);
                q2.push(cur2->left);
            }
            if(cur1->right) {
                q1.push(cur1->right);
                q2.push(cur2->right);
            }
        }
        return nullptr;
        
    }
};