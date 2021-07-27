#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n, k;
        cin>>n>>k;
        ll x = pow(2,n);
        ll result = min<ll>(2*k, x) * (x - 1);
        cout<<result<<endl;
    }
    return 0;
}