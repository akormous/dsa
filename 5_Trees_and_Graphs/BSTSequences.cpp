#include<bits/stdc++.h>
using namespace std;

/*
Question: A BST was created by traversing through an array from left to right and inserting each element.
Find all the possible arrays that could lead to the same exact BST.

Read this medium blog - https://medium.com/@jackwootton/binary-search-tree-sequences-53163b1f374a

The approach is to maintain a prefix list and just reorder items from subtree lists (all valid permutations)
*/


template <typename T>
class TreeNode {
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// You need to store all the valid sequences in the "ans" vector
vector<vector<int>> BSTSequence(TreeNode <int> * root)
{
    // base case 1 : if root is NULL
    if(root == NULL) {
        // then return an empty sequence
        vector<int> seq;
        // create a vector of vectors to match the return argument
        vector<vector<int>> res;
        res.push_back(seq);

        return res;
    }

    // base case 2 : if left and right child are NULL
    if(root -> left == NULL && root -> right == NULL) {
        // then return the data of the root node
        vector<int> seq;
        seq.push_back(root -> data);

        vector<vector<int>> res;
        res.push_back(seq);
        return res;
    }

    // main logic starts here
    // store the left subtree sequence and right subtree sequence
    vector<vector<int>> leftSeq, rightSeq;

    // vector that will store the resulting merged sequences
    vector<vector<int>> result;

    // recurse for left and right subtree
    leftSeq = BSTSequence(root -> left);
    rightSeq = BSTSequence(root -> right);

    // the size of the merged sequence
    int size = leftSeq[0].size() + rightSeq[0].size() + 1;

    // initialize a bool flag vector to keep track of permutations of the sequences
    // this vector will contain leftSeq[0].size() number of 0s
    // and rightSeq[0].size() number of 1s
    // an element from leftSeq is represented by 0 and from the rightSeq is represented by 1
    vector<bool> flag(leftSeq[0].size(), 0);    // initializing a vector

    // fill with 1s
    for(int k = 0; k < rightSeq[0].size(); ++k)
        flag.push_back(1);

    // here is the generation of all possible and valid permutations
    // these permutations will be tracked using the flag vector
    for(int i = 0; i < leftSeq.size(); ++i) {
        for(int j = 0; j < rightSeq.size(); ++j) {

            do {
                // a temp vector that will store a sequence
                vector<int> tmp(size);

                // the first node will be the root node
                tmp[0] = root -> data;

                // initialize 2 pointers
                int a = 0, b = 0;

                // start traversing from 0 to the size of flag vector
                for(int k = 0; k < flag.size(); ++k) {
                    // if it is 1, then get item from rightSeq
                    if(flag[k]) {
                        tmp[k + 1] = rightSeq[j][b++];
                    }
                    // else if it is 0, then get item from leftSeq
                    else {
                        tmp[k + 1] = leftSeq[i][a++];
                    }
                }
                result.push_back(tmp);
            } 
            // get the next permutation using inbuilt C++ function
            while(next_permutation(flag.begin(), flag.end()));
        }
    }
    return result;
}