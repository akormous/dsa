#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int n = t.length();
        int m = s.length();
        
        if(n == 0 && m == 0)
            return true;
        
        if(n == 0)
            return false;
        
        while(i < n && j < m) {
            while(i < n && s[j] != t[i]) {
                i++;
            }
            if(i == n && j < m)
                return false;
        
            i++;
            j++;
        }
        
        if(j == m)
            return true;
        
        return false;
        
    }
};