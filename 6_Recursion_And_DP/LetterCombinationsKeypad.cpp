#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        // set values in keypad
        keypad['2'] = "abc";
        keypad['3'] = "def";
        keypad['4'] = "ghi";
        keypad['5'] = "jkl";
        keypad['6'] = "mno";
        keypad['7'] = "pqrs";
        keypad['8'] = "tuv";
        keypad['9'] = "wxyz";
    }
    
    void func(string digits, string s) {
        if(s.length() == digits.length()) {
            result.push_back(s);
            return;
        }
        
        // traverse through the characters of the digits[s.length()]
        for(char c : keypad[digits[s.length()]]) {
            string tmp = s + c;
            func(digits, tmp);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return result;
        func(digits, "");
        return result;
    }
private:
    unordered_map<char,string> keypad;
    vector<string> result;
};