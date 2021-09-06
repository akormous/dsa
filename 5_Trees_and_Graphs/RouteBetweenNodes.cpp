#include<bits/stdc++.h>
using namespace std;

/*

Question: Given a directed graph, design an algorithm to find out whether there is a route between two nodes

*/

class Graph {
    int V;  // number of vertices
    list<int> *adj; // pointer to an array containing adjacency list

    public:

    Graph(int V) {
        this -> V = V;
        adj = new list<int>[V];
    }
    // creates an edge from node a to node b
    void addEdge(int a, int b) {
        adj[a].push_back(b);
    }
    // a function that checks if node b is reachable from node a
    bool isReachable(int a, int b) {
        // if they are the same node
        if(a == b)
            return true;

        // apply BFS from node a
        queue<int> q;
        bool visited[V];
        memset(visited, 0, sizeof(visited));

        q.push(a);
        visited[a] = true;

        while(!q.empty()) {
            int cur = q.front();
            q.pop();

            // check all neighbours of current node
            for(auto i : adj[cur]) {
                // if any of them is b, then return true
                if(i == b)
                    return true;

                // visit the node and add it to the queue
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return false;
    }
    // dfs utility
    void dfsUtil(bool visited[], int src, int dest) {
        if(visited[dest])
            return;

        visited[src] = true;

        for(auto i : adj[src]) {
            if(!visited[i])
                dfsUtil(visited, i, dest);
        }
    }
    // isReachable using DFS
    bool isReachable2(int a, int b) {
        bool visited[V];
        memset(visited, 0, sizeof(visited));

        dfsUtil(visited, a, b);

        return visited[b];
    }
};


int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout<<"isReachable(1,3) = "<<g.isReachable(1,3)<<endl;
    cout<<"isReachable(3,1) = "<<g.isReachable(3,1)<<endl;
    cout<<"isReachable(0,3) = "<<g.isReachable(0,3)<<endl;
    cout<<"isReachable(3,2) = "<<g.isReachable(3,2)<<endl;
    cout<<"isReachable(1,2) = "<<g.isReachable(1,2)<<endl;

    return 0;
}