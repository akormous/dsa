#include<bits/stdc++.h>
using namespace std;

/*

Question: Describe how can you use a single array
to implement 3 stacks ?

Approach:
Apart from the main storage array,
two more arrays will be required

k = number of stacks
n = size of storage array

top[k] - store the index of top element in each stack
next[n] - store the index of next entry in all stacks

*/

class MultiStack {
    int* arr;   // main array
    int* top;   // array that stores the top index of each stack
    int* next;  // array that stores the index of next free position in the main array
    int n, k;   // size of main array and number of stacks to implement
    int free;   // store the beginning index of free list

    public:
    // initialize the size and number of stacks
    MultiStack(int n, int k) {
        this -> n = n;
        this -> k = k;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        // initialize all stacks as empty
        for(int i = 0; i < k; i++)
            top[i] = -1;
        // initialize all spaces as free
        free = 0;   // first free space initially
        for(int i = 0; i < n - 1; i++)
            next[i] = i + 1;
        next[n - 1] = -1;   // last space is not free
    }

    // function that returns if the main array is Full or not
    bool isFull() {
        return (free == -1);
    }
    // function that returns if the stack represented by the stack number 'sn' is empty or not
    bool isEmpty(int sn) {
        return (top[sn] == -1);
    }
    // sn: stack number
    // push an element to a given stack number
    void push(int data, int sn) {
        if(isFull()) {
            cout<<"STACK OVERFLOW"<<endl;
            return;
        }
        // get the free space
        int i = free;
        // update the free space to the next free space
        free = next[i];

        // update the next of top of the given stack sn
        next[i] = top[sn];
        // update the top of the stack
        top[sn] = i;
        // update the data in the main array
        arr[i] = data;
    }
    // pop an element from a given stack sn
    int pop(int sn) {
        if(isEmpty(sn)) {
            cout<<"EMPTY STACK!"<<endl;
            return INT_MAX;
        }

        // find the topmost element
        int i = top[sn];
        // update the top to the next element
        top[sn] = next[i];

        next[i] = free;

        free = i;
        return arr[i];
    }
    // print the stack
    void print(int sn) {
        if(isEmpty(sn)) {
            cout<<"EMPTY STACK!"<<endl;
            return;
        }
        int j = top[sn];
        cout<<arr[j]<<" ";
        j = next[j];
        while(j != -1) {
            cout<<arr[j]<<" ";
            j = next[j];
        }
        cout<<endl;
    }

    void printArray() {
        cout<<endl<<"Top"<<endl;
        for(int i = 0; i < k; i++) {
            cout<<top[i]<<" ";
        }
        cout<<endl<<"Arr"<<endl;
        for(int i = 0; i < n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl<<"Next"<<endl;
        for(int i = 0; i < n; i++) {
            cout<<next[i]<<" ";
        }
        cout<<endl;
    }

    void printAllStacks() {    
        cout<<"STACK 1"<<endl;
        this -> print(0);
        
        cout<<"STACK 2"<<endl;
        this -> print(1);
        
        cout<<"STACK 3"<<endl;
        this -> print(2);
    }
};

int main() {
    // testing for 3 stacks
    MultiStack m(15, 3);
    // pushing 3 elements in first stack
    m.push(1, 0);
    m.push(2, 0);
    m.push(3, 0);
    // pushing 10 elements in second stack
    m.push(2, 1);
    m.push(2, 1);
    m.push(2, 1);
    m.push(2, 1);
    m.push(2, 1);
    m.push(2, 1);
    m.push(2, 1);
    m.push(2, 1);
    m.push(2, 1);
    m.push(2, 1);

    // pushing 5 elements in third stack
    m.push(3, 2);
    m.push(3, 2);
    m.push(3, 2);
    m.push(3, 2);
    m.push(3, 2);

    m.printAllStacks();

    // popping seven elements from stack number 2
    m.pop(1);
    m.pop(1);
    m.pop(1);
    m.pop(1);
    m.pop(1);
    m.pop(1);
    m.pop(1);
    m.printAllStacks();

    //m.printArray();
    return 0;
}