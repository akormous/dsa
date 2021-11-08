#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // returns true if all the frequencies are 0
    bool isZero(vector<int> freq) {
        for(int i = 0; i < freq.size(); ++i) {
            if(freq[i] != 0)
                return false;
        }
        return true;
    }
    // used in debugging
    void display(vector<int> arr) {
        for(auto i : arr)
            cout<<i<<" ";
        cout<<endl;
    }
    bool checkInclusion(string s1, string s2) {
        // an array of size 26, keeping track of frequencies of each letter
        vector<int> freq(26, 0);
        
        // frequencies of letters in s1
        for(auto i : s1) {
            freq[i - 'a']++;
        }
        //display(freq);

        // length of the window
        int n = s1.length();
        
        // decrement frequencies of first window
        for(int i = 0; i < n; ++i) {
            freq[s2[i] - 'a']--;
        }
        //display(freq);

        // sliding window
        for(int i = n; i < s2.length(); i++) {
            // check if all freq are 0
            if(isZero(freq))
                return true;

            //display(freq);

            // shift the window by 1
            freq[ s2[i - n] - 'a' ]++;
            freq[ s2[i] - 'a' ]--;
        }
        if(isZero(freq))
            return true;
        return false;
    }
};

int main() {
    Solution s;

    cout<<s.checkInclusion("ab", "eidbaoooo")<<endl;
    return 0;
}