#include<bits/stdc++.h>
using namespace std;

/*

Question: Check if a string is permutation of another string

*/

// considering the string consisting of only ASCII characters
// so create an array of size 128 which will keep track of the frequency of each character in the string
// traverse the first string, add to the frequency array
// traverse the second string, subtract from the frequency array
// check if any element in the array is non-zero
bool isPermutation(string a, string b) {
    if(a.length() != b.length())
        return false;
    
    int freq[128];
    memset(freq, 0, sizeof(freq));

    for(int i = 0; i < a.length(); ++i) {
        freq[a[i]]++;
        freq[b[i]]--;
    }

    for(int i = 0; i < 128; ++i)
        if(freq[i] != 0)
            return false;
    return true;
}

int main() {
    // solution
    if(isPermutation("abcdefghijklmnopqrstuvwxyz", "qwertyuiopasdfghjklzxcvbn."))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}