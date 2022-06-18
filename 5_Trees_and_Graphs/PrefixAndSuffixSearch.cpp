#include<bits/stdc++.h>
using namespace std;

#define ALPHABET 27
struct Node {
    Node* children[27]; // choosing the delimiter as '{', 
                        // why ? because the ASCII code of '{' is 'z'+1, so 'a' + 26 = '{'
    int idx;    // stores the index of the word in the array
    Node() {    // constructor
        for(int i = 0; i < ALPHABET; ++i)
            children[i] = nullptr;
        idx = 0;
    }
};
class WordFilter {
    Node* root; // trie root node
public:
    WordFilter(vector<string>& words) {
        root = new Node();
        // example: if word is "apple", then store
        // "{apple", "e{apple", "le{apple", "ple{apple", "pple{apple", "apple{apple"
        
        // generic formula = suffix + '{' + prefix
        
        for(int i = 0; i < words.size(); i++) {
            string word = '{' + words[i];
            insert(root, i, word);
            for(int j = 0; j < word.size(); j++) {
                string tmp = word.substr(j+1) + word;
                insert(root, i, tmp);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string word = suffix + '{' + prefix;    // create the key = suffix + '{' + prefix
        Node* crawler = root;
        for(char& c : word) {
            if(crawler->children[c-'a'] == nullptr)
                return -1;
            crawler = crawler->children[c-'a'];
        }
        return crawler->idx;    // if found return the index that we stored
    }
    
    void insert(Node* root, int idx, string& word) {
        Node* crawler = root;
        for(char& c : word) {
            if(crawler->children[c-'a'] == nullptr)
                crawler->children[c-'a'] = new Node();
            crawler = crawler->children[c-'a'];
            crawler->idx = idx;
        }
    }    
};

/**
* Your WordFilter object will be instantiated and called as such:
* WordFilter* obj = new WordFilter(words);
* int param_1 = obj->f(prefix,suffix);
*/