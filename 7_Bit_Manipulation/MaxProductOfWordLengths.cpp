#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getBitMask(string& w) {
        int result = 0;
        for(char& c : w)
            result = result | (1 << (c - 'a'));
        return result;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            // generate bit mask for this word
            string& w = words[i];
            masks[i] = getBitMask(w);
            
            // compare words before this to this word, by AND operation
            // if words[i] AND words[j] => then there are some common letters
            for(int j = 0; j < i; j++) {
                if((masks[i] & masks[j]) == 0) {
                    int prod = words[i].length() * words[j].length();
                    ans = max(ans, prod);
                }
            }
        }
        return ans;
    }
};