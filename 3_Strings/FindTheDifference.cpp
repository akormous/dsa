#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);

        for(auto c : t) {
            freq[c - 'a']++;
        }

        for(auto c : s) {
            freq[c - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] == 1)
                return ('a' + i);
        }
        return 0;
    }
};