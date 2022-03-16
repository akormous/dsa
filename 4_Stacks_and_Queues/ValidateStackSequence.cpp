#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        int n = pushed.size();
        
        if(n == 0)
            return true;
        
        stack<int> s;
        
        while(i < n && j < n) {
            
            s.push( pushed[i++] );
            
            while(!s.empty() && (s.top() == popped[j])) {
                s.pop();
                j++;
            }
            
        }
        
        return s.empty();
    }
};