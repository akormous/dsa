#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        result[0] = 1;
        // result[i] = product of prefix of i * product of suffix of i
        
        // store prefix at each i
        for(int i = 1; i < n; i++)
            result[i] = result[i-1] * nums[i-1];
        
        // calculate suffix product at each i and multiply with result[i]
        int suffixProd = 1;
        for(int i = n-1; i >= 0; i--) {
            result[i] = result[i] * suffixProd;
            suffixProd = suffixProd * nums[i];
        }
        return result;
    }
};