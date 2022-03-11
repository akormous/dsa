#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0)
            return head;
        
        // number of nodes
        int n = 0;
        ListNode* cur = head;
        ListNode* prev;
        
        while(cur != nullptr) {
            n++;
            prev = cur;
            cur = cur->next;
        }
        cout << k <<endl;
        cout << n <<endl;
        if(n == 1)
            return head;
        
        k = k%n;
        
        if(k == 0)
            return head;
        
        prev->next = head;
        
        int m = n-k;
        
        cur = head;
        
        while(m != 0) {
            prev = cur;
            cur = cur->next;
            m--;
        }
        
        prev->next = nullptr;
        return cur;
        
    }
};