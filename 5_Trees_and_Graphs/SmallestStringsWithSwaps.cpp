#include<bits/stdc++.h>
using namespace std;

/*
Return the lexicographically smallest string that s can be changed to after using the swaps.
*/

class Solution {
public:
    vector<int> sz;
    vector<int> id;
    // returns the root of 'p'
    int find(int p) {
        int root = id[p];
        while(root != id[root])
            root = id[root];
        
        // compress path
        while(p != root) {
            int next = id[p];
            id[p] = root;
            p = next;
        }
        return root;
    }

    // unifies the sets containing 'p' and 'q'
    void unify(int p, int q) {
        int root1 = find(p);
        int root2 = find(q);
        if(root1 == root2)  return;

        if(sz[root1] > sz[root2]) {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        else {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size = s.length();
        sz.resize(size);
        id.resize(size);
        for(int i = 0; i < size; i++) {
            sz[i] = 1;
            id[i] = i;  // initially all nodes are root
        }

        // create sets
        for(auto& pair : pairs) {
            unify( find(pair[0]), find(pair[1]) );
        }
        // create collection of sets
        vector<vector<int>> sets(size);
        for(int i = 0; i < size; i++) {
            sets[ find(i) ].push_back(i);
        }
        // create strings using the sets
        for(auto& set : sets) {
            string temp = "";
            for(auto idx : set) {
                temp += s[idx];
            }
            sort(temp.begin(), temp.end());
            // modify the original string
            for(int i = 0; i < set.size(); i++) {
                s[set[i]] = temp[i];
            }
        }
        return s;
    }
};