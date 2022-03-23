#include<bits/stdc++.h>
using namespace std;

/*
INSERTION SORT - imagine sorting a deck of cards by hand
                 take one card from the unsorted part 
                 and search for its relevant position in the sorted part
Time Complexity - O (n^2)
*/

void insertionSort(vector<int>& arr, int n) {
    for(int i = 1; i < n; i++) {
        int pos = i-1;
        int val = arr[i]; // number which need to be put in its right place
        // traverse the sorted part of the array in reverse and compare it with val
        while(pos >=0 && arr[pos] > val) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        // assign val to its correct position
        arr[pos + 1] = val;
    }
}

void displayArray(vector<int> arr, int n) {
    cout<<endl;
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    return;
}

int main() {
    vector<int> arr = {45, 23, 9, 15, 12, 324, 5152, -655, 54, 14, 88, 0, -1, -733};
    displayArray(arr, arr.size());
    insertionSort(arr, arr.size());
    displayArray(arr, arr.size());
    return 0;
}