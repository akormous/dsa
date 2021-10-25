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

/*

Brute force approach-
Find all the possible paths, calculate sum and compare with K

Intuition - 
The question asks to find a path from any node to any other node that has a sum K
The basic idea is to apply DFS, but we need to keep track of prefix sum at each node
So DFS can be applied on every node, and keep track of the current sum

*/

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
    // number of paths having sum = k
    // this is global, just think why ?
    int count = 0;
    void DFSUtil(TreeNode* root, int k, int& count) {
        // if we reach null
        if(root == nullptr) return;

        // check if sum is acheived
        if(root -> val == k) 
            count++;
            
        // include this node in the sum and go left
        DFSUtil(root -> left, k - root -> val, count);

        // include this node in the sum and go right
        DFSUtil(root -> right, k - root -> val, count);

    }
    int pathSum(TreeNode* root, int targetSum) {
       if(root != nullptr) {
           DFSUtil(root, targetSum, count);
           pathSum(root -> left, targetSum);
           pathSum(root -> right, targetSum);
       }
       return count;
    }
};