#include<bits/stdc++.h>
using namespace std;

/*
Given a set of inequalities, return true if it is a set of valid inequalities
For ex.

a < b, b < c, c < a  = false
a < b, b < c, a < c = true

*/

void dfs(string src, unordered_map<string,vector<string>>& graph, unordered_set<string>& visited, bool& result) {
    // go to each neighbor of src
    for(auto& neighbor : graph[src]) {
        if(visited.find(neighbor) != visited.end()) {
            result = false;
            return;
        }
        visited.insert(neighbor);
        dfs(neighbor, graph, visited, result);
        visited.erase(neighbor);
    }
}
bool AreValidInequations(vector<vector<string>>& inequations) {
    unordered_map<string, vector<string>> graph;
    for(auto& e : inequations) {
        string src = e[0];
        string op = e[1];
        string dest = e[2];
        if(op == ">")
            graph[src].push_back(dest);
        else
            graph[dest].push_back(src);
    }

    unordered_set<string> visited;
    bool result = true; // assume there are no cycles
    for(auto& node : graph) {
        visited.insert(node.first);
        dfs(node.first, graph, visited, result);    // changes result to false if cycle is detected
        if(result == false)
            return false;
    }
    return true;
}

int main() {
    // solution
    vector<vector<string>> inequations = {{"a", "<", "b"}, {"b", "<", "c"}, {"a", "<", "c"},};

    if(AreValidInequations(inequations)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}