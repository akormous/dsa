#include<bits/stdc++.h>
using namespace std;
/*
Consider a 2D plane with some arbitrary points. 
Given some relations between different points. Return true if all the statements given are valid otherwise return false.

The input statements contains three attributes, which includes the two points and the relation between those points in terms of direction.
The directions can be one of [N, S, E, W, NE, NW, SE, SW]

For instance, the statement "P1 N P2" represent point P2 is to the North of point P1.

Input
P1 N P2
P2 N P3
P3 S P1

Output
true

Input
P1 N P2
P2 N P3
P1 S P3

Output
false

*/

/*
Solution:
Given a statement
P1 N P2 , we can create a directed edge from P1 to P2
but consider this statement
P2 S P1 , isn't this the same as P1 N P2 ? 
So we can represent South direction by creating a directed edge in the opposite direction
Similary for East and West directions.

Now, we can create 2 graphs,
1. one for North-South directions
2. other one for East-West directions

Then we look for cycles in these graphs, if there is a cycle, then the given statements are not valid
*/

vector<string> getEntities(string& relation, string del = " ") {
    vector<string> result;
    string tmp = "";
    int i = 0;
    while(relation[i] != ' ')
        tmp += relation[i++];
    result.push_back(tmp);
    tmp = "";
    i++;
    while(relation[i] != ' ')
        tmp += relation[i++];
    result.push_back(tmp);
    tmp = "";
    i++;
    while(i < relation.size())
        tmp += relation[i++];
    result.push_back(tmp);
    return result;
}

bool dfs(string root, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited) {
    if(visited.find(root) != visited.end()) return false;

    // visit the node
    visited.insert(root);
    for(string& ngh : graph[root]) {
        if(!dfs(ngh, graph, visited))
            return false;
    }
    visited.erase(root);
    return true;
}

bool isCyclePresent(unordered_map<string, vector<string>>& graph) {
    // using DFS to detect cycles
    unordered_set<string> visited;
    unordered_set<string> cache;
    for(auto& p : graph) {
        string node = p.first;
        if(cache.find(node) != cache.end() || !dfs(node, graph, visited))
            return true;
        else
            cache.insert(node);
    }
    return false;
}

void printGraph(unordered_map<string, vector<string>>& g) {
    cout << "\n---------------------------------------------\n";
    for(auto& p : g) {
        cout << p.first << " -> ";
        for(auto& ngh : p.second)
            cout << ngh << ", ";
        cout << endl;
    }
    cout << "\n---------------------------------------------\n";
}

bool areRelationsValid(vector<string>& relations) {
    unordered_map<string, vector<string>> graphNS;
    unordered_map<string, vector<string>> graphEW;

    for(string& r : relations) {
        auto entities = getEntities(r);
        string src = entities[0];
        string dest = entities[2];
        string dir = entities[1];
        if(dir[0] == 'E') {
            graphEW[src].push_back(dest);
        }
        else if(dir[0] == 'W') {
            graphEW[dest].push_back(src);
        }
        else if(dir[0] == 'N') {
            graphNS[src].push_back(dest);
            if(dir.length() > 1) {
                if(dir[1] == 'E') {
                    graphEW[src].push_back(dest);
                }
                else if(dir[1] == 'W') {
                    graphEW[dest].push_back(src);
                }       
            }
        }
        else if(dir[0] == 'S') {
            graphNS[dest].push_back(src);
            if(dir.length() > 1) {
                if(dir[1] == 'E') {
                    graphEW[src].push_back(dest);
                }
                else if(dir[1] == 'W') {
                    graphEW[dest].push_back(src);
                }       
            }
        }
    }
    //printGraph(graphNS);
    //printGraph(graphEW);
    return !isCyclePresent(graphNS) && !isCyclePresent(graphEW);
}

int main() {
    // solution
    vector<string> input1 = {
        "P1 N P2",
        "P2 S P3",
        "P1 E P3",
        "P3 NW P4",
        "P5 SW P4",
        "P1 W P5",
    };

    vector<string> input2 = {
        "P1 N P2",
        "P2 S P3",
        "P1 E P3",
        "P3 NW P4",
        "P5 SW P4",
        "P1 W P5",
        "P1 NW P3"
    };

    vector<string> input3 = {
        "P1 N P2",
        "P2 N P3",
        "P1 S P3",
    };

    vector<string> input4 = {
        "P1 N P2",
        "P2 N P3",
        "P3 S P1",
    };
    
    cout << ( areRelationsValid(input1) ? "TRUE" : "FALSE" ) << endl;
    cout << ( areRelationsValid(input2) ? "TRUE" : "FALSE" ) << endl;
    cout << ( areRelationsValid(input3) ? "TRUE" : "FALSE" ) << endl;
    cout << ( areRelationsValid(input4) ? "TRUE" : "FALSE" ) << endl;

    return 0;
}