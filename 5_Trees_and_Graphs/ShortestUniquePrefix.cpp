#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define ALPHABET 26
struct Node {
    Node* children[ALPHABET];
    bool isEOW;
    int freq;
    Node() {
        for(int i = 0; i < ALPHABET; i++)   children[i] = nullptr;
        isEOW = false;
        freq = 0;
    }
};

void insert(Node* root, string& s) {
    Node* crawler = root;
    for(char& c : s) {
        if(crawler->children[c - 'a'] == nullptr)
            crawler->children[c - 'a'] = new Node();
        crawler = crawler->children[c - 'a'];
        (crawler->freq)++;
    }
    crawler->isEOW = true;
}

string getPrefix(Node* root, string& s) {
    string prefix = "";
    prefix += s[0];
    Node* crawler = root->children[s[0] - 'a'];

    // add the characters until the crawler has only one child
    for(int i = 1; i < s.size(); ++i) {
        // if the frequency of current node is 1, then return prefix
        if(crawler->freq == 1)
            break;
        prefix += s[i];
        crawler = crawler->children[s[i] - 'a'];
    }
    return prefix;
}

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        // create a trie with the words in arr
        
        Node* root = new Node();
        
        for(int i = 0; i < n; i++)
            insert(root, arr[i]);
        
        vector<string> result(n, "");
        
        for(int i = 0; i < n; i++) {
            result[i] = getPrefix(root, arr[i]);
        }
        return result;
        
    }
    
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends