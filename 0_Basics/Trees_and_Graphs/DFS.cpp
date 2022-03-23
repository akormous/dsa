// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*

Question:
Given a connected undirected graph.
Perform a Depth First Traversal of the graph.

*/

 // } Driver Code Ends
class Solution {
  public:
    // DFS utility function
    void dfsUtil(vector<int> g[], bool visited[], vector<int>& result, int cur) {
        // visit the current node
        visited[cur] = true;

        // add this node to result
        result.push_back(cur);

        // traverse the adjacency list of current node
        for(auto i : g[cur]) {
            // if any node is not visited, call dfs on that node
            if(!visited[i]) {
                dfsUtil(g, visited, result, i);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // given an array of vectors, and number of vertices in a graph
        // perform DFS
        // result vector
        vector<int> result;
        // a boolean array to keep track of visited nodes
        bool visited[V];
        memset(visited, 0, sizeof(visited));

        dfsUtil(adj, visited, result, 0);

        return result;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends