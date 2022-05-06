#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        stack<int> freq;
        
        for(char c : s) {
            if(!st.empty() && c == st.top()) {
                freq.push( freq.top() + 1 );
            }
            else {
                freq.push(1);
            }
            st.push(c);
            
            if(freq.top() == k) {
                char tmp = st.top();
                while(!st.empty() && st.top() == tmp) {
                    st.pop();
                    freq.pop();
                }
            }
        }
        
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};