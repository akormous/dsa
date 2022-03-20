#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> countA(7, 0);
        vector<int> countB(7, 0);
        vector<int> same(7, 0);
        
        int n = tops.size();
        
        for(int i = 0; i < n; ++i) {
            countA[ tops[i] ]++;
            countB[ bottoms[i] ]++;
            
            if(tops[i] == bottoms[i])
                same[ tops[i] ]++;
        }
        
        int result = INT_MAX;
        
        for(int i = 1; i <= 6; i++) {
            
            if(countA[i] + countB[i] - same[i] == n)
                result = min(countA[i], countB[i]) - same[i];
            
        }
        
        return (result == INT_MAX)? -1 : result;
        
    }
};