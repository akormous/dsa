#include<bits/stdc++.h>
using namespace std;

/*

Magic Index: A magic index in an array A [ 0 ••• n -1] is defined to be an index such that A[ i]  = 
i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in
array A.
Q2 - What if the values are not distinct?



*/

/* if only distinct integers
if the middle+1 index <= the element at hi index, then search in the right part
if middle-1 index >= arr[lo], then search in the left part

*/
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

/* if duplicates are allowed
Here we cannot know for sure which side contains the magic index, so we have to search both sides no matter what
but there is a catch

compare midIndex and arr[midIndex],

consider searching left side,
if midIndex-1 > arr[midIndex-1], so the hi for left side will be arr[midIndex-1]
so when searching left side, the hi cap will be minimum of midIndex and arr[midIndex]

similarly for the right side, the lo cap will be maximum of midIndex and arr[midIndex]
*/
int getMagicIndex2(vector<int> arr, int lo, int hi) {
    if(hi >= lo) {
        int midIndex = (lo + hi)/2;
        int midValue = arr[midIndex];

        if(midIndex == midValue)
            return midIndex;
        
        int result = -1;
        // search the left part
        result = getMagicIndex2(arr, lo, min(midIndex-1, midValue));
        
        if(result != -1)
            return result;
        
        return getMagicIndex2(arr, max(midIndex+1, midValue), hi);
    }
    return -1;
}

int main() {

    vector<int> arr = {-10, -2, -1, 0, 1, 5, 7, 69, 420};

    cout<<getMagicIndex2(arr, 0, arr.size()-1)<<endl;

    return 0;
}