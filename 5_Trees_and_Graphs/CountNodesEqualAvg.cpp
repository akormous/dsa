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
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    
    /*
    DFS solution
    returns pair<int,int> {sum_of_subtree, count_of_nodes_in_that_subtree}
    */ 
    pair<int,int> dfs(TreeNode* root) {
        if(root == NULL) return {0,0};
        
        // get sum of left subtree and count of nodes
        auto left = dfs(root->left);
        int leftSum = left.first;   // sum of nodes in left subtree
        int leftCount = left.second; // count of nodes in left subtree
        
        auto right = dfs(root->right);
        int rightSum = right.first;  // sum of nodes in right subtree
        int rightCount = right.second; // count of nodes in right subtree
        
        int curSum = root->val + leftSum + rightSum;    // sum of nodes in current subtree
        int curCount = leftCount + rightCount + 1;  // count of nodes in current subtree
        
        int curAvg = curSum/curCount; // avg of cur subtree
                
        // check if curAvg is equal to root->val
        if(root->val == curAvg)
            count++;    // increase the count
        

        // return pair of curSum, curCount 
        return {curSum, curCount};
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }

};