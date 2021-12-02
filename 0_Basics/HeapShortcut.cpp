#include<bits/stdc++.h>
using namespace std;

/*

Implementing min heap and max heap using priority queue

Max Heap - 
priority_queue<int> maxHeap;

Min Heap -
priority_queue<int, vector<int>, greater<int>> minHeap;

*/

void maxHeapImplementation() {
    // implements a max heap
    priority_queue<int> h;
    // pushing elements to maxHeap
    h.push(99);
    h.push(59);
    h.push(69);
    h.push(9);
    h.push(2);
    h.push(13);
    h.push(10231);

    while(!h.empty()) {
        cout<<h.top()<<" ";
        h.pop();
    }
    return ;
}

void minHeapImplementation() {
    // implements a min heap
    priority_queue<int, vector<int>, greater<int>> h;
    // pushing elements to minHeap
    h.push(99);
    h.push(59);
    h.push(69);
    h.push(9);
    h.push(2);
    h.push(13);
    h.push(10231);

    while(!h.empty()) {
        cout<<h.top()<<" ";
        h.pop();
    }
    return ;
}

int main() {
    // solution
    maxHeapImplementation();
    cout<<endl;
    minHeapImplementation();
    return 0;
}