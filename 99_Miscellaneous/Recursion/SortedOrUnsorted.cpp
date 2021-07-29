/*
Check if an array is sorted or unsorted
*/
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n, int cur_index) {
    // base condition 1: if whole array is traversed
    if(cur_index == n)
        return true;
    // base condition 2: if elements are found out of order
    if(arr[cur_index] < arr[cur_index - 1])
        return false;

    // make recursive call for next index
    return isSorted(arr, n, cur_index + 1);
    
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    // starting from the first index
    // basically, we need to compare an element with prev element
    // if they are out of order, then the array is not sorted
    cout<<"Is the given array sorted ? "<<isSorted(arr, n, 1);
    return 0;
}