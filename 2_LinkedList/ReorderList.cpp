#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return ;
        
        // find the middle node
        ListNode* p1 = head, *p2 = head;
        while(p2->next != nullptr && p2->next->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;            
        }
    
        // reverse the linked list after the middle node
        ListNode* preMid = p1;
        ListNode* preCur = p1->next;
        while(preCur->next != nullptr) {
            ListNode* cur = preCur->next;
            preCur->next = cur->next;
            cur->next = preMid->next;
            preMid->next = cur;
        }
                
        // reorder the ll
        p1 = head;
        p2 = preMid->next;
        while(p1 != preMid) {
            preMid->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMid->next;
            
        }
    }
};