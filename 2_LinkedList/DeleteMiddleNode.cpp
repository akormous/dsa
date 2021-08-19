#include<bits/stdc++.h>
using namespace std;

/*

Question:
Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node.


Solution  - O(1)


*/

struct Node{
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
    public:
    LinkedList() {
        head = nullptr;
    }
    // create a node with given data

    // insert at front of the linked list using data provided
    void insert(int d) {
        // create a new node
        Node* temp = new Node;
        temp -> data = d;
        temp -> next = nullptr;
        if(head) {
            temp -> next = head;
        }
        head = temp;
    }
    // returns Node from the position specified
    Node* getMiddleNode(int c) {
        Node* cur = head;
        while(--c)
            cur = cur -> next;
        return cur;
    }

    // delete the first occurence of a node with given data
    void deleteNode(int d) {
        if(head == nullptr) {
            cout<<"EMPTY LINKED LIST!"<<endl;
            return;
        }
        if(head -> data == d) {
            Node* temp = head;
            head = head -> next;
            delete temp;
            return;
        }
        Node* cur = head;
        while(cur -> next != nullptr) {
            if(cur -> next -> data == d) {
                Node* temp = cur -> next;
                cur -> next = cur -> next ->next;
                delete temp;
                return ;
            }
        }
        cout<<"NOT FOUND!";
    }

    // print Linked List
    void print() {
        Node* cur = head;
        while(cur != nullptr) {
            cout<<cur -> data <<" ";
            cur = cur -> next;
        }
        cout<<endl;
    }

    // solution function here
    void removeMiddleNode(Node* n) {
        // check if the node is the last node in the linked list
        if(n == nullptr || n -> next == nullptr) {
            cout<<"CANNOT DELETE LAST NODE!"<<endl;
            return;
        }

        Node* cur = n;
        // make sure to delete the next node later
        Node* temp = cur -> next;
        cur -> data = cur -> next -> data;
        cur -> next = cur -> next -> next;
        delete temp;
    }

};

int main() {
    LinkedList l1;
    // inserted random numbers in the linked list
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);
    l1.insert(9);
    l1.insert(10);
    l1.insert(11);
    l1.print();

    Node* temp = l1.getMiddleNode(10);
 
    // call solution function here
    l1.removeMiddleNode(temp);

    l1.print();
    

    return 0;
}