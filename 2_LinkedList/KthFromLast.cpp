#include<bits/stdc++.h>
using namespace std;

/*

Question: 
Return the Kth Node to last in a Linked List

Approach:
Naive approach is to first find the length of the linked list
and then traverse again to return Kth to last element

Recursive approach -
Recurse the linked list till it reaches the end
When it hits the end, the method passes back a counter value
Each parent call increases the count by 1
When it reaches k, return the node

The counter value can be passed by reference so it doesn't change its value of each recursive call

Time Complexity - O(n)
Space Complexity - O(n)


If you solve it in iterative way, space complexity = O(1)
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

    // Kth to last
    // i is references so it doesn't copy its value of every recursive call
    Node* solve(Node* head, int k, int& i ) {
        // when the head hits the end of the linked list
        // return 0
        if(head == nullptr)
            return nullptr;

        // recursive call
        Node* tmp = solve(head -> next, k, i);

        // Fun fact -  this tmp node will always be nullptr
        /*
        if(tmp == nullptr)
            cout<<"nullptr"<<endl;
        */

        // increment i
        i = i + 1;
        // when i equals k, return the node
        if(i == k)
            return head;
        // simple return the node if it is not the kth node from last
        return tmp;

    }
    Node* kthToLast(int k) {
        // if there is nothing in the linked list
        if(head == nullptr)
            return nullptr;
        int i = 0;
        Node* kthNodeFromLast = solve(head, k, i);

        return kthNodeFromLast;
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
    // call solution function here
    Node* k = l1.kthToLast(11);


    cout<<k -> data<<endl;

    l1.print();
    

    return 0;
}