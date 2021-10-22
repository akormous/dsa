// { Driver Code Starts
//Initial Template for C++

/*
Question: Print the top view of a binary tree.
So, print from the leftmost node to the rightmost node

Approach:
If you know how to calculate Horizontal distance of each node from the root,
then this question will be easy peasy

Calculate HD for each node, and then just display the first node of the partical HD list

Also, if you think about it, we dont even want all of the nodes, we just want the first one,
so there is no need to maintain a map
A lesser time complexity can be achieved if we use stack for left subtree and simple list for right subtree
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> result;
        if(root == NULL)    return result;

        // using a stack for left subtree, because in the final result, the order should be reversed
        stack<int> left;
        
        // using a simple vector for right subtree
        vector<int> right;

        // queue containing pairs of Node and its horizontal distance
        queue<pair<Node*, int>> q;
        // for root hd = 0
        // l and r represent the current farthest horizontal distance of a node from the root
        int hd = 0, l = 0, r = 0;
        q.push(make_pair(root, hd));
        Node* cur;
        while(!q.empty()) {
            cur = q.front().first;
            int hd = q.front().second;

            // if a new farthest left node is found, then push it to the left stack
            if(hd < l) {
                left.push(cur -> data);
                l = hd;
            }
            // if a new farthest right node is found, then push it to the right vector
            else if(hd > r) {
                right.push_back(cur -> data);
                r = hd;
            }

            // if there is a left node
            if(cur -> left) {
                q.push(make_pair(cur -> left, hd - 1));
            }
            // if there is a right node
            if(cur -> right) {
                q.push(make_pair(cur -> right, hd + 1));
            }
            // remove the current node
            q.pop();
        }

        // transfer the sequence from stack to result
        while(!left.empty()) {
            result.push_back(left.top());
            left.pop();
        }
        // push the root node data
        result.push_back(root -> data);
        // transfer the sequence from right vector to result
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends