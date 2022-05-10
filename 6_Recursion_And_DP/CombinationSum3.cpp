#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtracker( int k, int n, vector<int>& mySet, vector<vector<int>>& result ) {
        if(n == 0 && mySet.size() == k) {
            result.push_back(mySet);
            return;
        }
        
        // start from mySet.back() + 1, because we dont want to repeat the same combination
        int start = mySet.empty() ? 1 : mySet.back() + 1;
        for(int i = start; i <= 9; ++i) {
            if(n - i < 0)   break;  // when sum goes negative, do not proceed
            mySet.push_back(i); // add to set
            backtracker(k, n - i, mySet, result);
            mySet.pop_back();   // remove from set, i.e. backtracking
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> mySet;
        
        backtracker(k, n, mySet, result);
        return result;
        
    }
};