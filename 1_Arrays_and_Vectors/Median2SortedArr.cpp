#include<bits/stdc++.h>
using namespace std;
/**
 * youtube tutorial: https://www.youtube.com/watch?v=q6IEA26hvXc
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int total = A.size() + B.size();
        int half = total / 2;
        // ensure A is the smaller in size
        if(A.size() > B.size())
            A.swap(B);
        
        if(A.size() == 0) {
            int mid = total/2;
            if(total % 2 == 1)
                return B[mid];
            return (B[mid] + B[mid-1]) / 2.0;
        }
        
        int l = -1, r = A.size();
        while(true) {
            int i = (l + r)/2;      // A
            int j = half - i - 2;   // B
            
            int Aleft = (i >= 0 ? A[i] : INT_MIN );
            int Aright = (i+1 < A.size() ? A[i+1] : INT_MAX);   
            int Bleft = (j >= 0 ? B[j] : INT_MIN);
            int Bright = (j+1 < B.size() ? B[j+1] : INT_MAX);   
            // partition is correct
            if(Aleft <= Bright && Bleft <= Aright) {
                // odd
                if(total % 2 == 1)
                    return min(Aright, Bright);
                // even
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            // partition is incorrect
            else if(Aleft > Bright)
                r = i-1;
            else
                l = i+1;
        }
    }
};