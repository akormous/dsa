#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        // if s is empty
        if(s.length() == 0 || p.length() == 0)  return result;

        // create a freq arr for p
        vector<int> charCounts(26, 0);
        for(auto c : p)
            charCounts[c - 'a']++;
        
        // sliding window approach
        int left = 0;
        int right = 0;

        // decrement this count when a character is found in a window and as well as p
        int count = p.length();

        while(right < s.length()) {
            // if the char at right pointer is found in p, then decrement the count
            if(charCounts[s.at(right) - 'a'] >= 1)
                count--;
            
            // decrement the freq at the right pointer
            charCounts[s.at(right) - 'a']--;
            // move right pointer
            right++;

            // if count reaches 0, then store the left pointer in the result
            if(count == 0) 
                result.push_back(left);

            // if the sliding window reaches the size of p
            if(right - left == p.length()) {
                
                // if the char at left was in p, then increment the count
                if( charCounts[s.at(left) - 'a'] >= 0 )
                    count++;
                
                // increment the freq for char at s[left]
                charCounts[s.at(left) - 'a']++;

                // move left pointer
                left++;
            }
        }
        return result;
    }
};

void printArr(vector<int> v) {
    for(auto i : v)
        cout << i<<" ";
}

int main() {
    // solution
    Solution s;

    printArr(s.findAnagrams("ababab", "ab"));
    return 0;
}