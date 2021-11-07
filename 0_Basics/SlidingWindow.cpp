#include<bits/stdc++.h>
using namespace std;

/*
Sliding Window - imagine a bus traversing through an array,
you just subtract the first element and add the new element
easy nothing to explain
*/

// returns the maximum sum of k consecutive elements
int slidingWindowSum(vector<int> arr, int k) {
    int maxSum = INT_MIN;
    // if window size is greater than length of array
    if(k > arr.size())  return INT_MIN;

    // find the sum of the first k elements
    int curWindowSum = 0;
    for(int i = 0; i < k; ++i)
        curWindowSum += arr[i];
    
    maxSum = max(maxSum, curWindowSum);

    // start from the kth element, then calc sum of each window
    for(int i = k; i < arr.size(); ++i) {
        curWindowSum = curWindowSum - arr[i - k] + arr[i];
        maxSum = max(maxSum, curWindowSum);
    }
    return maxSum;
}

int main() {
    vector<int> arr = {1,3,-6,5,3,-67,8,0, 8,4,1};
    // solution
    cout<<slidingWindowSum(arr, 2)<<endl;
    cout<<slidingWindowSum(arr, 3)<<endl;
    cout<<slidingWindowSum(arr, 4)<<endl;
    cout<<slidingWindowSum(arr, 5)<<endl;
    return 0;
}