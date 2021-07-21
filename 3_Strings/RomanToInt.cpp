#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // creating an unordered_map of roman values
        unordered_map<char, int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        // size of string
        int n = s.length();
        if(n == 1)
            return umap[s[0]];
        
        // starting from least significant digit in roman
        int result = umap[s[n-1]];
        for(int i = n-2; i >= 0; i--)
        {
            if(umap[s[i]] < umap[s[i+1]])
                result -= umap[s[i]];
            else
                result += umap[s[i]];
        }
        return result;
    }
};