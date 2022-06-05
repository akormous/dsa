#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool contains(unordered_map<int,int>& iMap, int iVal) {
        return (iMap.find(iVal) != iMap.end());
    }
    int longestConsecutive(vector<int>& nums) {
        // maps the boundary values of a sequence to its longest sequence length
        unordered_map<int,int> map;
        int result = 0;
        for(int& n : nums) {
            if(map.find(n) == map.end()) {
                int left = contains(map, n-1) ? map[n-1] : 0; // get the sequence length of prev neighbor
                int right = contains(map, n+1) ? map[n+1] : 0;// get the sequence length of next neighbor
                
                int sum = 1 + left + right; // sequence length at n
                
                map[n] = sum;
                result = max(result, sum);
                // update the boundary values
                map[n - left] = sum;
                map[n + right] = sum;
            }
            else {
                continue;   // duplicates
            }
        }
        return result;
    }
};