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
    
    ListNode* getNextUniqueNode(ListNode* cur) {
        
        
        while(cur != nullptr && cur->next != nullptr
             && cur->val == cur->next->val) {

            cur = cur->next;

        }
        return cur->next;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* init = new ListNode(0);
        init->next = head;
        
        ListNode* prev = init;
        ListNode* cur = head;
        
        
        while(cur != nullptr && cur->next != nullptr) {
            
            if(cur->val == cur->next->val) {
                cur = getNextUniqueNode(cur);
                prev->next = cur;
            } 
            else {
                
                cur = cur->next;
                prev = prev->next;
            }
            
        }
        
        return init->next;
    }
};