#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        // store the frequencies
        for(auto num : nums) {
            mp[num]++;
        }
        // count of unique pairs
        int count = 0;

        // when k == 0, then numbers appearing twice or more can make diff 0
        if(k == 0) {
            for(auto num : mp) {
                if(num.second > 1)
                    count++;
            }
        }
        // when k > 0, then find num + k in the hash table
        else {
            for(auto num : mp) {
                if(mp.find(num.first + k) != mp.end())
                    count++;
            }
        }
        return count;
    }
};