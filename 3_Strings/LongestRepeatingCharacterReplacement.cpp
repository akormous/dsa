#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int WindowSize(int start, int end) {
        return (end - start + 1);
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        int start = 0;  // start of the window
        vector<int> freq(26, 0);    // frequency array
        int maxCount = 0;   // highest frequency in any window
        int maxLength = 0;  // result to be returned
        
        for(int end = 0; end < n; end++) {
            char c = s[end];
            freq[c - 'A']++;
            maxCount = max(maxCount, freq[c - 'A']);
            if(WindowSize(start, end) - maxCount > k) { 
                // means there are characters which we cannot replace
                // to make a repeating character string
                // so shrink the window size
                freq[s[start] - 'A']--; // decrease the frequency of start character of window
                start++;    // move start
            }
            
            maxLength = max(maxLength, WindowSize(start, end)); // check max length of repeating characters
        }
        return maxLength;
    }
};