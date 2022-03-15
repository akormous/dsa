#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isOpen(char c) {
        return (c == '(');
    }
    
    bool isClose(char c) {
        return (c == ')');
    }
    
    string minRemoveToMakeValid(string s) {
        string result = "";
        stack<char> st;
        
        if(s.empty())
            return result;
        
        vector<bool> tracer(s.length(), 1);
        
        for(int i = 0; i < s.length(); ++i) {
            
            if( isOpen(s[i]) )
                st.push(s[i]);
                
            else if( isClose(s[i]) ) {
                
                if( !st.empty() && isOpen(st.top()))
                    st.pop();
                else
                    tracer[i] = 0;
            }
        }
        
        cout<<st.empty()<<endl;
        int i = s.length() - 1;
        while(i >= 0 && !st.empty()) {
            
            if( isOpen(s[i]) ) {
                tracer[i] = 0;
                st.pop();
            }
                
            i--;
        }
        
        for(i = 0; i < s.length(); ++i) {
            if(tracer[i] == 1)
                result += s[i];
        }
        return result;
    }
};