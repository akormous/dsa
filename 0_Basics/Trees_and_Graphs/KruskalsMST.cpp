#include<bits/stdc++.h>
using namespace std;

/*
Find Minimum-Spanning Tree in a given graph
*/

class UnionFind {
private:
    int size;
    vector<int> id; // id[i] points to the parent of i
    vector<int> sz; // size of each set/component

public:
    UnionFind(int size) {
        if(size <= 0)
            throw "size <= 0 not allowed";
        this->size = size;
        id.resize(size);
        sz.resize(size);
        for(int i = 0; i < size; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    // returns the parent of a node 'p'
    int find(int p) {
        int root = p;
        while(root != id[root])
            root = id[root];
        
        // compress path
        while(p != root) {
            int next = id[p];
            id[next] = root;
            p = next;
        }
        return root;
    }

    // unifies the sets containing 'p' and 'q'
    void unify(int p, int q) {
        int root1 = find(p);
        int root2 = find(q);
        if(root1 == root2)  return;

        if(sz[root1] > sz[root2]) {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        else {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
    }
};

bool compareWeight(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Graph {
    vector<vector<int>> edges;  // edge = {w, x, y}
    int v;  // number of nodes in the graph
    
public:
    
    // initialize a graph with number of nodes = v
    Graph(int v) {
        this->v = v;
    }
    // add edge to the graph
    void addEdge(int x, int y, int w) {
        edges.push_back({w, x, y});
    }
    // calculate mst cost
    int minSpanningTreeCost() {
        int cost = 0;
        sort(edges.begin(), edges.end(), compareWeight);    // sort the edges is increasing order of weight
        UnionFind ds(v);    // initialize Union find data structure

        for(auto& edge : edges) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // if x and y belong to different sets
            if(ds.find(x) != ds.find(y)) {
                ds.unify(x, y); // combine the sets
                cost += w;  // add cost
            }
        }
        return cost;    // return the final mst cost
    }
};

int main() {
    // solution
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    cout << "MST cost = " << g.minSpanningTreeCost() << endl;

    return 0;
}