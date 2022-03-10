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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        int carry = 0;
        
        while(p1->next != nullptr && p2->next != nullptr) {
            int sum = p1->val + p2->val + carry;
            
            p2->val = sum%10;
            
            carry = sum/10;
            
            p1 = p1->next;
            p2 = p2->next;
        }
                    
        int sum = p1->val + p2->val + carry;
        p2->val = sum%10;
        carry = sum/10;
        
        if(p2->next == nullptr) {
                
            if(p1->next == nullptr && carry != 0) {
                p2->next = new ListNode(0);
            }
            else {
                p2->next = p1->next;
            }            
        }
        p2 = p2->next;

            
        while(p2 != nullptr) {
            int sum = p2->val + carry;
            
            p2->val = sum%10;
            carry = sum/10;
            if(p2->next == nullptr && carry) {
                p2->next = new ListNode(0);
            }
            p2 = p2->next;
        }
        
        
        
        return l2;
    }
};