#include<bits/stdc++.h>
using namespace std;

/*
INORDER TRAVERSAL - 
Algorithm-
(Recursive)
a) Traverse the left subtree
b) display val
c) Traverse the right subtree

(Using Stack)
a) Create an empty stack
b) Goto the leftmost node in the tree till cur != NULL
c) Pop node from stack, print it
b) Set cur = popped_item->right

Uses-
In case of BST, inorder traversal gives nodes in increasing order

Time Complexity -O(n) in both ways
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

// INORDER TRAVERSAL recursive function
void inorderTraversal(Node* cur) {
    if(cur == NULL)
        return;
    inorderTraversal(cur->left);
    cout<<cur->val<<" ";
    inorderTraversal(cur->right);
}

// INORDER TRAVERSAL using loops (without recursion)
// need to use a stack
void inorderTraversal2(Node* cur) {
    // create an empty stack
    stack<Node*> st;
    while(cur != NULL || !st.empty()) {
        // goto the leftmost node in the tree
        while(cur != NULL) {
            st.push(cur);
            cur = cur->left;
        }
        // pop node from stack
        cur = st.top();
        st.pop();
        // print it
        cout<<cur->val<<" ";
        // set cur to cur->right
        cur = cur->right;
    }
}

int main() {
    // defining a simple binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);

    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(9);

    // displaying inorder traversal
    inorderTraversal(root);
    cout<<endl;
    inorderTraversal2(root);
    return 0;
}