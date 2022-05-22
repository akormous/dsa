#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void extendPalindrome(string s, int l, int r, int& count) {
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        if(s.length() == 0) return 0;
        
        int count = 0;
        
        for(int i = 0; i < s.length(); ++i) {   // imagine i being the midpoint
            // assumption 1: palindrome is of odd length
            extendPalindrome(s, i, i, count);
            // assumption 2: palindrome is of even length
            extendPalindrome(s, i, i+1, count);
            
        }
        return count;
    }
};