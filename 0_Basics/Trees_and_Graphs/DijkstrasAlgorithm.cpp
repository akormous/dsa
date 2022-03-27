#include<bits/stdc++.h>
using namespace std;
/*

Dijkstra's Algorithm
Question: LC743

Dijkstra's Algorithm returns an array of shortest distance to all nodes (dist)
from a starting node s



*/
typedef pair<int,int> pd;


struct compareDist {
    constexpr bool operator()(pair<int,int> const& a, pair<int,int> const& b) const noexcept {
        return a.second > b.second;
    }
};

class Solution {
public:
    

    string getKey(int src, int dest) {
        return (to_string(src) + "," + to_string(dest));
    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create adjacency list and edge to weight map
        vector<vector<int>> graph(n+1);
        unordered_map<string, int> weights;

        for(auto t : times) {
            int src = t[0];
            int dest = t[1];
            int wt = t[2];
            // insert in graph
            graph[src].push_back(dest);

            // map edge to weight
            string key = getKey(src, dest);
            weights[key] = wt;
        }

        // create the dist array, initialize all distance to infinite (sentinel value)
        vector<int> dist(n+1, INT_MAX);
        // distance to starting node is 0
        dist[k] = 0;
        
        // keep track of visited nodes
        vector<bool> visited(n+1, false);

        // a priority queue storing the neighbors 
        // and at the front will the next most promising node,
        // which basically means the node having least distance to reach
        priority_queue<pd, vector<pd>, compareDist> q;

        // insert the starting node
        q.push({k, dist[k]});

        while(!q.empty()) {

            pair<int,int> curNode = q.top();
            q.pop();

            // visit curNode
            visited[curNode.first] = true;

            // skip stale pairs, 
            // skip nodes for which we already have found a better path
            // routing through other nodes before we got to process this node
            if(dist[curNode.first] < curNode.second) continue;

            // for all the neighbors of cur node
            for(auto neighbor : graph[curNode.first]) {
                // if neighbor is alreadt visited
                if(visited[neighbor] == true)  continue;

                string key = getKey(curNode.first, neighbor);
                // new distance
                int newDist = dist[curNode.first] + weights[key];

                if(newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    q.push({neighbor, newDist});
                }
            }
        }

        int maxTime = *max_element(begin(dist) + 1, end(dist));

        return (maxTime == INT_MAX ? -1 : maxTime);

    }
};