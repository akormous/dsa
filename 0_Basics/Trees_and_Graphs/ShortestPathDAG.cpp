#include<bits/stdc++.h>
using namespace std;

/*

SINGLE SOURCE SHORTEST PATH (SSSP)

Find the shortest path from a given source node to every other node in the Directed Acyclic graph.
Using Topological Sort

NOTE: Only valid for DAGs

Algorithm:

Step 1. Find the Topological Ordering of the graph
Step 2. Assign infinite distance value to the distance array (topological sorted)
Step 3. Start from the src, and try to relax each edge
        distance[neighbor] = min( distance[neighbor], distance[cur] + weight[edge] )
*/

// LC743
class Solution {
public:
    int dfs(int cur, int pos, vector<int>& order, vector<bool>& visited, vector<vector<int>>& graph) {
        visited[cur] = true;

        for(auto neighbor : graph[cur])
            if( !visited[neighbor] )
                pos = dfs(neighbor, pos, order, visited, graph);
        
        order[pos] = cur;
        return (pos-1);
    }
    vector<int> topoSort(int n, vector<vector<int>> graph) {
        vector<int> order(n);
        vector<bool> visited(n, 0);
        int pos = n-1;

        for(int cur = 0; cur < n; cur++) {
            if(!visited[cur])
                pos = dfs(cur, pos, order, visited, graph);
        }
        return order;
    }

    vector<int> SSSPDAG(vector<vector<int>>& edges, int n, int start) {
        
        // create an adjacency list
        vector<vector<int>> adj(n, vector<int>());
        // create a map from edge to weight of the edge
        unordered_map<string,int> weight;

        for(auto edge : edges) {
            int src = edge[0];
            int dest = edge[1];
            int wt = edge[2];

            adj[src].push_back(dest);
            string key = to_string(src) + "," +to_string(dest);
            weight[key] = wt;       
        }
        
        // get topological sorted order of the nodes
        vector<int> order = topoSort(n, adj);
        // assign infinite distance to each node
        vector<int> distance(n, INT_MAX);

        distance[start] = 0;
 
        // start from 1st node
        for(int i = 0; i < n; i++) {
            
            int cur = order[i];
            
            if(distance[cur] == INT_MAX) continue;
            
            for(auto neighbor : adj[cur]) {
                
                int src = cur;
                int dest = neighbor;
                string key = to_string(src) + "," + to_string(dest);
     
                distance[dest] = min( distance[dest], distance[src] + weight[key] );   
            }
        }
        
        return distance;
    }
};


int main() {
    Solution s;
    vector<vector<int>> edges = {
        {0,1,3},
        {0,2,6},
        {1,2,4},
        {1,4,11},
        {1,3,4},
        {2,3,8},
        {2,6,11},
        {3,4,-4},
        {3,5,5},
        {3,6,2},
        {4,7,9},
        {5,7,1},
        {6,7,2},
    };
    int n = 8;
    int start = 0;
    vector<int> distance = s.SSSPDAG(edges, n, start);

    for(auto d : distance)
        cout<<d<<" ";
    return 0;
}