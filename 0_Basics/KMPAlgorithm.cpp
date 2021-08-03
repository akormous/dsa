#include<bits/stdc++.h>
using namespace std;
/*
KMP Algorithm is used for pattern searching in a string
KMP - Knuth-Morris-Pratt

Time complexity of KMP algorithm is O( n )

Prerequisites

LPS - Longest Proper Prefix which is also a Suffix

What is a proper prefix?
A prefix which is not the whole string. 
For example, in string "ABC"
Prefixes are "", "A", "AB", "ABC"
but proper prefixes are "", "A", "AB"

The suffixes in "ABC" are "", "C", "BC", "ABC"

Now making the lps array
For each sub-pattern pat[0 .. i] where i goes from 0 to m-1,
lps[i] stores length of the maximum matching proper prefix
which is also a suffix of the subpattern pat[0 .. i]

Example lps for various patterns
string s = "AAAA"
lps[] = [0, 1, 2, 3]

string s = "ABCDE"
lps[] = [0, 0, 0, 0, 0]

string s = "AABAACAABAA"
lps[] = [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
*/

// returns the lps array for the given pattern string
vector<int> computeLpsArray(string pat) {
    // length of the pattern
    int n = pat.length();

    // length of the previous prefix which is also suffix, initially 0
    int len = 0;

    // lps array, first element is always 0
    vector<int> lps(n);
    lps[0] = 0;

    // traverse the string from index 1 to n-1
    int i = 1;
    while(i < n) {
        // if a character matches, then the lps length is increased by 1
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        // else if a character does not match
        else {
            // if there was already a prefix suffix going in the previous iteration
            // then compare the current character with the previous character of the prefix suffix that we are checking basically
            // kind of a backtracking action going on here
            if(len != 0) {
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

// KMP search
void KMPSearch(string text, string pat) {
    int m = text.length();
    int n = pat.length();

    // compute the lps array for the pat
    vector<int> lps = computeLpsArray(pat);

    int i = 0, j = 0;
    while(i < m) {
        if(text[i] == pat[j]) {
            j++;
            i++;
        }
        if(j == n) {
            // pattern is found
            cout<<"Pattern found at index = "<<i - j<<endl;
            // refer the lps array for how many element to skip comparing
            j = lps[j - 1];
        }
        // if the characters mismatch
        else if(i < m && text[i] != pat[j]) {
            // if there were some matches, i.e. j != 0
            // refer the lps array for how many elements to skip comparing
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    // given string
    string text = "HAGSAAACAAAACBHFKJGAAACAAAACBHJFKGDJBNXMAAACAAAACBAJHKLBFHAAAAACAAAACBKJSDHERBAAACAAAACBNBM";
    // the pattern to be searched for
    string pat = "AAACAAAACB";

    // use the KMP algorithm to search for the pattern in the text
    KMPSearch(text, pat);

    return 0;
}