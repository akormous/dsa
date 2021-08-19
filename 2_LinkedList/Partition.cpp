#include<bits/stdc++.h>
using namespace std;

/*
Question -
Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.

EXAMPLE
Input:
Output:
3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5]
3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

*/

/*

Brute force - 
O(n ^ 2)

Cur and runner approach - the runner will look for a position where the cur node can be placed

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

    // partition linked list
    void partition(int p) {
        Node* cur = head;
        // find a node which should be in the right partition but it is not
        while(cur != nullptr) {
            if(cur -> data >= p) {
                // look for a node which can be replaced
                Node* temp = cur;

                while(temp != nullptr && temp -> data >= p) {
                    temp = temp -> next;
                }
                // if temp reaches the end, put the node at the end of the linked list
                if(temp == nullptr)
                    return;
                // swap the data of cur and the replaceable node
                swap(cur -> data, temp -> data);   
            }
            cur = cur -> next;
        }

    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LinkedList l1;
    // inserted random numbers in the linked list
    l1.insert(1);
    l1.insert(23);
    l1.insert(3);
    l1.insert(4);
    l1.insert(59);
    l1.insert(6);
    l1.insert(7);
    l1.insert(82);
    l1.insert(9);
    l1.insert(10);
    l1.insert(11);
    l1.print();
    // call solution function here
    l1.partition(20);

    l1.print();
    

    return 0;
}