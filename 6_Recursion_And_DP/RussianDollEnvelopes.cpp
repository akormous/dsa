#include<bits/stdc++.h>
using namespace std;

bool customCompare(vector<int> &e1, vector<int> &e2) {
    // compare the width,
    // if width are equal, then arrange them in descending order of height
    if(e1[0] == e2[0])
        return e1[1] > e2[1];
    // else ascending order of width
    return e1[0] < e2[0];
}
class Solution {
public:
    // you have to boil down this 2-D LIS to 1-D LIS
    // arrange the envelopes in increasing order of width
    // if width of 2 envs is same, then arrange them in descending order of height
    // why ? to disable them to be added to longest increasing subsequence,
    // because we cannot fit envelopes inside one another having same width
    // the bigger envelope has to be strictly greater than the other one
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n <= 1)  return n;
        
        sort(envelopes.begin(), envelopes.end(), customCompare);
        // LIS
        vector<int> seq;    // maintaining an sorted seq of height
        seq.push_back(envelopes[0][1]);
        
        for(int i = 1; i < n; ++i) {
            int curEnvHeight = envelopes[i][1];
            int lastSeqEnvHeight = seq.back();
            if(curEnvHeight <= lastSeqEnvHeight) {
                int idx = lower_bound(seq.begin(), seq.end(), curEnvHeight) - seq.begin();
                seq[idx] = curEnvHeight;
            }
            else {
                seq.push_back(curEnvHeight);
            }
        }
        
        return seq.size();
    }
};