/*

Question: Check subtree.
Given a very large binary tree and a smaller binary tree, determine if the smaller binary tree is a subtree of the larger one.

Approach - 
Do a preorder traversal, and for each root, check if they are identical
recurse for the child nodes as well

So, 2 functions will be created.
Function 1 will check if 2 given nodes are identical (data is identical and recursion for child nodes)
Function 2 will mainly do the preorder traversal and will call Function 1 for checking equality

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
  public:
    // Function to check if 2 trees are identical
    bool areIdentical(Node* root1, Node* root2) {
        // if both of them are NULL, then yey boi
        if(root1 == NULL && root2 == NULL)
            return true;
        // if one of them is NULL, then nope
        if(root1 == NULL || root2 == NULL)
            return false;
        
        // recurse for left child and right child
        return  (root1->data == root2->data) &&
                areIdentical(root1-> left, root2->left) &&
                areIdentical(root1->right, root2->right);

    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {   
        // S = smaller tree, T = bigger tree
        // if smaller tree is NULL, then it is a subtree as the leaf nodes children are also NULL
        if(S == NULL)
            return true;
        // if the bigger tree is NULL, then what even are you going to check ?
        if(T == NULL)
            return false;
        // preorder traversal starts here
        // check if the root node are identical
        if(areIdentical(T, S))
            return true;
        
        // recurse for left and right subtree of T
        return isSubTree(T -> left, S) ||
                isSubTree(T -> right, S);
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}  // } Driver Code Ends