#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> to_routes;  // maps bus stop to route number
        for(int i = 0; i < routes.size(); i++) {
            for(int j : routes[i])
                to_routes[j].push_back(i);
        }
        
        unordered_set<int> visited; // keeps track of visited bus stops
        queue<pair<int,int>> q;   // stores bus stop and number of buses taken to reach this bus stop
        q.push({source, 0});
        visited.insert(source);
        
        while(!q.empty()) {
            int stop = q.front().first;
            int busCount = q.front().second;
            q.pop();
            
            if(stop == target)  // if current stop is target, then return bus count
                return busCount;
            
            // checkout each route from current bus stop
            for(int r : to_routes[stop]) {
                // check each bus stop in the route
                for(int i : routes[r]) {
                    if(visited.find(i) == visited.end())  { // this bus stop is not visited yet
                        visited.insert(i);
                        q.push({i, busCount + 1});
                    }
                }
                routes[r].clear();  // clear the route as we have considered all bus stops in this route
            }
        }
        return -1;
    }
};