#include<bits/stdc++.h>
using namespace std;

/*

Find the shortest path from a source node to destination node
Unweighted undirected graph.

Simply do BFS

*/

int shortestPath(map<char,vector<char>> graph, char src, char dest) {
    queue<pair<char,int>> q;  // stores a node and distance from the src node
    q.push({src, 0});

    unordered_set<char> visited;    // keep track of visited nodes

    while(!q.empty()) {
        char curNode = q.front().first;
        int dist = q.front().second;
        visited.insert(curNode);
        
        q.pop();

        // push the neighbors of the curNode
        for(auto i : graph[curNode]) {
            if(visited.find(i) == visited.end()) {
                q.push({i, dist + 1});

                // check if destination node is reached
                if(i == dest)
                    return (dist + 1);
            }
        }
    }
    return -1;
}

void buildGraph(map<char,vector<char>>& graph, vector<pair<char,char>> edges) {
    vector<pair<char,char>>::iterator it;

    for(it = edges.begin(); it != edges.end(); ++it) {
        graph[it->first].push_back(it->second);
        graph[it->second].push_back(it->first);
    }
}

int main() {
    // solution
    vector<pair<char,char>> edges = {
        {'w','x'},
        {'x','y'},
        {'z','y'},
        {'z','v'},
        {'w','v'}
    };

    // convert edges to adjacency list
    map<char,vector<char>> graph;
    buildGraph(graph, edges);
    
    cout<<shortestPath(graph, 'w', 'x')<<endl;
    return 0;
}