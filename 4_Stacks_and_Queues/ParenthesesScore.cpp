#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        if(s.length() == 0)
            return 0;
        
        stack<int> st;
        int cur = 0;
        
        for(char c : s) {
            
            if(c == '(') {
                st.push(cur);
                cur = 0;
            }
            else {
                cur = cur + st.top() + max(cur, 1);
                st.pop();
            }
        }
        return cur;
    }
};