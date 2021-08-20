#include<bits/stdc++.h>
using namespace std;

/*

Question: Check if a linked list is palindrome or not


Approach - 

Using recursion, I will reach the end of the linked list
From that point when backtracking, compare the head and runner data
If they are equal, move the head pointer to the next node
the position of the runner pointer will be taken care by recursion

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

    // check if a linked list is palindrome
    void compareReverse(Node*& head, Node* runner, bool& flag) {
        // if any mismatch occurred earlier
        // if head reaches end
        // if runner reaches end
        if(flag == false || head == nullptr || runner == nullptr)
            return;

        compareReverse(head, runner -> next, flag);

        if(head -> data != runner -> data) {
            flag = false;
        }
        // move head to next for comparing
        head = head -> next;
    }

    bool isPalindrome() {
        // make a copy of the head pointer so that it doesn't get lost
        Node* headCopy = new Node;
        headCopy -> data = head -> data;
        headCopy -> next = head -> next;
        // a flag denoting equality of linked list with its reverse
        // assuming the linked list is palindrome
        bool flag = true;

        // compare the linked list with its reverse
        compareReverse(headCopy, head, flag);

        return flag;

    }
    

};

int main() {
    LinkedList l1;
    // inserted random numbers in the linked list
    l1.insert(1);
    l1.insert(3);
    l1.insert(4);
    l1.insert(4);
    l1.insert(3);
    l1.insert(1);
    l1.print();
    // call solution function here
    if(l1.isPalindrome()) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    l1.print();
    

    return 0;
}