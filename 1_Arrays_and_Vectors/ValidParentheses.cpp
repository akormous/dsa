#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isClosingBracket(char b) {
        if(b == ')' || b == '}' || b == ']')
            return true;
        return false;
    }
    bool isValid(string s) {
        if(s.length() % 2 == 1)
            return false;
        unordered_map<char, char> umap;
        umap['('] = ')';
        umap['{'] = '}';
        umap['['] = ']';
        // create a stack
        stack<char> st;
        
        for(char i:s) 
        {
            // if it is a closing bracket 
            if(isClosingBracket(i))
            {
                // if either stack is empty or the topmost element doesnt match
                if(st.empty() || umap[st.top()] != i)
                    return false;
                // if all good, then pop
                st.pop();
            }
            else
            {
                // pushing opening brackets only
                st.push(i);
            }
        }
        // if there is something left in stack, then the parentheses are not valid
        return st.empty();
    }
};