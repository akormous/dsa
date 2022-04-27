#include<bits/stdc++.h>
using namespace std;

/*
UNION-FIND

Operations:
Find:
To find which component a particular element belongs to, 
find the root of that component by following the parent nodes
until a self loop is reached (a node who's parent is itself)

Union:
To unify two elements find whcih are the root nodes of each component
and if the root nodes are different
make one of the root nodes be the parent of the other

*/

class UnionFind {
private:
    // number of elements in this union-find
    int size;
    // used to track the size of each of the components
    vector<int> sz;
    // id[i] points to the parent of i, if id[i] = i then i is a root node
    vector<int> id;
    // track the number of components in the union-find
    int numComp;
public:
    // initialize union-find with a size
    UnionFind(int size) {
        if(size <= 0)
            throw "Size <= 0 not allowed!";
        this->size = size;
        this->numComp = size; // initially all of the nodes are root
        sz.resize(size);
        id.resize(size);
        for(int i = 0; i < size; i++) {
            sz[i] = 1;  // each component is initially of size 1
            id[i] = i;  // link to itself
        }
    }

    // find in which component/set 'p' belongs to
    int find(int p) {
        // find the root of 'p'
        int root = p;
        while(root != id[root])
            root = id[root];
        
        // compress the path leading back to the root (path compression)
        while(p != root) {
            int next = id[p];
            id[p] = root;
            p = next;
        }
        return root;
    }
    // unify the components/sets containing 'p' and 'q'
    void unify(int p, int q) {
        int root1 = find(p);
        int root2 = find(q);

        // if they belong to the same set, then nothing to do
        if(root1 == root2)  return;

        // else combine the smaller set to the larger set
        if(sz[root1] > sz[root2]) {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        else {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
        // since we are unifying 2 sets, the number of components decrease by 1
        numComp--;
    }
    // return the size of union-find
    int getSize() {
        return this->size;
    }
    // return the number of components in union-find
    int components() {
        return numComp;
    }
    // return if p and q are in the same set
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

int main() {
    // solution
    UnionFind u(10);

    u.unify(0,5);
    u.unify(5,3);
    u.unify(9,2);
    u.unify(7,8);
    u.unify(3,8);

    cout << u.components() << endl;
    return 0;
}