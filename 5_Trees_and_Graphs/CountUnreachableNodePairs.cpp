#include<bits/stdc++.h>
using namespace std;

/*
Union-Find data structure implementation with path compression
*/
class UnionFind {
public:
    int n;    // number of nodes
    int c;    // number of components
    vector<int> sz;   // size of each component
    vector<int> id;     // parent of each node
    
    // constructor
    UnionFind(int iN) {
        n = iN;
        c = iN;
        sz.resize(iN);
        id.resize(iN);
        for(int i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    
    /*
    Returns the root of a given node
    */
    int find(int i) {
        int root = i;
        while(root != id[root])
            root = id[root];
        // path compression - modify the root of all the nodes
        while(i != root) {
            int next = id[i];
            id[i] = root;
            i = next;
        }
        return root;
    }
    
    /*
    Unifies 2 components, given their id
    */
    void unify(int p, int q) {
        int root1 = find(p);    // get root of p
        int root2 = find(q);    // get root of q
        
        if(root1 == root2)  return; // if they are in the same component, then return
        
        // merge the smaller component into bigger component
        if(sz[root1] >= sz[root2]) {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        else {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind* uf = new UnionFind(n);    // initialize a uf data structure
        
        // add every edge in uf
        for(vector<int>& e : edges) {
            uf->unify(e[0], e[1]);
        }
        
        // if there is only 1 component, which means every node in the graph is connected
        if(uf->c == 1)
            return 0;
        
        /*
        Now, to calculate the number of disconnected pair counts
        We will go through each component/graph in our UnionFind data structure,
        and get the pair count by multiplying the sizes of graph
        For example, if the size of components are 4, 1, and 2
        then the number of disconnected pairs of node between g(4) and g(1) = 4*1 = 4
        then we will unify these 2 graphs, so new graph becomes of size 5 = g(5)
        so, pair count between g(5) and g(2)  = 5*2 = 10
        Total pair count = g(4)*g(1) + g(5)*g(2) = 4 + 10
        Summary - We cumulatively unify the graph that we are processing and calculate the pair count
        */
        long long res = 0;      // disconnected pair count
        long long nodeCount = 0;    // number of nodes in the graph
        
        for(int i = 0; i < n; i++) {
            // if this is a root of some component
            if(uf->id[i] == i) {
                // if this is the 1st component that we encountered
                if(nodeCount == 0) {
                    nodeCount = uf->sz[i];
                }
                else {
                    // add up the pair count
                    res = res + nodeCount*(uf->sz[i]);
                    // update the node count in cumulative graph
                    nodeCount += uf->sz[i];
                }
            }
        }
        
        return res;
        
    }
};