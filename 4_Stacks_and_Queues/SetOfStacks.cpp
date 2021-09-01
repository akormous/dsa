#include<bits/stdc++.h>
using namespace std;

/*

Question: Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be
composed of several stacks and should create a new stack once the previous one exceeds capacity.
SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack
(that is, pop () should return the same values as it would if there were just a single stack).
FOLLOW UP
Implement a function popAt ( int index) which performs a pop operation on a specific sub-stack.


Approach:
A simple approach would be to create a vector of stacks.
When the n - 1 stack reaches threshold, push back a new stack in the vector


*/

/*

PROBLEM IN THIS SOLUTION:
The stack is not being updated in the set of stacks vector ? Even after using pointers ?
Refer to some already existing solution in C++ on the internet

*/

// Creating a custom class for stack because we need pointer to stack
class Stack {
    stack<int> s;
    public:
    Stack() {

    };
    void pop() {
        s.pop();
    }
    void push(int data) {
        s.push(data);
    }
    int top() {
        return s.top();
    }
    int size() {
        return s.size();
    }
    bool empty() {
        return s.empty();
    }
};

void printStack(Stack s) {
    while(s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

class SetOfStacks {
    public:
    // a vector of stack pointers
    vector<Stack*> v;
    int threshold;  // the number after which a new stack will be created
    
    SetOfStacks() = delete;
    SetOfStacks(int t) {
        threshold = t;
    }
    // a helper function that creates and returns a pointer to new stack
    Stack* createNewStack() {
        return (new Stack);
    }

    // helper function to return the last stack in the vector
    Stack* getLastStack() {
        return v[v.size() - 1];
    }

    // push data is set of stacks
    void push(int data) {
        // if the vector is empty or
        // if the last stack has reached threshold, then also create a new stack
        if( v.size() == 0 || ( getLastStack() -> size() >= threshold ) ) {
            // push a new stack with the data
            v.push_back(createNewStack());
        }
        // push the data to the last stack
        getLastStack() -> push(data);
    }

    // return the topmost element of the last stack in the vector
    int top() {
        // if vector is empty
        if(v.size() == 0)
            return INT_MAX;
        //cout<<"Current size of vector = "<<v.size()<<endl;
        return getLastStack() -> top();
    }

    // popping is tricky, because if the last stack becomes empty, then you gotta delete it
    void pop() {
        // if the last stack is empty, then remove it
        if(getLastStack() -> empty()) {
            v.pop_back();
        }
        getLastStack() -> pop();
    }

    void printAll() {
        for(int i = 0; i < v.size(); i++) {
            Stack* temp = v[i];
            printStack(*temp);
        }
    }
};

int main() {
    
    SetOfStacks a(3);

    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);

    cout<<"Pop  "<<a.top()<<endl;
    a.pop();
    

    cout<<"Pop  "<<a.top()<<endl;    
    a.pop();

    a.printAll();
    cout<<"Pop  "<<a.top()<<endl;
    a.pop();

    cout<<"Pop  "<<a.top()<<endl;
    return 0;
}