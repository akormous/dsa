#include<bits/stdc++.h>
using namespace std;
/*
Given k sorted linked lists,
merge them into 1 sorted linked list
*/

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
struct CompareVal {
    bool operator()(ListNode* a, ListNode* b) {
        return (a->val < b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // implement a min heap to store the smallest element among all the heads of k linked lists
        priority_queue<ListNode*, vector<ListNode*>, CompareVal> minHeap;

        int k = lists.size();
        // store all the heads in the min heap
        for(auto head : lists) {
            if(head != nullptr)
                minHeap.push(head);
        }

        // create a new linked list
        ListNode* result = new ListNode(-1);
        ListNode* cur = result;
        while(!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            cur->next = new ListNode(smallest->val);
            cur = cur->next;

            if(smallest->next != nullptr)
                minHeap.push(smallest->next);
        }
        return result->next;
    }
};