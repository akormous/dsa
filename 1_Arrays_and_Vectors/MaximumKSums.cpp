#include<bits/stdc++.h>
using namespace std;

vector<int> maximumKSums(vector<int> arr, int k) {
    // get the sum of all positive numbers, and turn all the negative numbers to their absolute value
    int total = 0;   // sum of all positive numbers
    for(int& n : arr) {
        if(n > 0)
            total += n;
        else
            n = abs(n);
    }

    // sort the arr
    sort(arr.begin(), arr.end());

    // maintain a min pq of size k
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(total);
    for(int& n : arr) {
        if(minHeap.size() == k) break;
        minHeap.push(total - n);
    } 
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    // solution
    vector<int> input = {-4, -5, -7, 2, 5};
    int k = 6;
    vector<int> ans = maximumKSums(input, k);
    for(int& a : ans)
        cout << a << " " ;
    cout << endl;
    return 0;
}