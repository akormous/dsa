#include<bits/stdc++.h>
using namespace std;

/*
TRIE question
*/
#define ALPHABET 26
struct Node {
    Node* children[ALPHABET];
    bool isEOW;
    Node() {
        for(int i = 0; i < ALPHABET; ++i)
            children[i] = nullptr;
        isEOW = false;
    }
};

class Solution {
private:
    Node* root; // trie root
    int result = 0; // result to be returned; length of shortest reference string
    
    // insert a word in the trie
    void insert(string& s) {
        Node* crawler = root;
        for(char& c : s) {
            if(crawler->children[c-'a'] == nullptr)
                crawler->children[c-'a'] = new Node();
            crawler = crawler->children[c-'a'];
        }
        crawler->isEOW = true;
    }
    
    bool isLeaf(Node* node) {
        for(int i = 0; i < ALPHABET; ++i)
            if(node->children[i] != nullptr)
                return false;
        return true;
    }
    
    void dfs(Node* root, int depth) {
        if(isLeaf(root)) {
            result += depth+1;
            return;
        }
        
        for(int i = 0; i < ALPHABET; i++) {
            if(root->children[i] != nullptr)
                dfs(root->children[i], depth+1);
        }
    }
public:
    Solution() {
        root = new Node();
    }
    int minimumLengthEncoding(vector<string>& words) {
        // insert all reverse words in trie
        for(string w : words) {
            reverse(w.begin(), w.end());
            insert(w);
        }
        // calculate sum of depths of all leaf nodes
        dfs(root, 0);
        return result;
    }
};