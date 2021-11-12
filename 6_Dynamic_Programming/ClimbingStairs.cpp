#include<bits/stdc++.h>
using namespace std;

/*

Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
steps at a time. Implement a method to count how many possible ways the child can run up the
stairs.


Approach:
Try to run some cases when n = 1, 2, 3
In how many ways 1 2 or 3 steps can be hopped

Try to make a recursive call for n > 3

Try to come up with a caching solution Dynamic Programming

*/

int utility(int n, int arr[]) {
    if(n == 0 || n == 1 || n == 2)
        return n;
    
    if(arr[n] == 0)
        arr[n] = utility(n-1, arr) + utility(n-2, arr) + utility(n-3, arr);
    
    return arr[n];
}

int numberOfWays(int n) {
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));

    return utility(n, arr);
}

int main() {
    // solution
    for(int i = 0; i < 17; i++)
        cout<<numberOfWays(i)<<endl;
    return 0;
}