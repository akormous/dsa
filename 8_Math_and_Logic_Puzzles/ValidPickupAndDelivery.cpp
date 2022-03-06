#include<bits/stdc++.h>
using namespace std;

/*
Number of ways the pickups can be arranged = n!

Lets say the pickups are ordered like this

p1, p2, p3

Now, for delivery 3, there is only one valid slot (which is at the end)

p1, p2, p3, d3

For  delivery 2, there are three valid slots

p1, p2, d2, p3, d3
p1, p2, p3, d2, d3
p1, p2, p3, d3, d2

Similarly, for delivery 1, there are five valid slots
So, total permutations =

n! * (1 * 3 * 5 * ... * (2n-1))
*/

class Solution {
public:
    int countOrders(int n) {
        long long res = 1, cap = 1000000007;

        // number of permutations of arranging pickups = n!
        for(int i = 1; i <= n; ++i) {
            res = (res * i)%cap;
        }

        // number of ways to order deliveries = 1 * 3 * 5 * 7 * .... * (2n - 1)
        for(int i = 1; i < 2*n; i+=2) {
            res = (res * i)%cap;
        }
        return res;
    }
};