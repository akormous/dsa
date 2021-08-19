#include<bits/stdc++.h>
using namespace std;

/*
Question -
Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
EXAMPLE

Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.

Output: 2 -> 1 -> 9. That is, 912.

FOLLOW UP

Suppose the digits are stored in forward order. Repeat the above problem.

EXAMPLE

lnput:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.

Output: 9 - > 1 -> 2. That is, 912.


*/
/*

NOTE: This file contains both solutions

*/

struct Node{
    int data;
    Node* next;
};

class LinkedList {
    public:
    Node* head;
    
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
    // reverse the linked list
    void reverse() {
        if(head == nullptr)
            return;

        Node* cur = head;
        Node* prev = nullptr;

        while(cur != nullptr) {
            Node* true_next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = true_next;            
        }
        head = prev;
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


// reverse sum - assuming the numbers are stored in reverse order
// a recursive approach
Node* addLists(Node* n1, Node* n2, int carry) {
    if(n1 == nullptr && n2 == nullptr && carry == 0)
        return nullptr;
    
    int sum = carry;
    if(n1 != nullptr)
        sum += n1 -> data;

    if(n2 != nullptr)
        sum += n2 -> data;

    Node* sumNode = new Node;
    sumNode -> data = sum % 10;

    sumNode -> next = addLists(
        (n1 == nullptr) ? nullptr : n1 -> next,
        (n2 == nullptr) ? nullptr : n2 -> next,
        (sum / 10) > 0 ? 1 : 0
    );
    return sumNode;
}

LinkedList sumIfReverseOrderRecursive(LinkedList l1, LinkedList l2) {
    LinkedList result;
    result.head = addLists(l1.head, l2.head, 0);
    return result;
}

// reverse sum - assuming the numbers are stored in reverse order
LinkedList sumIfReverseOrder(LinkedList l1, LinkedList l2) {
    LinkedList result;
    // similar to adding large numbers using array
    // so basically keep track of carry
    bool carry = false;

    Node* c1 = l1.head;
    Node* c2 = l2.head;
    while(c1 != nullptr && c2 != nullptr) {
        // add the digits
        int sum = (c1 -> data) + (c2 -> data);
        // if there was prev carry
        if(carry) {
            sum = sum + 1;
        }
        // flush carry
        carry = false;
        // check for current carry
        if(sum / 10 != 0)
            carry = true;
        result.insert(sum % 10);

        c1 = c1 -> next;
        c2 = c2 -> next;
    }
    // insert all the remaining digits if any
    while(c1 != nullptr) {
        int sum = c1 -> data;
        if(carry)
            sum = sum + 1;
        // flush carry
        carry = false;
        result.insert(sum % 10);

        // check for current carry
        if(sum / 10 != 0)
            carry = true;
        c1 = c1 -> next;
    }
    while(c2 != nullptr) {
        int sum = c2 -> data;
        if(carry)
            sum = sum + 1;
        // flush carry
        carry = false;
        result.insert(sum % 10);
        
        // check for current carry
        if(sum / 10 != 0)
            carry = true;

        c2 = c2 -> next;
    }
    if(carry)
        result.insert(1);

    return result;
}


// forward sum - assuming the numbers are stored in order
LinkedList sumIfNormalOrder(LinkedList l1, LinkedList l2) {
    l1.reverse();
    l2.reverse();
    return sumIfReverseOrderRecursive(l1, l2);
}



int main() {
    LinkedList l1, l2;
    // if stored in reverse order
    // 543 + 9378
    l1.insert(5);   l1.insert(4); l1.insert(3); 

    l2.insert(9);   l2.insert(3); l2.insert(7); l2.insert(8);

    l1.print();
    l2.print();

    sumIfReverseOrderRecursive(l1, l2).print();

    cout<<endl<<endl;
    l1.reverse();
    l2.reverse();
    l1.print();
    l2.print();

    sumIfNormalOrder(l1, l2).print();

    return 0;
}