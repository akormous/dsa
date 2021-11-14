#include<bits/stdc++.h>
using namespace std;

/*

Magic Index: A magic index in an array A [ 0 ••• n -1] is defined to be an index such that A[ i]  = 
i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in
array A.
Q2 - What if the values are not distinct?



*/

// if only distinct integers
int getMagicIndex(vector<int> arr, int lo, int hi) {
    if(hi >= lo) {
        int mid = (lo + hi)/2;

        if(mid == arr[mid])
            return mid;
        
        int result = -1;

        if(mid + 1 <= arr[hi])
            result = getMagicIndex(arr, mid+1, hi);
        
        if(result != -1)    return result;

        if(mid-1 >= arr[lo])
            return getMagicIndex(arr, lo, mid-1);
    }
    return -1;
}

// if duplicates are allowed
// to do
int getMagicIndex2(vector<int> arr, int lo, int hi);

int main() {

    vector<int> arr = {-10, -2, -1, 0, 1, 5, 7, 69, 420};

    cout<<getMagicIndex(arr, 0, arr.size()-1)<<endl;

    return 0;
}