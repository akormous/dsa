#include<bits/stdc++.h>
using namespace std;


/*

Question: 
Given a number, find its next smallest and next largest number
having the same number of set bits.

Approach:

NEXT BIGGER NUMBER

Find the rightmost 0, which has a 1 to the right of it

For ex.

idx - 7 6 5 4 3 2 1 0
bit - 1 0 0 0 1 1 1 0

In the given binary number, 0 at index 4 is the rightmost zero which has a 1 to the right of it

Flip this zero

idx - 7 6 5 4 3 2 1 0
bit - 1 0 0 1 1 1 1 0

But now the number of 1s are increased by 1.
Now we have to minimize the bits to the right of index 4 (flipped 0)
Minimizing means - move all the 1s to the right
Simply clear all the bits to the right of flipped 0

Let the number of 1s to the right of flipped 0 = p
then we have to fill p-1 1s from the right

NOTE: If a number is like 11111 then technically it is ..011111, assume zeroes are prefixed
*/

bool getBit(int num, int i) {
    return (num & (1 << i)) != 0;
}

int setBit(int num, int i, bool val) {
    if(val)
        return (num | (1 << i));
    return (num & ~(1 << i));
}

int clearBitsMSBTo0(int num, int i) {
    return (num & (-1 << (i)));
}

int nextBigger(int num) {
    // find the rightmost 0 which has a 1 to the right of it
    int i = 0;
    int right_1_count = 0;
    // go through the trailing zeroes
    while(!getBit(num, i))
        i++;
    // count the number of 1s
    while(getBit(num, i)) {
        right_1_count++;
        i++;
    }
    // flip this zero bit
    num = setBit(num, i, 1);

    // clear all the bits from the right of i till index 0
    num = clearBitsMSBTo0(num, i);

    // fill up bits from the right, how many bits ? right_1_count - 1
    int seq1s = ~(-1 << (right_1_count-1));

    num = num | seq1s;

    return num;
}

int nextSmaller(int num) {
    // find the rightmost 1 which has a 0 to the right of it
    int i = 0;
    int right_1_count = 0;

    // go through trailing 1s
    while(getBit(num, i)) {
        right_1_count++;
        i++;
    }

    // go through the zeros
    while(!getBit(num, i))
        ++i;
    
    // flip this one bit
    num = setBit(num, i, 0);

    // clear all the bits to the right of i till index 0
    num = clearBitsMSBTo0(num, i);

    // add right_1_count + 1 bits immediately to the right of i
    i--;
    right_1_count++;
    while(right_1_count) {
        num = setBit(num, i, 1);
        i--;
        right_1_count--;
    }
    return num;
}

int main() {
    // solution
    cout<<nextBigger(5)<<"\t"<<nextSmaller(5)<<endl;
    cout<<nextBigger(11)<<"\t"<<nextSmaller(11)<<endl;
    cout<<nextBigger(16)<<"\t"<<nextSmaller(16)<<endl;
    cout<<nextBigger(6)<<"\t"<<nextSmaller(6)<<endl;
    return 0;
}