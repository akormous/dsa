#include<bits/stdc++.h>
using namespace std;

/*
BUBBLE SORT - repeatedly swapping adjacent numbers if they are in the wrong order
Time Complexity - O (n^2)
*/

void bubbleSort(vector<int>& arr, int n) {
    for(int i = 1; i < n; i++)
        for(int j = 0; j < (n - i); j++)
            // comparing adjacent numbers
            if(arr[j] > arr[j + 1])
                // swapping if the numbers are not in order
                swap(arr[j], arr[j + 1]);
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
    bubbleSort(arr, arr.size());
    displayArray(arr, arr.size());
    return 0;
}