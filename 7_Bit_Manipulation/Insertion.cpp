/*
Insertion:  You  are  given  two  32-bit  numbers,  N  and  M,  and  two  bit  positions,  i  and 
j. Write  a  method  to  insert  M  into  N  such  that  M  starts  at  bit  j  and  ends  at  bit  i.  You
can  assume  that  the  bits  j  through  i  have  enough  space  to  fit  all  of  M.  That  is,  if
M = 10011,  you can assume that there are at  least 5 bits  between  j  and i. You would  not, for
example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
EXAMPLE 
Input:  N  10000000000,  M 10011,  i  2,  j  6
Output: N  =  10001001100 
*/

/*

Approach: left shift M by i, than logical OR with N

*/

#include<bits/stdc++.h>
using namespace std;

string numToBinary(int n) {
    string result = "";
    while(n > 0) {
        result = to_string(n%2) + result;
        n /= 2;
    }
    if(n < 0) {
        result = "1" + result;
    }
    return result;
}

// returns a mask that will clear bits from j to i
int getMask(int i, int j) {
    return (-1 << j) | (~(-1 << i));
}

// inserts M into N from position j to i
int insertion(int N, int M, int i, int j) {
    // clear bits from j to i
    int mask = getMask(i, j);
    N = N & mask;

    return N | (M << i);
}

int main() {
    int N = 1024;
    int M = 19;
    int i = 2;
    int j = 6;

    cout<<insertion(N, M, i, j)<<endl;
    
    cout<<numToBinary(N)<<endl;
    cout<<numToBinary(M)<<endl;
    cout<<numToBinary(insertion(N, M, i, j))<<endl;
    return 0;
}