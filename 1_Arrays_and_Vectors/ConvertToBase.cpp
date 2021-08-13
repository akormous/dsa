#include<bits/stdc++.h>
using namespace std;

/*
Question: Convert any base number (binary, octal, hexadecimal, base 64 etc.) to its decimal form (base 10)
*/

// return decimal representation of any base number
int convertToBase(string number, int base) {
    // check if base is less than 2
    if(base < 2)
        return -1;
    
    // length of string
    int n = number.length();
    int power = 0;
    int result = 0;
    // start from the last character in the string
    // exponentiate it and add to result
    for(int i = n - 1; i >= 0; i--) {
        // convert char to int
        int digit = number[i] - '0';
        // check if digit lies between 0 and base - 1
        if(digit < 0 || digit >= base) {
            return -1;
        }
        result += digit * pow(base, power++);
    }
    return result;
}


int main() {
    // solution

    cout<<convertToBase("111", 2)<<endl;
    return 0;
}