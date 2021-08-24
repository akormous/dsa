#include<bits/stdc++.h>
using namespace std;

/*

Question: Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
an additional temporary stack, but you may not copy the elements into any other data structure
(such as an array). The stack supports the following operations: push, pop, peek, and is Empty.


Approach:
O(n^2)

Search and push.....booorrrriiiiiinnnggg

Basically, create another stack where the largest number is at the top
*/

void sortStack(stack<int>& s) {
    stack<int> r;   // descending order from top to bottom aka reverse

    while(!s.empty()) {
        // store the top element in a temp variable
        int temp = s.top();
        s.pop();
        while(!r.empty() && r.top() > temp) {
            int t2 = r.top();
            r.pop();
            s.push(t2);
        }
        r.push(temp);
    }

    // copy all elements from r to s
    while(!r.empty()) {
        int temp = r.top();
        r.pop();
        s.push(temp);
    }
}

void print(stack<int> s) {
    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main() {
    stack<int> s;
    s.push(144);
    s.push(60);
    s.push(800);
    s.push(600);
    s.push(1920);
    s.push(1080);
    s.push(1280);
    s.push(720);
    s.push(640);
    s.push(480);
    print(s);
    cout<<endl;
    sortStack(s);

    print(s);
    return 0;
}