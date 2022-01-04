#include<bits/stdc++.h>
using namespace std;

/*
Return a bitwise complment of an integer

for example:
5 = 101
Ans = 010 = 2

7 = 111
Ans = 000 = 0

Logic:
There are a number of ways to do this,
first is to right shift each bit, flip it and add it to result

second is to create a mask
Can we do an XOR operation with this mask to get the result ?
What should the mask be ?

Basic property of XOR:
1 ^ 1 = 0
1 ^ 0 = 1

so if we XOR each bit by 1, it gets flipped, so create a mask which is just greater than the given integer 
mask = 0;
while(mask < n)
    mask = mask << 1 | 1;

return n ^ mask;
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while(mask < n )
            mask = mask << 1 | 1;
        
        return n ^ mask;
    }
};