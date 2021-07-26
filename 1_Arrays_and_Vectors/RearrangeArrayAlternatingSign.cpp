#include<bits/stdc++.h>
using namespace std;

// shift all negative element to the end
// returns the index of first negative element in the arr
int shiftNegativeToEnd(vector<int>& arr) {
    int n = arr.size();
    int l = 0, r = n - 1;
    while(l < r) {
        // search for a negative integer from the left
        while(l < n && arr[l] >= 0)
            l++;
        // search for a positive integer from the right
        while(r >= 0 && arr[r] < 0)
            r--;

        if(l < r)
            swap(arr[l], arr[r]);
    }
    return l;
}


void rearrange(vector<int>& arr, int p) {
    int n = arr.size();
    int i = 0;
    while(i < n && p < n) {
        swap(arr[i], arr[p]);
        i = i + 2;
        p = p + 1;
    }
}
void displayArr(vector<int> arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;
}
// solution
void solution(vector<int>& arr) {
    cout<<"Original Array"<<endl;
    displayArr(arr);
    cout<<"Shifting all negative integer to the end"<<endl;
    int pivot = shiftNegativeToEnd(arr);
    displayArr(arr);
    cout<<"Rearranging the array in alternating negative and positive integers"<<endl;
    rearrange(arr, pivot);
    displayArr(arr);
}



int main() {
    vector<int> arr = {-5, -2, -5, -2, -4, 7, 1, 8, 0, -8};
    vector<int> arr2 = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    solution(arr);   
    solution(arr2);
    return 0;
}