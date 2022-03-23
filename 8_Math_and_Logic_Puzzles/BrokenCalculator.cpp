#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brokenCalc(int start, int target) {
        int result = 0;
        
        
        while(target > start) {
            
            if(target%2 == 1)
                target = target + 1;
            else
                target = target / 2;
            result++;
            
        }
        
        return result + start - target;
    }
};