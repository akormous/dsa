#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinLength(vector<string> strs) {
        int minLength = INT_MAX;
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            if(strs[i].length() < minLength )
                minLength = strs[i].length();
        }
        return minLength;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        // get the length of smallest string in the array
        int minLength = findMinLength(strs);
        
        int n = strs.size();
        // check till minLength only
        for(int i = 0; i < minLength; i++) {
            
            char c = strs[0][i];
            // now check if this char matches in all of the strings
            for(int j = 0; j < n; j++) {
                if(c != strs[j][i])
                    return ans;
            }
            ans += c;
        }
        return ans;
    }
};