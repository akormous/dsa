/*
I/P: 431
O/P: Four Three One
Do this using recursion
*/
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, string> dict = {{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"},
                                {4, "Four"}, {5, "Five"}, {6, "Six"},
                                {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};

void printSpelling(int n) {
    if(n == 0)
        return;
    printSpelling(n/10);
    cout<<dict[n % 10]<<" ";
}

int main() {
    int n = 4314253;
    printSpelling(n);
    return 0;
}