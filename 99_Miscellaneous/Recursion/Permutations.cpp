/*
Given a string, print all permuations of the string
*/
#include<bits/stdc++.h>
using namespace std;

/*
Approach is to swap char from cur_pos till end of the string
and get permutations,
after getting all the permutations at a given index,
swap the characters again to get the original string,
for the next permutation cycle
*/
void permutations(string s, int cur_pos) {
    if(cur_pos == s.length()) {
        cout<<s<<" ";
        return;
    }
    // swap every character of the string with all the characters and get permutations
    for(int i = cur_pos; i < s.length(); i++) {
        swap(s[i], s[cur_pos]);

        permutations(s, cur_pos + 1);

        // swap the characters back to bring the string to its original form
        swap(s[i], s[cur_pos]);
    }
}

int main() {
    string s = "abc";
    permutations(s, 0);
}