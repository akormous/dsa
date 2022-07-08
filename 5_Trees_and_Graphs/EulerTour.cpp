#include<bits/stdc++.h>
using namespace std;

/*

Given a bunch of edges, 
can you print the Euler tour of the tree

*/

class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& graph, vector<int>& result, int cur, unordered_set<int>& visited) {
        if(visited.find(cur) != visited.end())
            return;

        visited.insert(cur);

        for(int& neighbor : graph[cur]) {
            if(visited.find(neighbor) == visited.end()) {
                result.push_back(cur);
                dfs(graph, result, neighbor, visited);
            }
        }
        result.push_back(cur);
    }
    /**
     * @brief Get the Euler Tour object
     * 
     * @param edges edges of the graph
     * @return vector<int> euler tour sequence
     */
    vector<int> getEulerTour(vector<vector<int>> edges) {
        // build the tree, i will store it in the form of adjacency list
        unordered_map<int,vector<int>> graph;

        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> result;
        unordered_set<int> visited;
        dfs(graph, result, 0, visited);
        return result;

    }

private:

};

int main() {
    vector<vector<int>> input = {{0, 1},
            {0, 2},
            {1, 3},
            {1, 4}};
    // solution
    Solution s;

    vector<int> result = s.getEulerTour(input);

    for(int n : result)
        cout << n << " ";
    cout << endl;

    return 0;
}