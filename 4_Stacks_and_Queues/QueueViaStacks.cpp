#include<bits/stdc++.h>
using namespace std;

/*

Question: Implement a queue using stacks

Queue = First In First Out

Approach: Maintain 2 stacks

1. First stack will keep the pushed elements (enqueue)
2. Second stack will come into action when we want to dequeue an element
   In that case, move all elements from the first stack and push it to the second stack 
*/

class QueueUsingStacks {
    stack<int> s1;  // enqueue here
    stack<int> s2;  // dequeue from here

    public:
    // helper function that moves all elements from s1 to s2
    void moveS1toS2() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    // enqueue
    void push(int data) {
        s1.push(data);
    }
    // dequeue
    void pop() {
        // if s2 is empty, then move all elements from s1 to s2
        if(s2.empty()) 
            moveS1toS2();
        s2.pop();
    }
    // return the front element in the queue
    int front() {
        if(s2.empty()) 
            moveS1toS2();
        return s2.top();
    }
    // return true if queue is empty, else false
    bool empty() {
        return ( s1.empty() && s2.empty() );
    }
    // return the size of the queue
    int size() {
        return ( s1.size() + s2.size() );
    }
};

int main() {
    // create an object of QueueUsingStacks
    QueueUsingStacks q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    cout<<"Front element = "<<q.front()<<endl;

    q.pop();
    q.pop();
    q.pop();

    cout<<"Front element = "<<q.front()<<endl;

    return 0;
}