#include<bits/stdc++.h>
using namespace std;

/*
Print the BFS sequence of a given graph
*/

void printBFS(map<char, vector<char>> graph, char source) {
    queue<char> q;  // initialize a queue
    q.push(source); // push the source node to the queue

    while(!q.empty()) {
        char cur = q.front();
        cout<<cur<<" ";
        q.pop();

        for(auto i : graph[cur]) // push all the neighbors of the current node to the queue
            q.push(i);
    }
    return;
}

int main() {
    // solution

    map<char, vector<char>> graph;

    graph['a'] = { 'b', 'c' };
    graph['b'] = { 'd' };
    graph['c'] = { 'e' };
    graph['d'] = { 'f' };
    graph['e'] = {};
    graph['f'] = {};

    printBFS(graph, 'a');   // print DFS of the graph starting from source node 'a'

    return 0;
}