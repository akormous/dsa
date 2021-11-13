#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int l, maxLen = 0;
    
    void extendPalindrome(string s, int i, int k) {
        while(i >= 0 && k < s.length() && s[i] == s[k]) {
            i--;
            k++;
        }
        
        if(maxLen < (k-i-1)) {
            maxLen = k-i-1;
            l = i+1;
        }
    }
    
    string longestPalindrome(string s) {
        if(s.length() < 2)
            return s;
        
        for(int i = 0; i < s.length()-1; ++i) {
            // assuming the palindrome is of odd length
            extendPalindrome(s, i, i);
            // assuming the palindrome is of even length
            extendPalindrome(s, i, i+1);
        }
        
        return s.substr(l, maxLen);
    }
};