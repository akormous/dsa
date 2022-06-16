#include<bits/stdc++.h>
using namespace std;

// Node for each resource
struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int iKey, int iVal) : key(iKey), val(iVal), next(nullptr), prev(nullptr) {}
};
/*
Summary-
A cache of fixed size is represented by a map (key -> resource)
Each resource is represented by a Node in a double linked list

Why double linked list?
We will keep 2 nodes (head and tail),
where head will point at the resource which is MOST FREQUENTLY USED
and tail will point at the resource which is LEAST FREQUENTLY USED
Now consider two functions - 
1. insert at the most frequent end of the linked list 
2. and remove from the least frequent end of the linked list

Using these two functions we can achieve everything that we need to maintain a LRU Cache.

Imagine a situation where a request for reading a resource comes and that resource is present in the cache-
Since cache(map) has pointer to every node, now if a request for reading a node comes to the system,
we can directly reach the node using our map, and remove it from the linked list and then add it to the most frequent end of the linked list.

Similarly deletion and addition.

*/
class LRUCache {
    int capacity;
    Node* left;     // points to the least recently used node
    Node* right;    // points to the most recently used node
    unordered_map<int, Node*> cache;   // maps key to a pointer to Node (Node*)
    void display() {    // for debugging: prints the linked list from left to right
        Node* cur = left;
        while(cur != nullptr) {
            cout << cur->key << " <-->" << " ";
            cur = cur->next;
        }
        cout << endl;
    }
public:
    LRUCache(int iCapacity) {
        capacity = iCapacity;
        // create dummy nodes at the extreme ends of the linked list
        left = new Node(-1, -1); right = new Node(-1, -1);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        // if cache has the key
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if this key is already present in the cache
        if(cache.find(key) != cache.end())
            remove(cache[key]); // remove the node
        cache[key] = new Node(key, value);  // create a new node with key and value and put it in cache
        insert(cache[key]); // insert the node in the linked list
        
        // if the cache size exceeds capacity
        if(cache.size() > capacity) {
            Node* lruNode = left->next; // this is the node next to left, hence LRU
            remove(lruNode);    // remove this node from the linked list
            cache.erase(lruNode->key);  // erase the node from the cache as well
        }
    }
    
    // helper functions for inserting and removing a node from the double linked list
    // insertion will only happen at the most frequent side
    void insert(Node* node) {
        Node* prevNode = right->prev;
        Node* nextNode = right;
        prevNode->next = node;
        nextNode->prev = node;
        node->prev = prevNode;
        node->next = nextNode;
        
    }
    // remove a given node from the linked list
    void remove(Node* node) {
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */