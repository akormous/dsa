// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*

Question: Find the intersecting point in two singly linked lists

*/

/*
EASY CLEAN
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a != b) {
            a = (a == nullptr ? headB : a->next);
            b = (b == nullptr ? headA : b->next);
        }
        return a;
    }
};

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    // find the lengths of the linked lists
    Node* cur1 = head1;
    int len1 = 0;
    
    Node* cur2 = head2;
    int len2 = 0;
    
    while(cur1 != NULL) {
        len1++;
        cur1 = cur1 -> next;
    }
    
    while(cur2 != NULL) {
        len2++;
        cur2 = cur2 -> next;
    }
    
    // capturing the head of longer ll
    Node* longer;
    Node* shorter;
    if(len1 > len2) {
        longer = head1;
        shorter = head2;
    }
    else {
        longer = head2;
        shorter = head1;
    }
    
    int diff = abs(len1 - len2);
    while(diff--) {
        longer = longer -> next;
    }
    
    while(longer != NULL && shorter != NULL) {
        if(longer == shorter)
            return longer -> data;
        longer = longer -> next;
        shorter = shorter -> next;
    }
    return -1;
}

