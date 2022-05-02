#include<bits/stdc++.h>
using namespace std;

/*
Bellman-Ford Algorithm
Question: LC743

Bellman-Ford algorithm returns an array of shortest distance to all nodes (dist)
from a starting node s. It also works for negative edge weights.

TC: O(EV)

which is not ideal as Dijkstra's has a TC of O((E+V) log(V))

When to use this?
When graph has negative edge weights.

Dijkstra's algorithm fails for negative cycles.
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        // the nodes are numbered from 1 to n
        vector<int> dist(n+1, INT_MAX);
        // distance of starting node
        dist[k] = 0;

        for(int i = 0; i < n; ++i) {
            for(auto& edge : edges) {
                int src = edge[0];
                int dest = edge[1];
                int wt = edge[2];

                // if cur_distance + wt of edge < dist[dest]
                if(dist[src] != INT_MAX && dist[src] + wt < dist[dest])
                    dist[dest] = dist[src] + wt;
            }
        }
        // in the question we have to return the maximum distance from node k to any other node in the graph
        int maxWait = 0;
        for(int i = 1; i <= n; i++) {
            maxWait = max(maxWait, dist[i]);
        }
        // if any node is unreachable, then return -1
        return (maxWait == INT_MAX ? -1 : maxWait);
    }
};

/*

Another example of Bellman-Ford
LC787

*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;
        
        // run only k times
        for(int i = 0; i <= k; i++) {
            vector<int> tmp(cost);
            for(auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];
                
                if(cost[from] != INT_MAX && cost[from] + price < tmp[to])
                    tmp[to] = cost[from] + price;
            }
            cost = tmp;
        }
        
        return ( cost[dst] == INT_MAX ? -1 : cost[dst] );
    }
};