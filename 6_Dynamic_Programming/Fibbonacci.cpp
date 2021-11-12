#include<bits/stdc++.h>
using namespace std;


// recursive function that returns the nth number in fibbonacci series
int fib(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}


// using dynamic programming
int util(int n, int arr[]) {
    if(n == 0 || n == 1)  return n;
    

    if(arr[n] == 0) {
        arr[n] = util(n-1, arr) + util(n-2, arr);
    }
    return arr[n];
}
// top-down
int fib2(int n) {
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));

    return util(n, arr);

}


// bottom-up
int fib3(int n) {
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));

    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= n; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}
int main() {
    // solution

    for(int i = 0; i < 10; ++i)
        cout<<fib2(i)<<endl;
    return 0;
}