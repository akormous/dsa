#include<bits/stdc++.h>
using namespace std;

/*

Question: Check if a string is a permutation of a palindrome

forexample.
Tact coa
is a permutation of a palindrome
Taco cat

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

string toLowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

/*

Best Approach - Bit vector
in a palindrome the frequency of each character should be even,
this can be checked by using a bit vector as on-off machine
initially all of them are off,
so if the frequency of all characters is even
then all of them should be off in the final state

except when the length of the string is odd,
so only 1 can remain toggled

NOTE: always keep in mind the character set of the string, ASCII or Unicode
For now, i am considering only a - z

Bit toggle - xor

*/

void toggle(int &bitVector, char c) {
    bitVector = bitVector ^ (1 << (c - 'a'));
}

bool isPalindromePermutation(string s) {
    cout<<"Bit vector implementation"<<endl;
    // remove all whitespaces
    s = removeWhiteSpaces(s);

    // convert string to lowercase
    s = toLowerCase(s);

    // an int bit vector can handle upto 32 characters
    // initially all bits are off
    int bitVector = 0;
    // traverse each character in the string and toggle it
    for(int i = 0; i < s.length(); i++)
        toggle(bitVector, s[i]);
    
    return bitVector == 0 || (bitVector & (bitVector - 1)) == 0;
}


/*
Palindrome is a string that is read same backwards and forwards

Input -
- can contain Upper Case and Lower Case letter
- can contain whitespaces
- can contain ASCII characters

Approach - Using a frequency table
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

void getFrequency(int freq[], string s) {
    // traverse the string and update frequencies
    for(int i = 0; i < s.length(); i++) {
        freq[s[i]]++;
    }
}

bool isPalindromePermutation2(string s) {
    // empty string
    if(s.length() < 1)
        return false;

    // only one character
    if(s.length() == 1)
        return true;
    
    // remove whitespaces
    s = removeWhiteSpaces(s);
    // covert to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    // create a freq table
    int freq[128];
    memset(freq, 0, sizeof(freq));

    // get frequencies
    getFrequency(freq, s);

    // incase if the number of characters in the string are odd
    // then a flag will keep track of the if that character is checked or not
    bool pe = false;
    for(int i = 0; i < 128; i++) {
        if(freq[i] % 2 != 0) {
            // if the string length is odd
            if( (s.length() % 2) != 0 && !pe) {
                pe = true;
            }
            // else freq is not even
            else 
                return false;
        }
    }
    return true;
}


int main() {
    // solution
    if(isPalindromePermutation("A b R B adf sf  h d s h r"))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}