#include<bits/stdc++.h>
using namespace std;

/*
Given a sorted array, remove duplicates in-place such that
each unique element can appear at most twice
*/
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        // a reader pointer
        int rp = 0;
        // a writer pointer
        int wp = 0;
        
        int n = arr.size();
        
        if(n == 1)    return 1;
        
        // while reader pointer is in bounds
        while(rp < n) {
            // set current element to read val
            int cur = arr[rp];
            
            // write the first number (possibly from a sequence of duplicates, or not)
            arr[wp] = arr[rp];
            // if rp and rp + 1 are equal
            if(rp + 1 < n && arr[rp] == arr[rp+1]) {
                // write at cur and move 
                arr[wp++] = cur;
                // write at 2nd pos and move
                arr[wp++] = cur;
                
                // find the number which is different from the current element
                while(rp < n && arr[rp] == cur)
                    rp++;
            }
            // write and move
            else {
                arr[wp++] = arr[rp++];
            }
        }
        
        return wp;          
    }
};