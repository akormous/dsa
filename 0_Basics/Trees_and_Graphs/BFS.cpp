// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

/*

Breadth First Search
visit all the neighbouring nodes before going deep

*/

class Solution {
  public:
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // result vector
        vector<int> result;

        // a boolean visited array
        bool visited[V];
        memset(visited, 0, sizeof(visited));

        // queue
        queue<int> q;

        // insert the root node, assuming to be zeroth node
        q.push(0);
        // visit the root node
        visited[0] = true;

        while(!q.empty()) {
            // pop the front element and add it to the result
            int cur = q.front();
            q.pop();

            result.push_back(cur);
            
            // insert all neighbouring nodes of cur, (if they are not visited yet)
            for(auto i : adj[cur]) {
                if(!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends