#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        // frequency maps for a window and t
        unordered_map<char,int> window;
        unordered_map<char,int> countT;
        
        // calculate the frequencies of chars in t
        for(char& c : t)
            countT[c]++;
        
        int need = countT.size(); // number of characters that need to be satisfied
        int have = 0;   // number of chars that we initially have
        
        int resultIdx = -1;
        int resultLen = INT_MAX;
        
        int l = 0, r = 0;
        for(r = 0; r < n; r++) {
            char c = s[r];
            window[c]++;
            if(window[c] == countT[c])
                    have++;
            
            while(have == need) {
                // update the result
                if(r - l + 1 < resultLen) {
                    resultLen = r - l + 1;
                    resultIdx = l;
                }
                // pop from the left and update window freq and have variable
                window[s[l]]--;
                if(countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                        have--;
                }
                l++;
            }
        }
        return resultIdx == -1 ? "" : s.substr(resultIdx, resultLen);
    }
};