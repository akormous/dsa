#include<bits/stdc++.h>
using namespace std;

/*
Question is to sort a paragraph from the 2nd letter of each word
Approach - 
1. Strip out all words from the paragraph
2. Sort them using a comparator function
*/

// a comparator function that compares 2nd letter of each word
bool compare2ndLetter(string s1, string s2) {
    return (s1[1] < s2[1]);
}

vector<string> solution(string paragraph) {
    vector<string> words;
    string temp_word;
    stringstream ss(paragraph);
    while(ss >> temp_word)
        words.push_back(temp_word);
    
    sort(words.begin(), words.end(), compare2ndLetter);
    return words;
}

int main() {
    string paragraph = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";
    cout<<paragraph;
    cout<<endl<<endl;    
    vector<string> ans = solution(paragraph);
    for(string i : ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}