#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Find bridges in a graph
 * 
 */
class Solution {
public:
    /**
     * @brief find bridges 
     * 
     * @param n number of nodes in the graph
     * @param connections array of edges (u,v)
     * @return vector<vector<int>> array or bridges (u,v) where u to v is a bridge
     */
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // convert edges to adjacency list
        vector<vector<int>> graph(n, vector<int>());
        for(auto con : connections) {
            graph[con[0]].push_back(con[1]);
            graph[con[1]].push_back(con[0]);
        }
        
        setSize(n);
        vector<vector<int>> bridges;    // result to be returned
                            // primary key for ids
        
        for(int i = 0; i < n; i++) {
            if(!visited[i])
                dfs(graph, i, -1, bridges);
        }
        return bridges;
    }

    /**
     * @brief DFS on the graph and populates bridges array
     * 
     * @param graph adjacency list
     * @param cur current node
     * @param parent parent node
     * @param bridges 
     */
    void dfs(vector<vector<int>>& graph, int cur, int parent, vector<vector<int>>& bridges) {
        visited[cur] = true;    // mark the current nodes as visited
        id = id + 1;            // increase the primary key
        ids[cur] = id;          // assign id to current node
        low[cur] = id;          // set default low-link value (id of itself)
        
        // go to each neighbor of current
        for(auto neighbor : graph[cur]) {
            if(neighbor == parent)  continue;   // if the neighbor is parent, then skip
            if(!visited[neighbor]) {            // if neighbor is not visited
                dfs(graph, neighbor, cur, bridges); // recursively call dfs
                /* 
                CALLBACK
                check if neighbor has lesser low-link value
                */
                low[cur] = min(low[cur], low[neighbor]);
                /*
                (this is in the callback)
                if the id of current node is less than the low-link value,
                it means that the current node was visited before this neighbor
                and this neighbor couldn't minimize its low-link value 
                which means that this current node and its neighbor 
                belong to different strongly connected components,
                so it is a critical connection
                */
                if(ids[cur] < low[neighbor])
                    bridges.push_back({cur, neighbor});
            }
            else {
                /**
                 * if there is a cycle and we have already visited that neighbor
                 * then, minimize the low-link value of the current node to the id of that neighbor
                 */
                low[cur] = min(low[cur], ids[neighbor]);
            }
        }
    }
    // resize visited, low, ids
    void setSize(int n) {
        visited.resize(n ,false);
        low.resize(n, 0);
        ids.resize(n, 0);
        id = 0;
    }
private:
    vector<bool> visited;   // to keep track of visited nodes
    vector<int> low;        // stores low-link value for every node
    vector<int> ids;        // assign unique ids to nodes
    int id;     
};