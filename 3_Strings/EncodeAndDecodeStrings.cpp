#include<bits/stdc++.h>
using namespace std;

/*
Store the length of the string at the beginning, and add a delimiter after this length number

for example {"leet", "code"} => 4#leet4#code
Reverse the operation to perform decoding
*/

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string payload = "";
        for(string& s : strs) {
            int l = s.length();
            payload += to_string(l) + '#' + s;
        }
        return payload;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> result;
        int n = str.length();
        int i = 0;
        while(i < n) {
            int len = readLength(str, i);
            i++;
            string cur = str.substr(i, len);
            result.push_back(cur);
            i +=len;
        }
        return result;
    }

    int readLength(string &str, int &pos) {
        string len = "";
        while(str[pos] != '#') {
            len += str[pos];
            pos++;
        }
        return stoi(len);
    }
};

bool check(vector<string>& in, vector<string>& out) {
    if(in.size() != out.size())
        return false;
    
    for(int i = 0; i < in.size(); ++i) {
        if(in[i] != out[i])
            return false;
    }
    return true;
}

int main() {
    Solution s;
    vector<string> input = {"leet","code","i#s","quit24617824e","funnnnasdfasdfq23447rfyad###$$$@$!4@&^&*$^(sf"};

    string payload = s.encode(input);
    vector<string> output = s.decode(payload);

    if(!check(input, output)) {
        cout << "TEST FAILED" << endl;
    }
    else {
        cout << "TEST PASSED" << endl;
    }
    return 0;
}