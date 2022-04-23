#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution() {
        prefix = "http://tinyurl.com/";
        charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    }
    // generates a random string of length 6
    string generateCode() {
        string result = "";
        for(int i = 0; i < 6; i++) {
            result += charSet[ rand() % charSet.size() ];
        }
        return result;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while( url2code.find(longUrl) == url2code.end() ) {
            string code = generateCode();
            if( code2url.find(code) == code2url.end() ) {
                url2code[longUrl] = code;
                code2url[code] = longUrl;
            }
        }
        return prefix + url2code[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string code = shortUrl.substr(prefix.size(), 6);
        return code2url[code];
    }
private:
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;
    string prefix;
    string charSet;
};