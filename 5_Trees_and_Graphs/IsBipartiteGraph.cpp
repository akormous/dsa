#include<bits/stdc++.h>
using namespace std;

/*
BFS solution
*/
class Solution {
public:
    /*
    this function checks if a graph can be colored using 2 colors, and no adjacent 2 nodes are of the same color, using BFS
    */
    bool bfsUtil(vector<vector<int>>& graph, vector<int>& colors, int src) {
        queue<int> q;
        q.push(src);
        colors[src] = 1;    // assign a color to the src
        
        while(!q.empty()) {
            int curNode = q.front();
            q.pop();
            int curColor = colors[curNode];
            int nextColor = (curColor == 0 ? 1 : 0);
            
            for(auto& neighbor : graph[curNode]) {
                if( colors[neighbor] == curColor )
                    return false;
                if( colors[neighbor] == -1) {
                    colors[neighbor] = nextColor;
                    q.push(neighbor);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();   // number of nodes
        /*
        colors[] -> color of a node i,
        -1 = colorless
        0 = red
        1 = blue
        */
        vector<int> colors(n, -1);
        
        for(int i = 0; i < n; ++i) {
            if(colors[i] == -1 && !bfsUtil(graph, colors, i))
                return false;
        }
        return true;
    }
};

/*
DFS solution
*/
class Solution {
public:
    bool dfsUtil(vector<vector<int>>& graph, vector<int>& colors, int src, int curColor) {
        colors[src] = curColor;
        int nextColor = (curColor == 0 ? 1 : 0);
        for(auto& ngh : graph[src]) {
            if( colors[ngh] == nextColor )  continue;
            if( colors[ngh] == curColor || !dfsUtil(graph, colors, ngh, nextColor))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1 && !dfsUtil(graph, colors, i, 1))
                return false;
        }
        return true;
    }
};