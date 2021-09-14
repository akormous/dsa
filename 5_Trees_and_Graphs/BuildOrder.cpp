#include<bits/stdc++.h>
using namespace std;


/*

Question: Given a bunch of projects and their dependencies, obtain a build order

projects[] = {a,b,c,d,e,f}
dependencies = {(a,d),(f,d),(b,d),(d,e)} etc.

second project in the pair is dependent on the first project

Find the order of building these projects

Approach: Easy topological sort question
*/

vector<string> buildOrder(vector<string> projects, vector<pair<string,string>> dependency) {
    // this will store the final build order
    vector<string> result;

    // currently processing project
    queue<string> inProcess;

    // calculate the number of dependencies for each project
    unordered_map<string,int> numDep;

    for(int i = 0; i < dependency.size(); ++i)
        numDep[ dependency[i].second ] ++;
    
    // find the project which has 0 dependencies and start with that
    for(auto i : projects) {
        if(numDep[i] == 0)
            inProcess.push(i);
    }
    while(!inProcess.empty()) {
        string cur = inProcess.front();
        inProcess.pop();

        // remove 1 from the number of dependency for the project who are dependent on the current one
        for(auto i : dependency) {
            if(i.first == cur) {
                numDep[i.second]--;
                if(numDep[i.second] == 0)
                    inProcess.push(i.second);
            }
        }

        // push the cur project to the result
        result.push_back(cur);
    }
    return result;
}

int main() {
    // solution
    vector<string> projects = {"a","b","c","d","e","f"};

    vector<pair<string,string>> dependencies;
    dependencies.push_back(make_pair("a","d"));
    dependencies.push_back(make_pair("f","b"));
    dependencies.push_back(make_pair("b","d"));
    dependencies.push_back(make_pair("f","a"));
    dependencies.push_back(make_pair("d","c"));
    

    vector<string> result = buildOrder(projects, dependencies);

    for(auto i : result)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}