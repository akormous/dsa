#include<bits/stdc++.h>
using namespace std;

/*
MERGE SORT - divide and conquer algorithm
             dividing the array into small parts
             and mergin them together in sorted way
Time Complexity - O (n * log(n))
*/

void merge(vector<int>& arr, int l, int r, int m) {
    // number of elements in the first array
    int n1 = (m - l + 1);
    // number of elements in the second array
    int n2 = (r - m);
    
    // copying values of the divided arrays in two new arrays
    int P[n1], Q[n2];
    for(int i = 0; i < n1; i++)
        P[i] = arr[l + i];
    
    for(int j = 0; j < n2; j++)
        Q[j] = arr[m + 1 + j];
    
    
    // two pointer will traverse P and Q
    // smaller of two elements will be added to the original array
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if( P[i] <= Q[j] )
            arr[k++] = P[i++];
        else
            arr[k++] = Q[j++];
    }
    // emptying the new arrays
    while(i < n1)
        arr[k++] = P[i++];

    while(j < n2)
        arr[k++] = Q[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l < r) {
        // mid of the array
        int m = (l + r )/ 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, r, m);
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
    // left and right index of the array
    // basically defining the boundaries of the array
    mergeSort(arr, 0, arr.size() - 1);

    displayArray(arr, arr.size());
    return 0;
}