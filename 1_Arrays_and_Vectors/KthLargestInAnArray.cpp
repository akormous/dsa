#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // similar to the partition method of quickSort,
    // but here there is a condition for the recursive call
    int quickSelect(vector<int>& nums, int low, int high, int& k) {
        int pivot = nums[high]; // last element is pivot
        int i = low;
        
        // start from low to high
        for(int j = low; j < high; ++j) {
            if(nums[j] < pivot) {   // swap all larger element than pivot to the right
                swap( nums[j], nums[i] );
                i++;
            }
        }
        swap(nums[high], nums[i]);  // swap pivot with the actual position
        if(i == k)  // if the position was k, return it
            return nums[k];
        // if position was lower than k, then call on the right partition,
        // else call on the left partition
        return i < k ? quickSelect(nums, i + 1, high, k) : quickSelect(nums, low, i - 1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // if the array was sorted, then kth largest would be
        k = n - k;
        return quickSelect(nums, 0, n-1, k);
    }
};