#include<bits/stdc++.h>
using namespace std;

/*
PREORDER TRAVERSAL - 
Algorithm-
(Recursive)
a) display val
b) Traverse the left subtree
c) Traverse the right subtree

(Using Stack)
a) Create an empty stack
b) Push the root node to stack
c) Loop while stack is not empty
    d) pop item from stack, print it
    e) push right child to stack
    f) push left child to stack

Uses-
Preorder traversal is used to create a copy of the tree
It is also used to get prefix expression of an expression tree
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

// PREORDER TRAVERSAL recursive function
void preorderTraversal(Node* cur) {
    if(cur == NULL)
        return;
    cout<<cur->val<<" ";
    preorderTraversal(cur->left);
    preorderTraversal(cur->right);
}

// PREORDER TRAVERSAL using loops (without recursion)
// need to use a stack
void preorderTraversal2(Node* cur) {
    // create an empty stack
    stack<Node*> st;
    // push root node to stack
    st.push(cur);
    while(!st.empty()) {
        cur = st.top();
        st.pop();
        cout<<cur->val<<" ";
        if(cur->right != NULL)
            st.push(cur->right);
        if(cur->left != NULL)
            st.push(cur->left);
    }
}

int main() {
    // defining a simple binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // displaying preorder traversal
    preorderTraversal(root);
    cout<<endl;
    preorderTraversal2(root);
    return 0;
}