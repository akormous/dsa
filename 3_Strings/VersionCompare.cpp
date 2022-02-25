#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int compareVersion(string v1, string v2) {
        // create a integer number from the versions
        // ignore the zeroes and dot
        
        int i=0, j=0;
        int n1 = v1.length(), n2 = v2.length();
        
        int num1 = 0, num2 = 0;
        
        while(i < n1 || j < n2) {
            // create number till each dot
            while(i < n1 && v1.at(i) != '.') {
                num1 = num1*10 + (v1.at(i) - '0');
                i++;
            }
            
            while(j < n2 && v2.at(j) != '.') {
                num2 = num2*10 + (v2.at(j) - '0');
                j++;
            }
            
            if(num1 < num2)
                return -1;
            
            if(num1 > num2)
                return 1;
            
            i++;
            j++;
            
            num1 = 0;
            num2 = 0;
        }
        
        return 0;
            
    }
};