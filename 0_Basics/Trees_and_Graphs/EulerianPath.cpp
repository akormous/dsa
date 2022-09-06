#include<bits/stdc++.h>
using namespace std;

/*
Finding an Eulerian path - Leetcode 332

*/
class Solution {
private:
    unordered_map<string,vector<string>> graph;
    unordered_map<string,int> inDegree, outDegree;
    unordered_set<string> visited;
    vector<string> path;
public:
    /**
     * @brief finds and stores eulerian path
     * 
     * @param at nodes where we are currently at
     */
    void dfs(string at) {
        while(outDegree[at] != 0) {
            vector<string>::iterator ngh = graph[at].begin();
            string airport = *ngh;
            graph[at].erase(ngh);
            outDegree[at]--;
            dfs(airport);
            
        }
        path.push_back(at);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto& t : tickets) {
            graph[t[0]].push_back(t[1]);
            inDegree[t[1]]++;
            outDegree[t[0]]++;
        }
        for(auto& p : graph)
            sort(p.second.begin(), p.second.end());

        /* starting node is also mentioned in the problem, JFK
        */
        dfs("JFK");
        reverse(path.begin(), path.end());
        return path;
    }
};