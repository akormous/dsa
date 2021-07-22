#include<bits/stdc++.h>
using namespace std;

/*
BINARY SEARCH- works on sorted array
               divide and conquer
TIME COMPLEXITY- O(log(n))

APPLICATIONS- anything which is sorted and you want to search something
*/

int binarySearch(vector<int>& arr, int val) {
    int l = 0, r = arr.size() - 1;
    
    while(l <= r) {    
        int m = l + (r - l)/2; // mid index
        if( arr[m] == val )
            return m;
        // if the middle value is greater, then update right
        else if( arr[m] > val ) {
            r = m - 1;
        }
        // if middle value is smaller, then update left
        else {
            l = m + 1;
        }
    }
    return -1; // if number not found
}

void displayArray(vector<int> arr, int n) {
    cout<<endl;
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    return;
}


int main() {
    vector<int> arr = {45, 23, 9, 15, 12, 324, 5152, -655, 54, 14, 88, 0, -1, -733};
    sort(arr.begin(), arr.end());
    displayArray(arr, arr.size());
    cout<<endl;
    int val;
    cout<<"Enter the number you wanna search for - ";
    cin>>val;
    int answer = binarySearch(arr, val);
    if(answer == -1) {
        cout<<"Number not found";
    }
    else {
        cout<<"Number found at index - "<<answer;
    }
    return 0;
}