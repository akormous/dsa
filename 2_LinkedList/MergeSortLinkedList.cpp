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
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*

Do a merge sort on a linked list.

Key points:
1. For finding the middle node, do slow-fast pointer approach

*/

class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2) {
        // create an empty linked list
        ListNode* cur = new ListNode(0);
        ListNode* head = cur;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if(l1) {
            cur->next = l1;
        }
        if(l2) {
            cur->next = l2;
        }
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        // base cases
        if(head == nullptr || head->next == nullptr)
            return head;

        // get to the middle node in the linked list
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // middle node
        ListNode* mid = slow->next;

        // break the linked list
        slow->next = nullptr;

        return merge(sortList(head), sortList(mid));

    }
};