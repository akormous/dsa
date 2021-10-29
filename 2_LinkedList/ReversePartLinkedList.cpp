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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;
        // go to the node where left part ends
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur;
        for(int i = 0; i < left - 1; i++) {
            pre = pre -> next;
        }
        cur = pre->next;
        //cout<<cur->val;
        
        // go to the start of right part
        ListNode* post = cur;
        for(int i = 0; i <= right - left; i++) {
            post = post->next;
        }
        
        // reverse the list between pre and post
        ListNode* midStart = cur;
        ListNode* prev = cur;
        cur = cur->next;
        for(int i = 0; i < right-left; ++i) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        pre -> next = prev;
        midStart -> next = post;
    
        return dummy->next;
        
    }
};