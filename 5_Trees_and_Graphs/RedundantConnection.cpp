#include<bits/stdc++.h>
using namespace std;

/*
Just a classic implementation of Union find
*/
class UnionFind {
private:
    vector<int> id; // id[i] = parent of i
    vector<int> sz; // sz[i] = size of component in which i exists
    int nComp;  // number of components at present
    
public:
    UnionFind(int n) {
        this->nComp = n;
        id.resize(n);
        sz.resize(n,1);
        for(int i = 0; i < n; i++)
            id[i] = i;
    }
    // returns the parent of p
    // with path compression
    int find(int p) {
        int tmp = p;
        while(id[p] != p)
            p = id[p];
        
        int root = p;
        while(id[tmp] != tmp) {
            int next = id[tmp];
            id[tmp] = root;
            tmp = next;
        }
        return root;
    }
    
    // unifies the components of p and q
    // returns true if both belong to the same component
    // else unifies them and returns false
    bool unify(int p, int q) {
        int root1 = find(p);
        int root2 = find(q);
        if(root1 == root2)
            return true;
        if(sz[root1] > sz[root2]) {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        else {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
        return false;
    }
    
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n+1);
        
        for(auto& e : edges) {
            if(uf.unify(e[0], e[1]))
                return e;
        }
        return {};
    }
};