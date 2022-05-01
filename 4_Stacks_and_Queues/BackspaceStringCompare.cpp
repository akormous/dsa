#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    returns the next legit character; which is not backspaced
    */
    char getNextLegitCharacter(const string& s, int& i) {
        int count = 0;
        while(i >= 0 && ( count > 0 || s[i] == '#' )) {
            if(s[i] == '#')
                count++;
            else
                count--;
            i--;
        }
        return (i >= 0 ? s[i] : '#');
    }
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        while(i >= 0 || j >= 0) {
            char S = getNextLegitCharacter(s, i);
            char T = getNextLegitCharacter(t, j);
            if(S != T)
                return false;
            else {
                i--;
                j--;
            }
        }
        return true;
    }
};