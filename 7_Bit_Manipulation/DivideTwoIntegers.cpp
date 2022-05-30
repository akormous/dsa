#include<bits/stdc++.h>
using namespace std;

// divide 2 integers without using /, *, % operators
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long dd = labs(dividend);
        long dv = labs(divisor);
        long ans = 0;
        while(dd >= dv) {
            long tmp = dv;
            int m = 1;
            while((tmp << 1) <= dd) {
                tmp = tmp << 1;
                m = m << 1;
            }
            dd = dd - tmp;
            ans += m;
        }
        return ans*sign;
    }
};