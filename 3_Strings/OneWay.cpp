#include<bits/stdc++.h>
#include<math.h>
using namespace std;

/*
Question: Check if a string is one or zero edits away
Edits can be-
1. Insert a character
2. Remove a character
3. Replace a character

Approach -
There are 3 types of checks that we need to handle
replacement check
insertion check
removal check
NOTE: insertion and removal check are same
NOTE: insertion and replacement check are also very similar

To decide which condition to check we can compare the lengths of the strings
if length of the strings are equal then do a replacement check
if a.length() - 1 = b.length() then do a insertion check and vice versa is also the same


A flag variable is enough to detect one difference in the string

case: replacement

queen
quein

i = 0, j = 0
Queen
Quein

i = 1, j = 1
qUeen
qUein

i = 2, j = 2
quEen
quEin

(difference found-  set flag)
i = 3, j = 3
queEn
queIn

in case of equal length of strings, move the pointer 
else in case of unequal length of string, do not move the pointer of shorter string

*/

bool oneWay(string a, string b) {
    // if difference in length of strings is greater than 1
    if(abs(int(a.length() - b.length())) > 1)
        return false;
    // considering a to be the shorter string
    if(a.length() > b.length())
        swap(a, b);
    
    bool foundDifference = false;
    int i = 0, j = 0;
    while(i < a.length() && j < b.length()) {
        // if the characters are unequal
        if(a[i] != b[i]) {
            if(foundDifference)
                return false;
            foundDifference = true;
            // if strings are of equal length
            // move the pointer of shorter string
            if(a.length() == b.length())
                i++;
        }
        // if characters are matching
        else
            i++;
        // always move pointer of longer string
        j++;
    }
    return true;
}

int main() {
    // solution
    if(oneWay("ba","aac"))
        cout<<"Yes";
    else 
        cout<<"No";
    return 0;
}