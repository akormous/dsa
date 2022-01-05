#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;  // contains the result
    
    bool isPalindrome(string s, int l, int r) {
        while(l <= r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    
    void partitionMaster(string s, int pos, vector<string>& path) {
        if(pos == s.size()) {
            result.push_back(path);
            return;
        }
        
        for(int i = pos; i < s.size(); ++i) {
            if(isPalindrome(s, pos, i)) {
                path.push_back(s.substr(pos, i - pos + 1));
            
                partitionMaster(s, i+1, path);
                // backtrack
                path.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> path;
        
        partitionMaster(s, 0, path);
        return result;
    }
};