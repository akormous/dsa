/*
Given an array, print all the elements that are present in the power set of the array
using recursion

Number of elements in the power set = 2^n,
where n = number of elements in the array
*/
#include<bits/stdc++.h>
using namespace std;

void printPowerSet(vector<int> arr, vector<int> output, int cur_index) {
    // check if cur_index is greater than the size of the array
    // aka base condition
    if(cur_index == arr.size()) {
        // print output
        for(auto i : output)
            cout<<i<<" ";
        cout<<endl;
        return;
    }

    // not including the element at cur_index
    printPowerSet(arr, output, cur_index + 1);

    // adding the element at cur_index to output
    output.push_back(arr[cur_index]);

    // recursive call after including the element at cur_index
    printPowerSet(arr, output, cur_index + 1);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> output;
    int cur_index = 0;
    printPowerSet(arr, output, cur_index);
    return 0;
}