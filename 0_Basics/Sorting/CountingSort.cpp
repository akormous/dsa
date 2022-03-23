#include<bits/stdc++.h>
using namespace std;


void displayArr(vector<int> arr) {
    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
}

void countingSort(vector<int>& arr) {

    // find the minimum and maximum element in the array
    int min = *min_element(arr.begin(), arr.end());
    int max = *max_element(arr.begin(), arr.end());
    int range = max - min + 1;

    // result vector
    vector<int> result(arr.size());

    // initialize a frequency array with all values as 0
    vector<int> freq(range, 0);
    // fill in the frequency array
    for(auto n : arr) {
        freq[n - min]++;
    }

    // do prefix sum on frequency array,
    // so that we get to know till which index a given number is supposed to be filled
    for(int i = 1; i < freq.size(); i++) {
        freq[i] += freq[i-1];
    }

    // fill in the values according to the predetermined indices
    for(int i = arr.size() - 1; i >= 0; --i) {

        result[ freq[ arr[i] - min ] - 1 ] = arr[i];

        freq[ arr[i] - min ]--;
    }

    // modify the original array
    for(int i = 0; i < result.size(); i++)
        arr[i] = result[i];

    
}



int main() {
    // solution
    vector<int> arr = { -5, -10, 0, -3, 8, 5, -1, 10 };

    countingSort(arr);

    displayArr(arr);

    return 0;
}