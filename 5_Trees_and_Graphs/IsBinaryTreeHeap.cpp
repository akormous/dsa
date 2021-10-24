// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


/*

Question: Is the given binary tree max-heap ?


Approach:
Heap has 2 basic properties
1. root node is greater than its children
2. nodes are filled from left to right

Then a level order traversal can be done
While traversing, we will keep a check on the completeness of the tree (nodes filled from left to right)
and also the root greater property
*/

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(struct Node* root) {
        // level order traversal
        queue<Node*> q;
        // push the root node
        q.push(root);
        
        // a flag for checking the completeness property
        bool isNullLevel = false;
        while(!q.empty()) {
            // get the current node
            Node* cur = q.front();
            q.pop();

            // if cur->left is not null
            if(cur->left) {
                // if null level is reached already, or the 1st property is not satisfied
                if(isNullLevel || cur->left->data > cur->data)
                    return false;
                // push the left node
                q.push(cur->left);
            }
            // else if cur->left is null, set null level
            else {
                isNullLevel = true;
            }
            // if cur->right is not null
            if(cur->right) {
                // if null level is reached already, or the 1st property is not satisfied
                if(isNullLevel || cur->right->data > cur->data)
                    return false;
                // push the right node
                q.push(cur->right);
            }
            // else if cur->right is null, set null level
            else {
                isNullLevel = true;
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}  // } Driver Code Ends