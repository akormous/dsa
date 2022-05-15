#include<bits/stdc++.h>
using namespace std;

int getBitonicPoint(vector<int> &arr) {
    int l = 0;
    int r = arr.size() - 1;

    while(l <= r) {
        int m = (l + r)/2;

        // if there are only 2 elements between l .. r
        if(r == l+1) {
            return (arr[l] > arr[r] ? l : r);
        }
        // base case, when arr[m] is largest among its neighbors
        if(arr[m] > arr[m-1] && arr[m] > arr[m+1])
            return m;
        
        // modify r or l
        if(arr[m] > arr[m-1] && arr[m] < arr[m+1])
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}
// binary search for increasing sequence
int binarySearch(vector<int> &arr, int l, int r, int val) {
    while(l <= r) {
        int m = (l+r)/2;
        if(arr[m] == val)
            return m;
        if(arr[m] < val)
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

// binary search for decreasing sequence
int binarySearch2(vector<int> &arr, int l, int r, int val) {
    while(l <= r) {
        int m = (l+r)/2;
        if(arr[m] == val)
            return m;
        if(arr[m] < val)
            r = m-1;
        else
            l = m+1;
    }
    return -1;
}



int solve(vector<int> &A, int B) {
    int bp = getBitonicPoint(A);
    //cout << bp << " " << A[bp] << endl;
    int solA = binarySearch(A, 0, bp, B);
    if(solA != -1)
        return solA;
    return binarySearch2(A, bp+1, A.size() - 1, B);
}

int main() {
    vector<int> arr = {1,3,50,10,9,7,6};
    solve(arr, 7);
    return 0;
}