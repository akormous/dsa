#include<bits/stdc++.h>
using namespace std;

void dfsUtility(map<char,vector<char>> graph, char src, bool visited[]) {
    if(visited[src - 'a'])    return;

    visited[src - 'a'] = true;

    for(auto neighbor : graph[src]) {
        dfsUtility(graph, neighbor, visited);
    }
}

int countConnectedComponents(map<char,vector<char>> graph) {
    int count = 0;
    // number of nodes in the graph
    int n = graph.size();
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    // iterate over each node in the graph and do a BFS or DFS and mark visited nodes
    map<char,vector<char>>::iterator it;
    for(it = graph.begin(); it != graph.end(); ++it) {
        char node = it->first;

        if(!visited[node - 'a']) {
            count++;
            dfsUtility(graph, node, visited);
        }
    }

    return count;
}

int main() {
    // solution
    
    map<char,vector<char>> graph;
    
    graph['a'] = { 'b', 'c' };
    graph['b'] = { 'd' };
    graph['c'] = { };
    graph['d'] = { };
    graph['e'] = {};
    graph['f'] = {};

    cout<<"Answer = "<<countConnectedComponents(graph);
    return 0;
}