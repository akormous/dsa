#include<bits/stdc++.h>
using namespace std;

/*
SELECTION SORT - the array is divided into two parts, sorted and unsorted, and then you know how it goes..ez
Time Complexity - O (n^2)
*/

void selectionSort(vector<int>& arr, int n) {
    for(int i = 0; i < n-1; i++) {
        int min = i + 1;  // index of smallest element in unsorted part
        for(int j = i+1; j < n; j++) {
            min = arr[j] < arr[min] ? j : min;
        }
        swap(arr[i], arr[min]);
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
    selectionSort(arr, arr.size());
    displayArray(arr, arr.size());
    return 0;
}