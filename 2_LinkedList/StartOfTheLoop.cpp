#include<bits/stdc++.h>
using namespace std;
/*

Question: 
Detect if there is a loop in a linked list
If there is a loop, then return the first node in the loop

Approach:
(slow and fast pointers)

1. Detect and return the meeting point node ( m ) of slow and fast pointers
2. Move head and m, whenever they are equal, that will be the start of the loop in the linked list
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // function that will return the meeting point node of slow and fast pointers
    ListNode* findMeetingPoint(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL && slow != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
                return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* m = findMeetingPoint(head);
        if(m == NULL)
            return NULL;
        while(true) {
            if(head == m)
                return head;
            head = head -> next;
            m = m -> next;
        }
        return NULL;
    }
};




