#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> computeLPS(string pat) {
        int n = pat.length();
        vector<int> lps(n);
        // length of prefix suffix
        int len = 0;
        // first index of lps is 0
        lps[0] = 0;

        // traverse the string and compare the characters in assumed prefix suffix and pattern
        int i = 1;
        while(i < n) {
            // if the character matches
            if( pat[i] == pat[len] ) {
                len++;
                lps[i] = len;
                i++;
            }
            // if there is a mismatch
            else {
                // if there was some prefix suffix going on just before this
                if(len != 0) {
                    // then continue comparing the previous characters
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int kmpSearch(string text, string pat) {
        int m = text.length();
        int n = pat.length();

        // computing the lps for the pattern
        vector<int> lps = computeLPS(pat);

        int i =0;
        int j = 0;
        // now start searching for the pattern
        while(i < m) {
            if(text[i] == pat[j]) {
                i++;
                j++;
            }
            // if pattern was found then return the index
            if(j == n)
                return (i - j);
            // else if there was some mismatch
            else if(i < m && text[i] != pat[j]) {
                // if there was some matching before
                if(j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        // the question is to find a pattern in a given text
        // approach is to use KMP algorithm
        // here needle is the pattern to be searched for
        // haystack is the text in which search will occur
        // KMP algorithm uses a LPS array (longest proper prefix which is also a suffix)
        
        // if the length of the needle is 0
        if(needle.length() == 0)
            return 0;
        
        // search for the needle in the haystack
        return kmpSearch(haystack, needle);
        
    }
};