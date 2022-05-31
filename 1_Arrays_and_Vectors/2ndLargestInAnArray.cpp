#include<bits/stdc++.h>
using namespace std;

/*
Given an array of numbers, find the 2nd largest element in the array in a single traversal
*/

int getSecondLargest(vector<int>& arr) {
    int n = arr.size();
    int first = arr[0];
    int second = -1;
    for(int i = 1; i < n; ++i) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if(arr[i] < first) {
            if(second == -1 || arr[i] > second)
                second = arr[i];
        }
    }
    return second;
}

int main() {
    // solution
    vector<int> arr = {5,7,2,4,8,9,11,1,5,13};
    cout << getSecondLargest(arr) << endl;

    return 0;
}