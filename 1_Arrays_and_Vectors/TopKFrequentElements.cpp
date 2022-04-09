#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // create a frequency array
        unordered_map<int, int> freq;
        for(int num : nums)
            freq[num]++;
        
        
        // its obvious that the highest frequency will not be greater than n
        // create n buckets, these buckets map freq -> numbers
        vector<vector<int>> buckets(n+1, vector<int>());
        
        for(auto p : freq) {
            int num = p.first;
            int freq = p.second;
            
            buckets[freq].push_back(num);
        }
        
        // get the most frequent k elements i.e. traverse the buckets from the end
        vector<int> result;
        for(int i = n; i >= 0 && result.size() < k; i--) {
            for(int num : buckets[i]) {
                result.push_back(num);
                if(result.size() == k) {
                    break;
                }
            }
        }
        return result;
    }
};
