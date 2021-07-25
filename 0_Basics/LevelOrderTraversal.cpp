#include<bits/stdc++.h>
using namespace std;

/*
LEVEL ORDER TRAVERSAL OF A BINARY TREE
aka Breadth First Traversal

How it works?
It is implemented using a queue.
Algorithm - 
a) Create an empty queue
b) Start from the root node as cur
c) Loop until cur != NULL
    1. display value at cur
    2. enqueue child nodes of cur
    3. cur = queue.front()
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

// LEVEL ORDER TRAVERSAL function
void levelOrderTraversal(Node* root) {
    // declaring an empty queue
    queue<Node*> q;
    Node* cur = root;
    // pushing the root node to the queue
    q.push(cur);
    while(cur != NULL) {
        // displaying the value at cur
        cout<<cur->val<<" ";
        // pushing the child nodes of cur to the queue
        q.push(cur->left);
        q.push(cur->right);
        // removing cur from the front of the queue
        q.pop();
        // updating cur to new Node which is at the front of the queue
        cur = q.front();
    }
}

int main() {
    // defining a simple binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // calling Level Order Traversal on the above binary tree
    levelOrderTraversal(root);
    return 0;
}