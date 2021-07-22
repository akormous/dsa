#include<bits/stdc++.h>
using namespace std;

/*
QUICK SORT - divide and conquer algorithm
             1. Pick an element as pivot
             2. Reorder the array such that all the elements
                with values less than the pivot, appear before the pivot
                and elements with values larger than pivot appear after the pivot
             3. Recursively invoke the function for the subarrays

Time Complexity- 
            Worst Case- O(n^2)
            Average Case- O(n * log(n))
*/

// this partition function choses last element as the pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // last element as pivot value
    int i = low - 1; // smallest element in the array

    // moving all the values smaller than pivot before pivot position
    for(int j = low; j < high; j++) {
        if( arr[j] < pivot ) {
            i++;
            swap( arr[i], arr[j] );
        }
    }

    // put the pivot at its correct position
    swap( arr[i+1], arr[high] );
    return (i+1);
}


// this parition function choses first element as the pivot
int partition1(vector<int>& arr, int low, int high) {
    swap( arr[low], arr[high] ); // swap the value at low and high
    // rest is same
    int pivot = arr[high]; // last element as pivot value
    int i = low - 1; // smallest element in the array

    // moving all the values smaller than pivot before pivot position
    for(int j = low; j < high; j++) {
        if( arr[j] < pivot ) {
            i++;
            swap( arr[i], arr[j] );
        }
    }

    // put the pivot at its correct position
    swap( arr[i+1], arr[high] );
    return (i+1);
}


void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        // find the partition position
        int pivot_location = partition1(arr, low, high);
        // recursively call quickSort for subarrays
        quickSort(arr, low, pivot_location - 1);
        quickSort(arr, pivot_location + 1, high);
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
    
    quickSort(arr, 0, arr.size() - 1);

    displayArray(arr, arr.size());
    return 0;
}