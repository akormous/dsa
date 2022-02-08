#include<bits/stdc++.h>
using namespace std;

/*
Given an integer num, 
repeatedly add all its digits 
until the result has only one digit, and return it.
*/

/* Pro Solution O(1) 
There is a thing called divisibility rule of 9,
if the sum of the digits is divisible by 9, the number is divisible by 9
*/
class Solution {
public:
    int addDigits(int num) {
        if(num == 0)
            return num;
        
        if(num%9 == 0)
            return 9;
        
        return num%9;
    }
};

/* Recursive Solution*/
class Solution2 {
public:
    int addDigits(int num) {
        if(num/10 == 0)
            return num;
        
        int nextNum = 0;
        while(num) {
            nextNum += num%10;
            num /= 10;
        }
        return addDigits(nextNum);
    }
};