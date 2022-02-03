#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        if(n == 0)  return 0;
        
        int result = 0;
        
        unordered_map<int,int> sumFreq12;
        for(auto n1 : nums1) {
            for(auto n2 : nums2) {
                sumFreq12[n1 + n2]++;
            }
        }
        
        
        unordered_map<int,int> sumFreq34;
        for(auto n3 : nums3) {
            for(auto n4 : nums4) {
                sumFreq34[n3 + n4]++;
            }
        }
        
        
        unordered_map<int,int>::iterator it;
        
        for(it = sumFreq12.begin(); it != sumFreq12.end(); ++it) {
            
            if(sumFreq34.find(0 - it->first) != sumFreq34.end()) {
                result += sumFreq12[it->first] * sumFreq34[0 - it->first];
            }
        }
        return result;
    }
};