#include<bits/stdc++.h>
using namespace std;

/*
Question: Check if a string has all unique characters (without using additional DS)

1. Use an integer as a bit checker
2. Calculate the index of a character with respect to 'a'
3. Set that index bit to 1 in the checker
4. If that bit is already set, then return false

NOTE: This will work if string contains a-z
For more characters coverage, use a larger data type like long long int

*/

bool isUnique(string s) {
    // checker for characters
    // by default int consists of 32 bits
    int checker = 0;

    // traverse each character in the string
    for(int i = 0; i < s.length(); i++) {
        int bitOffset = s[i] - 'a';

        // check if the bit corresponding to this character is set
        if((checker & (1 << bitOffset)) > 0)
            return false;
        
        // set the bit
        checker = checker | ( 1 << bitOffset );
    }
    return true;
}

int main() {
    // solution
    if(isUnique("abadc")) {
        cout<<"Yes";
    }
    else {
        cout<<"No";
    }
    cout<<endl;
    return 0;
}