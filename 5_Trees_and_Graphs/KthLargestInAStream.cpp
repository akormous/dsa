#include<bits/stdc++.h>
using namespace std;

class KthLargest {
private:
    // create a min-heap of size k
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    
public:

    KthLargest(int ik, vector<int>& nums) {
        k = ik;
        // insert the elements in the queue
        for(int num : nums)
            q.push(num);
    }
    
    int add(int val) {
        q.push(val);
        
        while(q.size() > k)
            q.pop();
        
        return q.top();
    }
};