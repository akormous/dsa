#include<bits/stdc++.h>
using namespace std;

/*

BUCKET SORT - Sorting Algorithm

Is is mainly useful when input is uniformly distributed over a range.

Lets assume the input array = arr[n]
find the range of number (max - min)

now, we want to create n buckets, so the range of each bucket would be (max - min)/n

Iterate over the input and put the numbers in its bucket,
the bucket index will be 
(arr[i] - minimum)/bucketSize



Time Complexity = O(n)
Space Complexity = O(n)

*/

void bucketSort(vector<int>& arr) {
    int n = arr.size();
    // find the maximum and minimum element
    auto p = minmax_element(arr.begin(), arr.end());
    int minimum = *p.first;
    int maximum = *p.second;

    // calculate the bucket size
    int bucketSize =  ceil((maximum - minimum)/float(n));
    // declare buckets
    vector<vector<int>> buckets(n, vector<int>());
    // put the numbers to its assigned bucket, notice how to calculate bucketIndex
    for(int num : arr) {
        int bucketIndex = (num - minimum)/bucketSize;
        buckets[bucketIndex].push_back(num);
    }
    // sort every bucket
    for(int i = 0; i < n; ++i)
        sort(buckets[i].begin(), buckets[i].end());
    

    arr.clear();
    // modify the original array
    for(auto b : buckets) {
        for(int num : b)
            arr.push_back(num);
    }
}


int main() {
    // solution
    vector<int> arr = {45, 23, 9, 15, 12, 324, 5152, -655, 54, 14, 88, 0, -1, -733};

    bucketSort(arr);

    for(int n : arr)
        cout << n << " ";

    return 0;
}