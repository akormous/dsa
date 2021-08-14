#include<bits/stdc++.h>
using namespace std;

/*

Question: Replace all whitespaces in a string with %20
          Assume the size of the string is such that it could accomodate the final resultant string
          Also, you are given true length of the string
          Basically, do it in place

Input string:
"i am iron man      "
True length = 13

"i%20am%20iron%20man"

*/

/*
A two pointer approach

First pointer will be at the writing position at the end of the string
Second pointer will be at the reading position at the end of true length

Assign character from the end
When a white space is encountered, fill in the required delimiter
Move the First pointer and Second pointer to the left by 1 pos
*/
string urlify(string s, int trueLength, string filler) {
    int r = trueLength - 1;
    int w = s.length() - 1;

    while(r >= 0 && w >= 0) {
        if(s[r] == ' ') {
            for(int i = filler.length() - 1; i >= 0; i--)
                s[w--] = filler[i];
            r--;
        }

        s[w--] = s[r--];
    }
    return s;
}


int main() {
    // solution
    string s = "I am Iron Man      ";
    cout<<s<<endl;
    cout<<urlify(s, 13, "%20")<<endl;
    return 0;
}