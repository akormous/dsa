#include<bits/stdc++.h>
using namespace std;

/*

Question - 
Remove duplicates from an unsorted linked list.

Keep track of the numbers using a hash set

If temp buffer is not  allowed, what will be the approach ?

O(n ^ 2)


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
    // insert at front of the linked list
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
    // delete the first occurence a node with given data
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

    // remove duplicates from a linked list
    void removeDuplicates() {
        // hash set to keep track of the numbers
        unordered_set<int> hashSet;
        // traverse the linked list and check if the number is already there in the set
        Node* cur = head;
        Node* prev = nullptr;
        while(cur != nullptr) {
            // if the data is present in the hashSet
            if(hashSet.find(cur -> data) != hashSet.end()) {
                // skip this Node in ll and delete it
                prev -> next = cur -> next;
                delete cur;
            }
            else {
                // insert the data in the hashSet
                // set prev = cur
                hashSet.insert(cur -> data);
                prev = cur;
            }
            cur = prev -> next;
        }
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

};

int main() {
    // solution
    LinkedList l1;
    l1.insert(1);
    l1.insert(1);
    l1.insert(1);
    l1.insert(2);
    l1.insert(1);
    l1.insert(1);
    l1.insert(3);
    l1.insert(1);
    l1.insert(1);
    l1.insert(4);
    l1.insert(5);
    l1.print();
    l1.removeDuplicates();
    l1.print();
    return 0;
}