#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/*

Recursive Multiply: Write a recursive function to multiply two positive integers without using the
*operator.You can use addition, subtraction, and bit shifting, but you should minimize the number
of those operations.

*/

// number of calls
int ct = 0;

ll multiplier(ll a, ll b) {
    ct++;
    if(b == 0 || a == 0)
        return 0;
    if(b == 1)
        return a;
    
    return a + multiplier(max(a, b-1), min(a, b-1));
}

ll multiply(ll a, ll b) {
    ll ans = multiplier(abs(a), abs(b));

    if(a < 0 && b < 0)
        return ans;
    else if(a < 0 || b < 0)
        return 0-ans;
    return ans;
}


int main() {
    // solution
    cout<<multiply(-88, 14)<<endl;
    cout<<"Number of recursive calls: "<<ct<<endl;
    return 0;
}