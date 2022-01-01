#include<bits/stdc++.h>
using namespace std;

/*

Given a graph in the form of adjacency list,
find the number of nodes in the largest component of that graph

adjacency list = map<char,vector<char>>

*/

// return the number of nodes in a component using DFS traversal
int dfsUtil(map<char,vector<char>> graph, char cur, unordered_set<char>& visited) {
    if(visited.find(cur) != visited.end())
        return 0;
    
    int size = 1;
    
    visited.insert(cur);
    for(auto i : graph[cur]) {    
        size += dfsUtil(graph, i, visited);
    }

    return size;
}

int largestComponent(map<char,vector<char>> graph) {
    int n = graph.size();   // number of nodes in the graph
    unordered_set<char> visited;    // keeping track of visited nodes
    
    int result = INT_MIN;    // result = number of nodes in the largest component
    int curCount = 0;      // number of nodes in the current component
    
    // reach every component in the graph
    map<char,vector<char>>::iterator it;

    for(it = graph.begin(); it != graph.end(); it++) {
        curCount = dfsUtil(graph, it->first, visited);
        result = max(result, curCount);
    }
    return result;
}
int main() {
    // solution
    // graph
    map<char,vector<char>> graph;
    graph['0'] = {'8', '1', '5', 'a'};
    graph['1'] = {'0'};
    graph['5'] = {'0', '8'};
    graph['8'] = {'0', '5'};
    graph['2'] = {'3', '4'};
    graph['3'] = {'2', '4'};
    graph['4'] = {'3', '2'};

    cout << largestComponent(graph) <<endl;
    return 0;
}