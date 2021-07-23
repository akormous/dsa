#include<bits/stdc++.h>
using namespace std;

/*
SINGLY LINKED LIST- each node points to next node
TIME COMPLEXITY- 
        Access - O(n)
        Search - O(n)
        Insertion - O(1)
        Deletion  - O(1)
SPACE COMPLEXITY- O(n)
*/

// simple structure of a Node in a linked list
struct Node {
    int val;
    struct Node* next;
};

// defining a class LinkedList where all the functionalities will be defined
class LinkedList {
    Node* head; // reference to the head of the linked list
    Node* tail; // reference to the tail of the linked list
    int size;   // number of elements in the linked list
    public:
    // default constructor
    LinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    // insertion at front of the linked list
    void insert(int val) {
        // creating a new node with the provided value
        Node* temp = new Node;
        temp->val = val;
        // if there are no elements in the list
        if(head == NULL) {
            temp->next = nullptr;
            tail = temp;
        } 
        // else add it to the front
        else {
            temp->next = head;
        }
        head = temp;
    }
    // delete the node with given value
    void deleteNode(int val) {
        Node* cur = head;
        // if head is to be deleted
        if(cur->val == val) {
            head = head->next;
            delete(cur);
            return;
        }
        // search for the value
        while(cur->next != nullptr) {
            if(cur->next->val == val) {
                Node* tmp = cur->next;
                cur->next = tmp->next;
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
            cout<<cur->val<<" ";
            cur = cur->next;
        }
    }

};


int main() {
    // declaring a linked list object
    LinkedList ll;
    // a sample array to feed values in the linked lst
    vector<int> arr = {4, 4, 23, 667, 42, 89, -123, 65236, 7637, 8547, 0};
    for(int i = 0; i < arr.size(); i++)
        ll.insert(arr[i]);
    
    cout<<"Before deleting"<<endl;
    ll.traverseLL();
    int num_to_delete = 667;
    ll.deleteNode(num_to_delete);
    cout<<endl<<"After deleting"<<endl;
    ll.traverseLL();
    return 0;
}