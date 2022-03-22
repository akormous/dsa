#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        
        if(n == 0)
            return "";
        
        string s(n, 'a');
        
        
        k = k - n;
        
        int p = n-1;
        
        while(k > 0) {
            
            if(k >= 26) {
                s[p] = 'z';
                k = k + 1 - 26;
            }
            else {
                s[p] = ('a' + k);
                k = 0;
            }
            p--;
            
        }
        return s;
    }
};