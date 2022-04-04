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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = nullptr,* n2 = nullptr;
        
        
        for(auto p = head; p != nullptr; p = p->next) {
            
            // move n2 if its not nullptr
            n2 = (n2 == nullptr ? nullptr : n2->next);
            
            // Go till kth node, store it in n1
            k--;
            if(k == 0) {
                n1 = p;
                // start n2 from head, now till p reaches end of linked list,
                // n2 will move (list.size() - k) positions, so kth from end
                n2 = head;
            }
        }
        
        swap(n1->val, n2->val);
        
        return head;
    }
};