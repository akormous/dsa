#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    double dfs(string src, string dest, unordered_set<string>& visited, unordered_map<string, unordered_map<string,double>>& graph) {
        // if destination is found in the map, return the weight
        if( graph[src].find(dest) != graph[src].end() )
            return graph[src][dest];
        
        // go to neighbors of src
        for(auto& neighbor : graph[src]) {
            // neighbor.first -> node name (string)
            // neihgbor.second -> weight for src, neighbor[0]
            if( visited.find(neighbor.first) == visited.end() ) { // if neighbor is not visited
                visited.insert(neighbor.first);    // visit the neighbor
                double result = dfs(neighbor.first, dest, visited, graph);
                if(result)  // if dest was found
                    return neighbor.second * result;    // return product of current wt and result
            }
        }
        return 0;   // if dest is not found
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // building a graph
        unordered_map<string, unordered_map<string,double>> graph;
        for(int i = 0; i < values.size(); ++i) {
            string src = equations[i][0];
            string dest = equations[i][1];
            double wt = values[i];
            
            graph[src].insert({dest, wt});
            
            if(wt != 0)
                graph[dest].insert({src, 1/wt});
        }
        // graph built
        
        vector<double> result;
        // now time to solve the queries
        for(auto q : queries) {
            unordered_set<string> visited; // empty visited array, to keep track of visited nodes in dfs
            double ans = dfs(q[0], q[1], visited, graph);
            if(ans) // if dest was found
                result.push_back(ans);
            else    // else push -1
                result.push_back(-1);
        }
        return result;
    }
};