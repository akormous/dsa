#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        // frequency array
        vector<long> freq(101, 0);
        
        long result = 0;
        int mod = 1000000007;
        
        for(auto num : arr)
            freq[num]++;
        
        for(int i = 0; i <= 100; ++i) {
            
            for(int j = 0; j <= 100; ++j) {
                
                int a = i;
                int b = j;
                int c = target - a - b;
                
                if(c < 0 || c > 100 || freq[c] == 0) continue;
                
                if(a == b && b == c) {
                    // number of ways to choose 3 from freq[a] (nC3) Combination formula
                    long n = freq[a];
                    result += n * (n-1) * (n-2) / 6;
                }
                else if(a == b && b != c) {
                    // number of ways to choose 2 from freq[a] (nC2) Combination formula
                    long n = freq[a];
                    result += n * (n-1) * freq[c] / 2;
                }
                else if(a < b && b < c) {
                    result += freq[a] * freq[b] * freq[c];
                }
            }
        }
        return (result % mod);
    }
};