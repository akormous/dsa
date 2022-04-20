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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        
        if(root == nullptr) return result;
        
        q.push(root);
        bool zigzag = false;    // a bool flag to denote if val needs to inserted at the front or the back
        
        while(!q.empty()) {
            vector<int> vals;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                
                if(zigzag)  vals.insert(vals.begin(), cur->val);
                else        vals.push_back(cur->val);
                
                if(cur->left)   q.push(cur->left);
                if(cur->right)  q.push(cur->right);
            }
            
            result.push_back(vals);
            vals.clear();
            zigzag = !zigzag;
        }
        return result;
    }
};