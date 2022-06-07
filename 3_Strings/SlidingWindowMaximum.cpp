#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;       // double ended queue
        vector<int> result; // answer
        // iterate over the array
        for(int i = 0; i < nums.size(); ++i) {
            if(!dq.empty() && dq.front() == i-k )   // checking if window size > k
                dq.pop_front();
            // remove all the elements from tail of dq which are less than nums[i]
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k-1)  // we have a window of size k or > k
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};