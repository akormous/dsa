/*
Calculate x ^ n in the most efficient way possible
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
// return x ^ n
ll power(int x, int n) {
    if(n == 0)
        return 1;
    // if n is odd
    if(n&1)
        return x * power(x, n/2) * power(x, n/2);
    // if n is even
    else
        return power(x, n/2) * power(x, n/2);
}

int main() {
    int x = 2;
    int n = 10;
    cout<<x<<" ^ "<<n<<" = "<<power(x, n);
    return 0;
}