#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Solution
{
    public:
    //Function to reverse a linked list.
    Node* reverseHead = NULL;
    void reverseUtil(struct Node* head, struct Node* prev) {
        if(head == NULL) {
            reverseHead = prev;
            return;
        }
        reverseUtil(head->next, head);
        head->next = prev;
    }
    struct Node* reverseList(struct Node *head)
    {
        reverseUtil(head, NULL);
        return reverseHead;
    }
    
};