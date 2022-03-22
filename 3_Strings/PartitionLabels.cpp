#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> lastIdx(26, -1);
        
        vector<int> result;
        
        for(int i = 0; i < s.length(); ++i)
            lastIdx[ s[i] - 'a' ] = i;
        
        for(int i = 0; i < s.length(); ) {
            
            int start = i;
            int end = lastIdx[ s[i] - 'a' ];
            
            for(int j = start; j < end; ++j) {
                
                if(lastIdx[ s[j] - 'a' ] > end)
                    end = lastIdx[ s[j] - 'a' ];
                
            }
            
            result.push_back(end - start + 1);
            i = end + 1;
        }
        return result;
    }
};