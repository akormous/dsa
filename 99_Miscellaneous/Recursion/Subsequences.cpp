/*
Given a string of length n
print all subsequences of the string
for ex. given string = abc
then subsequences are
a, b, c, ab, ac, bc, abc, null
*/
#include<bits/stdc++.h>
using namespace std;

void printAllSubsequences(string s, string output, int cur_pos) {
    if(cur_pos == s.length()) {
        // print the output string
        if(output == "")
            cout<<"null";
        else
            cout<<output;
        cout<<" ";
        return;
    }
    // without including the current char
    printAllSubsequences(s, output, cur_pos + 1);

    // with including current char
    output += s[cur_pos];
    printAllSubsequences(s, output, cur_pos + 1);
}

int main() {
    string s = "abc";
    string output = "";
    printAllSubsequences(s, output, 0);
    return 0;
}