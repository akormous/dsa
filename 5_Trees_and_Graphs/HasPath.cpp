#include<bits/stdc++.h>
using namespace std;

/*

Return true if there is a path between a given source and a destination node

*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(n == 1 || start == end)
            return true;
        // creating an adjacency list from the given edges
        unordered_map<int, vector<int>> graph;
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // a boolean visited array to keep track of visited nodes
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        
        // do a breadth first search
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if(cur == end)
                return true;
            
            for(auto neighbor : graph[cur]) {
                if(!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return false;
    }
};