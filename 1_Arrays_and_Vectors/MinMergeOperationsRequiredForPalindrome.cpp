/*
Refer: https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
*/
#include<bits/stdc++.h>
using namespace std;

int minMergeOperations(int arr[], int l, int r) {
    // if left pointer and right pointer are at same position
    if(l >= r) {
        return 0;
    }
    // if left and right numbers satisfy palindrome condition
    if(arr[l] == arr[r])
        return minMergeOperations(arr, l + 1, r - 1);
    // if number at left > number at right
    if(arr[l] > arr[r]) {
        arr[r - 1] = arr[r - 1] + arr[r];
        return 1 + minMergeOperations(arr, l, r - 1);
    }
    // if number at right is greater than number at left
    arr[l + 1] = arr[l] + arr[l + 1];
    return 1 + minMergeOperations(arr, l + 1, r);
}

int findMinOps(int arr[], int n) {
    return minMergeOperations(arr, 0, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[] = {1, 4, 5, 9, 1, 2, 4, 54, 3, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Count of minimum operations is "
         <<  findMinOps(arr, n) << endl;
    return 0;

    return 0;
}