#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

/*

Question: Implement a binary tree class from scratch, but apart from the usual operations of insert, find and delete,
implement a new operation, getRandomNode() which returns a random node from the tree
Each node in the tree should be equally likely to be chosen


*/

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    int children;   // number of children a node has

    // constructor
    Node(int val) {
        data = val;
        left = NULL; right = NULL;
        children = 1;
    }

    // function that returns the number of children
    int size() {
        return children;
    }

    // insert inorder
    void insertInorder(int val) {
        
        if(val <= data) {
            if(left == NULL) {
                left = new Node(val);
            }
            else
                left -> insertInorder(val);
        }
        else {
            if(right == NULL)
                right = new Node(val);
            else
                right -> insertInorder(val);
        }
        children++;
    }

    // find a node by value in the binary tree and return it
    Node* find(int val) {
        if(val == data)
            return this;
        else if(val <= data)
            return (left ? left -> find(val) : NULL);
        else if(val > data)
            return (right ? right -> find(val) : NULL);
        else
            return NULL;
    }

    // returns a random node by taking in a random number in range
    Node* getRandomUtil(int randomNumber) {
        // number of children of left child
        int leftSize = (left == NULL ? 0 : left -> size());

        if(randomNumber < leftSize)
            return left -> getRandomUtil(randomNumber);
        else if(randomNumber == leftSize)
            return this;
        else
            return right -> getRandomUtil(randomNumber -  (leftSize + 1));
    }

};

class BinaryTree {
    public:
    Node* root;
    BinaryTree() {
        root = NULL;
    }
    // function that returns the number of children
    int size() {
        return (root == NULL ? 0 : root -> size());
    }

    // insert in order in the tree
    void insertInorder(int val) {
        if(root == NULL)
            root = new Node(val);
        else
            root -> insertInorder(val);
    }

    // get random node
    Node* getRandomNode() {
        if(root == NULL)
            return NULL;
        // generate a random number
        Sleep(1000);
        srand(time(0));
        int randomNumber = rand() % (root -> size() + 1);

        // get ith node
        return root -> getRandomUtil(randomNumber);
    }

};


int main() {
    // solution
    BinaryTree t1;
    vector<int> arr = {1,2,4,1,532,6,45,6,75,7,4,87675,8,34,55,9867,9,89};
    cout<<"Populating Binary tree ..."<<endl;
    for(auto i : arr) {
        t1.insertInorder(i);
    }
    cout<<"Getting random nodes ..."<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    cout<<t1.getRandomNode() -> data<<endl;
    return 0;
}