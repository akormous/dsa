#include<bits/stdc++.h>
using namespace std;

/*

Question: What does the following code do ?

(n & (n-1)) == 0

Lets do some dry run

N   BIN     N-1     N & (N-1)   
0 = 0000    
1 = 0001    0000    0000    0   ZERO
2 = 0010    0001    0000    0   ZERO
3 = 0011    0010    0010    2
4 = 0100    0011    0000    0   ZERO
5 = 0101    0100    0100    4
6 = 0110    0101    0100    4
7 = 0111    0110    0110    6
8 = 1000    0111    0000    0   ZERO
9 = 1001    1000    1000    8
10= 1010    1001    1000    8
11= 1011    1010    1010    10
12= 1100    1011    1000    8
13= 1101    1100    1100    12
14= 1110    1101    1100    12
15= 1111    1110    1110    14
16= 10000   01111   00000   0   ZERO

If you are not a chimp,
you can clearly observe that 
(N & N-1 = 0) when (N = 2^x)

So, this piece of code tells you if a given number is a power of 2
*/

bool isPowerOf2(int num) {
    return (num & (num - 1)) == 0;
}

int main() {
    
    cout<<isPowerOf2(2)<<endl;
    cout<<isPowerOf2(3)<<endl;
    cout<<isPowerOf2(4)<<endl;
    cout<<isPowerOf2(16)<<endl;
    cout<<isPowerOf2(254)<<endl;
    cout<<isPowerOf2(256)<<endl;
    cout<<isPowerOf2(511)<<endl;
    cout<<isPowerOf2(512)<<endl;


    return 0;
}