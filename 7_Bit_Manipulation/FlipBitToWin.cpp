#include<bits/stdc++.h>
using namespace std;
/*

Question: Given a binary string and only 1 bit to flip.
Write code to find the length of the longest sequence of 1s you could create.

Approach - 
Keep track of the length of
current sequence of 1s
previous sequence of 1s

When we see a 0, check if we can merge these 2 sequences ?
How can we merge ?
If there is only one 0 between the current sequence and previous sequence

We can start from any end if an array is given



*/

// input: an integer
// output: length of the longest sequence of 1s obtained by flipping 1 bit
int flipBit(int num) {
    int prevLen = 0, curLen = 0, maxLen = 0;

    while(num != 0) {
        // if LSB is 1
        if(num & 1 == 1)
            curLen++;
        
        // else if LSB is 0
        else if(num & 0 == 1) {
            // check if the next bit is 1,
            // 1110 & 10 = 1
            // 10 is 2 in binary
            // the bitwise & operation always compares the LSBs
            prevLen = num & 2 == 0 ? 0 : curLen;

            // reset the sequence
            curLen = 0;
        }
        maxLen = max(prevLen + curLen, maxLen);

        // right shift by 1 bit
        num = num >> 1;
    }
}

// returns the length of the longest sequence of 1s after flipping 1 bit
// input: array of bits, length of the array
int findLongestSequence(bool arr[], int n) {
    int prevLen = 0, curLen = 0, maxLen = 0;

    for(int i = 0; i < n-1; ++i) {
        if(arr[i])
            curLen++;
        else {
            
            prevLen = arr[i + 1] ? curLen : 0;

            curLen = 0;

        }
        maxLen = max(prevLen + curLen, maxLen);
    }
    return maxLen + 1;
}


int main() {
    bool arr[] = {1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Length of the longest sequence of 1s = "
         << findLongestSequence(arr, n);
    return 0;
}