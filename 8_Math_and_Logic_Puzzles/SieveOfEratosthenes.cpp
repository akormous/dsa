#include<bits/stdc++.h>
using namespace std;

vector<int> generatePrimes(int max) {
    // create a boolean array of size max+1
    bool arr[max + 1];
    // set all the elements as false
    memset(arr, 0, sizeof(arr));

    // Sieve of Eratosthenes
    // 0 = prime
    // 1 = non-prime
    int i = 2;
    while(i <= sqrt(max)) {
        if(arr[i] == 0) {
            int j = 2*i;

            while(j <= max) {
                arr[j] = 1;
                j += i;
            }
        }
        i++;
    }

    // store all of the prime numbers in a vector
    vector<int> result;
    for(i = 2; i <= max; ++i)
        if(arr[i] == 0)
            result.push_back(i);
    
    return result;
}

void display(vector<int> arr) {
    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
}

int main() {
    // solution

    vector<int> myPrimes = generatePrimes(50);

    display(myPrimes);

    return 0;
}