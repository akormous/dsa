#include<bits/stdc++.h>
using namespace std;

/*
DOUBLY LINKED LIST- every node has a pointer to its previous and next node
                    advantage - reverse traversal from  anywhere in the list
TIME COMPLEXITY- 
        Access - O(n)
        Search - O(n)
        Insertion - O(1)
        Deletion  - O(1)
SPACE COMPLEXITY- O(n)
*/

// simple structure of a Node in a doubly linked list
struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

// defining a class LinkedList where all the functionalities will be defined
class DoublyLinkedList {
    Node* head; // reference to the head of the linked list
    Node* tail; // reference to the tail of the linked list
    int size;   // number of elements in the linked list
    public:
    // default constructor
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // insertion at front of the linked list
    void insert(int val) {
        // creating a new node with the provided value
        Node* temp = new Node;
        temp->val = val;
        temp->prev = nullptr;
        // if there are no elements in the list
        if(head == NULL) {
            temp->next = nullptr;
            tail = temp;
        } 
        // else add it to the front
        else {
            temp->next = head;
            head->prev = temp;
        }
        head = temp;
    }
    // insert an element at a specific position
    // pos represents position in linked list
    void insertAfterPos(int val, int pos) {
        if(pos < 0) {
            cout<<"Invalid position"<<endl;
            return;
        }
        Node* temp = new Node;
        temp->val = val;
        if(head == NULL) {
            temp->next = nullptr;
            temp->prev = nullptr;
        }
        else {
            Node* cur = head;
            while(pos--) {
                if(cur == nullptr) {
                    cout<<"Linked list is not long enough!"<<endl;
                    return;
                }
                cur = cur->next;
            }
            temp->prev = cur->prev;
            temp->next = cur;
            if(cur->prev != nullptr)
                cur->prev->next = temp;
            cur->prev = temp;
        }
    }
    // delete the node with given value
    void deleteNode(int val) {
        Node* cur = head;
        // if head is to be deleted
        if(cur->val == val) {
            head = head->next;
            head->prev = nullptr;
            delete(cur);
            return;
        }
        // search for the value
        while(cur->next != nullptr) {
            if(cur->next->val == val) {
                Node* tmp = cur->next;
                cur->next = tmp->next;
                tmp->next->prev = cur;
                cout<<"Deleting node with value - "<<tmp->val<<endl;
                delete(tmp);
                return;
            }
            cur = cur->next;
        }
        // if value is not found
        cout<<"Value not found"<<endl;
    }


    // traverse the list and display values
    void traverseLL() {
        Node* cur = head;
        while(cur != nullptr) {
            cout<<cur->val<<" => ";
            cur = cur->next;
        }
        cout<<"nullptr"<<endl;
    }

    // reverse traversal the list from tail
    void reverseTraversal() {
        Node* cur_tail = tail;
        while(cur_tail != nullptr) {
            cout<<cur_tail->val<<" => ";
            cur_tail = cur_tail->prev;
        }
        cout<<"nullptr"<<endl;
    }

};


int main() {
    // declaring a linked list object
    DoublyLinkedList ll;
    // a sample array to feed values in the linked lst
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i < arr.size(); i++)
        ll.insert(arr[i]);
    
    cout<<"Before deleting"<<endl;
    ll.traverseLL();
    int num_to_delete = 667;
    ll.deleteNode(num_to_delete);
    cout<<endl<<"After deleting"<<endl;
    ll.traverseLL();
    cout<<endl;
    cout<<"Reverse traversal"<<endl;
    ll.reverseTraversal();
    cout<<endl;
    cout<<"Inserting a node after 4th position"<<endl;
    ll.insertAfterPos(-99, 4);
    ll.traverseLL();
    cout<<endl;
    return 0;
}