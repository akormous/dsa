// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
/*

Question: Segregate even and odd nodes in a linked list, without creating any new linked list
Approach:

Create 4 pointers

evenStart, evenEnd
oddStart, oddEnd

And then simply traverse the linked list and add the nodes to the corresponding linked list

*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* evenStart = NULL;
        Node* evenEnd = NULL;

        Node* oddStart = NULL;
        Node* oddEnd = NULL;

        Node* cur = head;

        while(cur != NULL) {
            // if the cur node is even
            if(cur -> data % 2 == 0) {
                // if the even list is empty
                if(evenStart == NULL) {
                    evenStart = cur;
                    evenEnd = cur;
                }
                // else if there is already something in the even list
                else {
                    evenEnd -> next = cur;
                    evenEnd = evenEnd -> next;
                }
            }
            // else if the cur node is odd
            else {
                // if the odd list is empty
                if(oddStart == NULL) {
                    oddStart = cur;
                    oddEnd = cur;
                }
                // else if there is already something in the odd list
                else {
                    oddEnd -> next = cur;
                    oddEnd = oddEnd -> next;
                }
            }
            cur = cur -> next;
        }
        // if there were no changes made
        if(evenStart == NULL || oddStart == NULL)
            return head;
        
        // else connect the even list and odd list
        evenEnd -> next = oddStart;
        oddEnd -> next = NULL;
        head = evenStart;
        return head;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends