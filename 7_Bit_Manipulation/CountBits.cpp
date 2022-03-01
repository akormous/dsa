#include<bits/stdc++.h>
using namespace std;

/* Using the concept of Brian Kernighan's algorithm:
Number of set bits in n = number of set bits in (n & n-1) + 1

This is a DP question btw
*/
class Solution {
public:
    
    vector<int> countBits(int n) {
        
        vector<int> dp(n + 1,0);

        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i & (i-1)] + 1;
        }
        return dp;
    }
};

string toBinary(int n) {
    string s = bitset<8>(n).to_string();
    return s;
}

void print(vector<int> v) {
    for(int i = 0; i < v.size(); ++i)
        cout<< i << "\t" << v[i] << "\t" << toBinary(i) <<endl;
    cout<<endl;
    return;
}


int main() {

    Solution s;
    int n = 20;
    vector<int> dp = s.countBits(n);
    print(dp);

    return 0;
}