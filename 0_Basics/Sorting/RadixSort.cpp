#include<bits/stdc++.h>
using namespace std;

// sorts the array based on the digit described by the exp
// for ones digit, exp = 1
// for tens digit, exp = 10 and so on
void customCountSort(vector<int>& arr, int n, int exp) {
    
    vector<int> result(n);

    // initialize a frequency arr of range 10 (0 - 9)
    vector<int> freq(10, 0);

    // populate the frequencies
    for(auto num : arr) {
        freq[ num / exp % 10 ]++;
    }

    // do prefix sum on frequencies
    for(int i = 1; i < freq.size(); ++i)
        freq[i] += freq[i-1];

    // use count sort
    for(int i = n-1; i >= 0; i--) {
        result[ freq[ arr[i] / exp % 10 ] - 1 ] = arr[i];
        freq[ arr[i] / exp % 10 ]--;
    }

    // modify the original array
    for(int i = 0; i < n; i++)
        arr[i] = result[i];
}

void display(vector<int> arr) {
    for(auto num : arr)
        cout<<num<<" ";
    cout<<endl;
}

int main() {
    // solution
    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };

    int max = *max_element(arr.begin(), arr.end());
    int exp = 1;
    while(max != 0) {

        customCountSort(arr, arr.size(), exp);
        exp *= 10;
        max /= 10;
    }

    display(arr);
    return 0;
}