#include<bits/stdc++.h>
using namespace std;

/*

Swap two numbers by value, address, reference

*/

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout<<"In swap function"<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;
}

void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 78, b = 69;
    cout<<"Original values - "<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    cout<<endl;

    a = 78, b = 69;
    cout<<"Swap by value - "<<endl;
    swapByValue(a, b);
    cout<<"In main function"<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    cout<<endl;

    a = 78, b = 69;
    cout<<"Swap by reference - "<<endl;
    swapByReference(a, b);
    cout<<"a = "<<a<<" b = "<<b<<endl;
    cout<<endl;

    a = 78, b = 69;
    cout<<"Swap by address - "<<endl;
    swapByAddress(&a, &b);
    cout<<"a = "<<a<<" b = "<<b<<endl;

    return 0;
}