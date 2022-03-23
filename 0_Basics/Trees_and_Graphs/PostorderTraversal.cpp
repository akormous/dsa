#include<bits/stdc++.h>
using namespace std;

/*
POSTORDER TRAVERSAL - 
Algorithm-
(Recursive)
a) Traverse the left subtree
b) Traverse the right subtree
c) display val

(Using 2 Stacks)
a) Create an empty stack and push root node to it
b) Loop while first stack is not empty
    c) Pop item from first stack and push it to second stack
    d) Push left child of popped item to first stack
    e) Push right child of popped item to first stack
f) Display second stack

Uses-
Postorder traversal is used to get postfix expression of an expression tree

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

// POSTORDER TRAVERSAL recursive function
void postorderTraversal(Node* cur) {
    if(cur == NULL)
        return;
    postorderTraversal(cur->left);
    postorderTraversal(cur->right);
    cout<<cur->val<<" ";
}

// POSTORDER TRAVERSAL using loops (without recursion)
// need to use 2 stacks
void postorderTraversal2(Node* cur) {
    // create 2 empty stacks
    stack<Node*> st1, st2;
    // push the root node to first stack
    st1.push(cur);
    while(!st1.empty()) {
        cur = st1.top();
        st1.pop();
        st2.push(cur);
        if(cur->left)
            st1.push(cur->left);
        if(cur->right)
            st1.push(cur->right);
    }
    // display elements of stack 2
    while(!st2.empty()) {
        cout<<st2.top()->val<<" ";
        st2.pop();
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

    // displaying POSTORDER traversal
    postorderTraversal(root);
    cout<<endl;
    postorderTraversal2(root);
    return 0;
}