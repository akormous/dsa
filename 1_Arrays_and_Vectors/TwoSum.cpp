#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // result
        vector<int> result;
        // using a hashmap
        unordered_map<int, int> umap;

        int n = nums.size();
        
        for(int i=0; i < n; i++) {
            // checking if the required diff is already present in the hashmap
            if(umap.find(nums[i]) != umap.end()) {
                result.push_back( umap[nums[i]] );
                result.push_back(i);
                break;
            }
            umap[target - nums[i]] = i;
        }
        return result;
    }
};