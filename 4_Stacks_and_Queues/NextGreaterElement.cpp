#include<bits/stdc++.h>
using namespace std;

/*
Read the concept of monotonic increasing / decreasing stack
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        
        stack<int> st;  // decreasing monotonic stack
        
        for(int i = 0; i < 2*n; ++i) {
            while(!st.empty() && nums[i%n] > nums[st.top()]) {
                result[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return result;
    }
};