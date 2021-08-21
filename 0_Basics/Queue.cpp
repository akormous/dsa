#include<bits/stdc++.h>
using namespace std;

/*

QUEUE:
First In First Out

Nodes added at the end, but removed from the front

There are many variations of queue,
such as Double Ended Queue, Priority Queue etc.

*/

struct Node {
    int val;
    Node* next;
    Node(int n) : val(n), next(nullptr) {}
};

class Queue {
    private:
    Node* first;
    Node* last;

    public:
    Queue() {
        first = nullptr;
        last = nullptr;
    }

    bool isEmpty() {
        return first == nullptr;
    }
    void add(int data) {
        if(first == nullptr) {
            first = new Node(data);
            last = first;
        }
        else {
            last -> next = new Node(data);
            last = last -> next;
        }
    }

    void print() {
        if(isEmpty()) {
            cout<<"QUEUE IS EMPTY!"<<endl;
            return;
        }
        Node* cur = first;
        while(cur != nullptr) {
            cout<<cur -> val<<" ";
            cur = cur -> next;
        }
        cout<<endl;
    }

    void deleteNode() {
        if(isEmpty()) {
            cout<<"QUEUE IS EMPTY!"<<endl;
            return;
        }
        Node* temp = first;
        if(first == last) {
            first = last = nullptr;
        }
        else {
            first = first -> next;
        }
        delete temp;
    }
};

int main() {
    Queue q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    q.print();
    q.deleteNode();
    q.deleteNode();
    q.print();
    q.deleteNode();
    q.deleteNode();
    q.print();
    q.deleteNode();
    q.deleteNode();
    q.print();
    q.deleteNode();
    q.deleteNode();
    q.deleteNode();

    

    return 0;
}