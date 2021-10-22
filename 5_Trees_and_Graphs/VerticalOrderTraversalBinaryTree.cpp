#include<bits/stdc++.h>
using namespace std;

/*

Question: Print a binary tree in vertical manner,
Think of a binary tree divided into columns,
and going to either a left or right child takes up one unit of space.
Think of it as horizontal distance from root node (imagine all the edges are laid out flat)

So, vertical printing will be to print nodes columnwise.

How to do this ?
We need to keep track of horizontal distances of all nodes from the root node,
if two nodes have the same horizontal distance from the root node,
then that means they are on the same column / vertical line

HD = Horizontal Distance
For every right child, HD_right = HD_root + 1
For every left child, HD_left = HD_root - 1

We can do a preorder traversal of the given binary tree to calculate Horizontal Distances
A map (HD -> list of nodes)
Horizontal Distance mapped to a list of nodes

Horizontal Distance of root node is 0
*/
// Structure for a binary tree node
// { Driver Code Starts
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
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    // Function that store a list of nodes corresponding to a particular Horizontal Distance
    map<int, vector<int>> getVerticalOrder(Node* root) {
        map<int, vector<int>> m;
        // using BFS
        // this queue stores pairs containing a Node and it HD
        queue<pair<Node*, int>> q;

        // push the root node with HD as 0
        q.push(make_pair(root, 0));

        // simple BFS
        while(!q.empty()) {
            Node* cur = q.front().first;
            int hd = q.front().second;

            q.pop();
            // insert in the map
            m[hd].push_back(cur -> data);

            if(cur -> left)
                q.push(make_pair(cur -> left, hd - 1));
            if(cur -> right)
                q.push(make_pair(cur -> right, hd + 1));
        }
        return m;
    }

    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> result;
        if(root == NULL)    return result;

        
        // using BFS
        // mapping HD to a vector of nodes
        map<int, vector<int>> m = getVerticalOrder(root);

        // transfer the sequence in a single vector and return it
        
        // declare an iterator
        map<int, vector<int>>::iterator it;
        for(auto it : m) {
            for(int j = 0; j < it.second.size(); ++j)
                result.push_back(it.second[j]);
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


  // } Driver Code Ends