#include<bits/stdc++.h>
using namespace std;

/*

Find number of subarrays having sum less than or equal to K

Approach:
Sliding Window Technique

Start with the first element

*/

int subarrayCount(vector<int> arr, int k) {
    int start = 0, end = 0;
    int count = 0, sum = 0;


    while(end < arr.size()) {
        // add element from end of window
        sum += arr[end];

        // move the start pointer until sum is greater than k, basically discarding the starting element in the window
        while(start <= end && sum > k) {
            sum -= arr[start];
            start++;
        }

        count += (end - start + 1);
        end++;
    }
    return count;
}

int main() {
    // solution
    vector<int> arr = {1, 11, 2, 3, 15};
    cout<<subarrayCount(arr, 10)<<endl;
    return 0;
}