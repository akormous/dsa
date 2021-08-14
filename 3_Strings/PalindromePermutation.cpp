#include<bits/stdc++.h>
using namespace std;

/*

Question: Check if a string is a permutation of a palindrome

forexample.
Tact coa
is a permutation of a palindrome
Taco cat

*/

/*
Palindrome is a string that is read same backwards and forwards

Input -
- can contain Upper Case and Lower Case letter
- can contain whitespaces
- can contain ASCII characters

Approach -
- Remove all whitespaces
- convert to lowercase or uppercase

tactcoa
NOTE: if the string contains odd number of characters,]
      then there will be one character which wont make any pair
      else
      all of the letters should form a pair

- Create a freq table
- Populate the freq
- Check if it is balanced
    in case of odd characters, freq of one element can be an odd number
    in case of even characters, everything should be even

Time Complexity - O(N)
Space Complexity - O(1) because the character set can be constant ? ASCII or Unicode
*/

string removeWhiteSpaces(string s) {
    // removing all whitespaces
    int i = 0;
    while(i < s.length()) {
        if(s[i] == ' ')
            s.erase(s.begin() + i);
        else 
            i++;
    }
    return s;
}

bool isPalindromePermutation(string s) {
    if(s.length() < 2)
        return false;
    // remove whitespaces
    s = removeWhiteSpaces(s);
    
    // covert to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    

    // create a freq table
    int freq[128];
    memset(freq, 0, sizeof(freq));

    // traverse the string and update frequencies
    for(int i = 0; i < s.length(); i++) {
        freq[s[i]]++;
    }

    // incase if the number of characters in the string are odd
    // then a flag will keep track of the if that character is checked or not
    bool pe = false;
    for(int i = 0; i < 128; i++) {
        if(freq[i] % 2 != 0) {
            if(pe == false)
                pe = true;
            else
                return false;
        }
    }
    return true;
}


int main() {
    // solution
    if(isPalindromePermutation("C a R e C a R    "))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}