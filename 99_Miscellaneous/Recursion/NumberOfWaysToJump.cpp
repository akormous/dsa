/*
Given a staircase consisting of 'n' steps,
and you can only jump 1, 2 or 3 steps at a time.
Calculate the number of ways in which you can reach the destination (top of the staircase)
*/
#include<bits/stdc++.h>
using namespace std;

/*
The approach is to add 1,2 or 3 to cur_pos
base condition will be when cur_pos = n
*/
int climbStaircase(int n, int cur_pos) {
    if(cur_pos == n) {
        return 1;
    }
    if(cur_pos > n) {
        return 0;
    }
    return climbStaircase(n, cur_pos + 1) +
           climbStaircase(n, cur_pos + 2) +
           climbStaircase(n, cur_pos + 3);
}

/*
Another approach can be to move from the topmost step to 0
So we subtract 1,2 or 3 from n
with base conditions as n < 0 and n == 0
*/
int climbStaircase2(int n) {
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    
    return climbStaircase2(n - 1) + 
           climbStaircase2(n - 2) +
           climbStaircase2(n - 3);
}

int main() {
    int n = 5;
    int cur_pos = 0;
    cout<<"Number of ways in which you can climb the staircase = "<<climbStaircase(n, cur_pos)<<endl;
    return 0;
}