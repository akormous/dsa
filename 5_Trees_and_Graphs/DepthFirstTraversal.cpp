#include<bits/stdc++.h>
using namespace std;

/*

Given an adjacency list, perform a Depth First Traversal

*/

void printDFS(map<char, vector<char>> graph, char source) {
    int n = graph.size();   // number of nodes in the graph
    
    stack<char> st;
    st.push(source);  // push the source node to the stack

    while( !st.empty() ) {
        char cur = st.top();    // topmost node on the stack
        st.pop();   // pop it
        cout<<cur<<" ";
        
        // push all the neighbors of the cur node to the stack
        for(auto i : graph[cur])
            st.push(i);
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

    printDFS(graph, 'a');   // print DFS of the graph starting from source node 'a'

    return 0;
}