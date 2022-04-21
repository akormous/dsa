#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    2 Way BFS, start BFS from begin and end
    */
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> head, tail, *phead, *ptail;
        
        if(dict.find(end) == dict.end())
            return 0;
        
        head.insert(begin);
        tail.insert(end);
        
        int distance = 2;
        
        while(!head.empty() && !tail.empty()) {
            if(head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail;
                ptail = &head;
            }
            
            unordered_set<string> nextLayer;
            
            for(auto it = phead->begin(); it != phead->end(); ++it) {
                string word = *it;
                dict.erase(word);
                for(int i = 0; i < word.size(); i++) {
                    char n = word[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if(ptail->find(word) != ptail->end())
                            return distance;
                        if(dict.find(word) != dict.end()) {
                            nextLayer.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = n;
                }
            }
            
            phead->swap(nextLayer);
            distance++;
        }
        return 0;
    }
};