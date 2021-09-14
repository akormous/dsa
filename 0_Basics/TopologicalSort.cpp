// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/*

Theory:
1. Only valid for Directed Acyclic Graphs (DAG)

Algorithm:

1. Count the number of inbound links to every node
2. Start from the node which has 0 inbound links
3. Process this node, means, decrease the inbound links of all nodes connected to this one
4. Find the next node which has 0 inbound links, repeat the process
*/

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        // this will store the final topological sort order
	    vector<int> result;

        // the next node which is to be processed
        queue<int> processNext;

        // count the number of inbound edges to every vertex
        int inboundCount[V];
        memset(inboundCount, 0, sizeof(inboundCount));

        for(int i = 0; i < V; i++) {
            for(auto j : adj[i]) {
                inboundCount[j]++ ;
            }
        }

        // push the nodes to the queue whose inboundCount is 0
        for(int i = 0; i < V; i++) {
            if(inboundCount[i] == 0)
                processNext.push(i);
        }

        while(!processNext.empty()) {
            int cur = processNext.front();
            processNext.pop();

            for(auto i : adj[cur]) {
                inboundCount[i]--;
                if(inboundCount[i] == 0)
                    processNext.push(i);
            }
            result.push_back(cur);
        }
        return result;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends