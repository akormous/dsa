/*
Find if an array contains a subarr with given sum
NOTE: The array can contain negative numbers as well 
*/
#include<bits/stdc++.h>
using namespace std;

void solution(vector<int>& arr, int x) {
    // size of arr
    int n = arr.size();
    // length of subarr with given sum
    int answer;
    // a hashmap that store prefix sum
    unordered_map<int,int> umap;
    /* Approach: store prefix sum in a hashmap,
        check if umap[i] - sum is already present in the hashmap
        if it is present, it means that a subarr with given sum is present
        (similar to zero sum subarr problem)
    */
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        // check if current sum is equal to the given sum
        if(sum == x) {
            cout<<"Subarray with sum "<<x<<" is present between 0 and "<<i<<endl;
            return;
        }
        // check if sum - x is present in the hashmap
        if(umap.find(sum - x) != umap.end()) {
            cout<<"Subarray with sum "<<x<<" is present between "<<umap[sum]<<" and "<<i<<endl;
            return;
        }

        umap[sum] = i;
    }

}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int x = -10;
    solution(arr, x);
    cout<<endl;
    return 0;
}