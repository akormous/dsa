#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        
        // split path by delimiter '/'
        vector<string> token;
        string tmp;
        stringstream ss(path);
        while( getline(ss, tmp, '/' ) ) {
            
            if(tmp == "" || tmp == ".") {
                continue;
            }
            
            else if(tmp == "..") {
                if(!token.empty())
                    token.pop_back();
            }
            else {
                token.push_back(tmp);
            }
        }
        
        for(auto d : token) {
            
            result += "/" + d;
            
        }
        
        return result == ""? "/" : result;
        
    }
};