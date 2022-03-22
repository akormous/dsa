#include<bits/stdc++.h>
using namespace std;

class FreqStack {
public:
    
    unordered_map<int, int> freqTable;
    
    unordered_map<int, stack<int>> groupStack;
    
    int max_occur = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        
        freqTable[val]++;
        
        max_occur = max(  max_occur, freqTable[val]);
        
        groupStack[freqTable[val]].push(val);
        
    }
    
    int pop() {
        
        int top = groupStack[max_occur].top();
        
        freqTable[top]--;
        
        groupStack[max_occur].pop();
        
        if(groupStack[max_occur].empty())
            max_occur--;
        
        return top;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */