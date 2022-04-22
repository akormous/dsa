#include<bits/stdc++.h>
using namespace std;

/*
BINARY TREE - a tree where every node can have atmost 2 child nodes

Properties - 
a) Maximum number of nodes at a level 'l' = 2^(l - 1)
b) Maximum number of nodes in a tree of height 'h' = 2^h - 1
c) In a binary tree with 'n' nodes,
    minimum possible height OR minimum number of levels = ceil( log(n + 1) )
d) A binary tree with 'L' leaves has at least [ ceil( log(L) ) + 1 ] levels

Types of Binary Trees - 

1. Strictly Binary Tree - every node has either 0 or 2 child nodes

2. Complete Binary Tree - every node has 2 child nodes and all leaf nodes are at same level

3. Extended Binary Tree - complete binary tree obtained by adding dummy nodes

4. Threaded Binary Tree - in this type of binary tree,
                          all left child pointers that are NULL, points to its in-order predecessor
                          all right child pointers that are NULL, points to its in-order successor
                          refer - https://upload.wikimedia.org/wikipedia/commons/thumb/7/7a/Threaded_tree.svg/1200px-Threaded_tree.svg.png

Types of Tree traversals - 
1. Breadth First (Level Order Traversal)

2. Depth First
    a) Inorder Traversal
    b) Preorder Traversal
    c) Postorder Traversal
*/

// basic structure of a node in a binary tree
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// utility function to create a node with a given value
Node* newNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    // defining a simple binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    return 0;
}