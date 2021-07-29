#include<bits/stdc++.h>
using namespace std;

/*
BINARY SEARCH TREE - binary tree that satisfies binary search property

Property - (left->val) < (root->val) < (right->val)
*/

struct Node {
    int val;
    Node* left;
    Node* right;
};

// function to create a new node with a given val
struct Node* createNode(int val) {
    Node* temp = new Node;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// function to insert a node in BST
struct Node* insert(Node* root, int val) {
    // if root is NULL, then create a new node and insert it
    if(root == NULL) {
        return createNode(val);
    }
    // if the val at root is greater than provided val
    // then insert it to the left subtree
    if(root->val > val) {
        root->left = insert(root->left, val);
    }
    // else insert it to the right subtree
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

// display level order traversal of BST
void levelOrderTraversal(Node* root) {
    cout<<"Level order traversal of BST: "<<endl;
    // create a queue
    queue<Node*> q;
    q.push(root);
    // run till queue is not empty
    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
        cout<<cur->val<<" ";
    }
    cout<<endl;
}



int main() {
    // initialize a binary search tree
    Node* root = NULL;
    root = insert(root, 66);
    insert(root, 33);
    insert(root, 99);
    insert(root, 22);
    insert(root, 44);
    insert(root, 77);
    insert(root, 111);
    
    levelOrderTraversal(root);
    //dfs(root);
    return 0;
}