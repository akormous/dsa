#include<bits/stdc++.h>
using namespace std;

/*
Question - 
String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).

Inferences -
1. characters can be uppercase or lowercase, so should be treated seperately
2. a new string will be formed for sure
   the length of this new string will be inversely proportional to the number of repeated characters
3. if the new string is longer than the original string, then return the original string


Approach - 
1. traverse the original string and keep count of each character
2. when the current character becomes unequal to the previous character, start counter again
3. whenever the new string becomes lengthy than the original string, then return the original string

aaavvvvccccxxaa

prev = a
a

*/

string compressString(string s) {
    if(s.length() < 2)
        return s;
    
    string result = "";
    // store the first character
    result += s[0];
    char prev = s[0];
    int count = 1;
    // start traversing from the second character
    int i = 1;
    while(i < s.length()) {
        char cur = s[i];
        if(cur != prev) {
            result = result + to_string(count) + cur;
            // restart cout
            count = 1;
            // update the prev character
            prev = cur;
        }
        // matching characters
        else {
            // increase the count
            count++;
        }
        i++;
    }
    result += to_string(count);

    return (result.length() < s.length() ? result : s);
}

int main() {
    // solution
    string s = "AAAAAaaaaaBBBBccccXXXXXdddddXXXXXXXXXXXeEeEeEe";
    cout<<s<<endl;
    cout<<compressString(s)<<endl;
    return 0;
}