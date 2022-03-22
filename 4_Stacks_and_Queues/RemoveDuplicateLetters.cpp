#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        stack<char> st;
        vector<bool> visited(26, false);
        unordered_map<char, int> lastIdx;
        
        // keep track of last index of each character in the string
        for(int i = 0; i < s.length(); ++i)
            lastIdx[s[i]] = i;
        
        
        // iterate over the characters
        for(int i = 0; i < s.length(); ++i) {
            char cur = s[i];
            
            /*
            if cur char is visited, then continue
            */
            if(visited[cur - 'a'])
                continue;
            
            /*
            while cur char is smaller than topmost char
            and cur char exists after this position as well
            then remove the topmost char
            */
            while(!st.empty() && cur < st.top() && lastIdx[st.top()] > i ) {
                
                char tmp = st.top();
                st.pop();
                visited[tmp - 'a'] = false;
            }
            /*
            if cur char is not visited, then push it to the stack
            */
            if(!visited[cur - 'a']) {
                st.push(cur);
                visited[cur - 'a'] = true;
            }
        }
        
        string result = "";
        
        // reverse the stack and form the resulting string
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};