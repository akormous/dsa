#include<bits/stdc++.h>
using namespace std;

// the alphabet size for which the trie is to be created
#define ALPHABET_SIZE 26

/*

Trie n-ary tree
-used to store words
-running time tradeoff with space


*/

class TrieNode {
    public:
    // an array of references
    TrieNode* children[ALPHABET_SIZE];
    // a flag representing if the current node is end of a word
    bool isEOW;

    // default constructor
    TrieNode() {
        // all children are nullptr initially
        for(int i = 0; i < ALPHABET_SIZE; ++i)
            children[i] = nullptr;
        isEOW = false;
    }
};

// a class implementing all function on a Trie such as insert, delete, search
class Trie {
    private:
    TrieNode* root;
    public:

    Trie() {
        root = new TrieNode();
    }

    // insert a word in the trie
    void insert(string w) {
        TrieNode* crawler = root;

        // traverse every character in the string
        for(int i = 0; i < w.length(); ++i) {

            // get the index
            int key = w[i] - 'a';

            // if the child node of that char is nullptr, then create a new TrieNode there
            if(crawler -> children[key] == nullptr)
                crawler -> children[key] = new TrieNode();
            
            // go to that node
            crawler = crawler -> children[key];
        }

        // flag the end of word
        crawler -> isEOW = true;
    }
    // search for a word in trie
    bool search(string w) {
        TrieNode* crawler = root;

        // traverse each character in the string
        for(int i = 0; i < w.length(); ++i) {
            // get the index
            int key = w[i] - 'a';
            // if the child node for that char is nullptr, then return false
            if(crawler -> children[key] == nullptr)
                return false;
            
            // else move to the child node
            crawler = crawler -> children[key];
        }

        // if it is an end of word, then true, else false
        return (crawler -> isEOW);
    }

    // print all words in the trie
    void printAll() {
        
        cout<<endl;
    }
};


int main() {
    // create a Trie data structure
    Trie* t1 = new Trie();

    t1 -> insert("apple");
    t1 -> insert("banana");
    t1 -> insert("car");
    t1 -> insert("carrot");
    t1 -> insert("dog");
    t1 -> insert("food");
    t1 -> insert("dogfood");
    t1 -> insert("eat");
    t1 -> insert("fudge");
    cout<<"Enter a word to search"<<endl;
    string s;
    cin>>s;
    cout<<"Searching "<<s<<endl;
    cout<<t1 -> search(s)<<endl;


    t1 -> printAll();    

    return 0;
}