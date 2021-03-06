#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        queue<Node*> q;
        unordered_map<int, Node*> mp;
        
        q.push(node);
        
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            
            // if cur is not cloned
            if(mp.find(cur->val) == mp.end()) {
                Node* clone = new Node(cur->val);
                mp[clone->val] = clone;
            }
            
            // go through all of the neighbors
            for(auto nb : cur->neighbors) {
                if(mp.find(nb->val) == mp.end()) {
                    Node* tmpclone = new Node(nb->val);
                    mp[tmpclone->val] = tmpclone;
                    q.push(nb);
                }
                mp[cur->val]->neighbors.push_back( mp[nb->val] );
            }
        }
        return mp[1];
    }
};

/*
Depth First Search - Approach Easier to understand
*/
class Solution2 {
    unordered_map<Node*, Node*> copies;     // maps original node to copy
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        
        // if current node is not cloned
        if(copies.find(node) == copies.end()) {
            // clone it
            copies[node] = new Node(node->val, {});
            // go to each neighbor of this node and push the neighbors
            for(auto& n : node->neighbors) {
                copies[node]->neighbors.push_back( cloneGraph(n) ); 
            }
        }
        return copies[node];
    }
};