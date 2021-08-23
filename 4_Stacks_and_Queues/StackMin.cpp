#include<bits/stdc++.h>
using namespace std;

/*

Question: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.


Approach: use another stack at top which will be the minimum element at that point
*/

// a class that implements basic stack + a function min, which given the minimum element
// in the stack in O(1) time
class CustomStack {
    stack<int> st;
    stack<int> minStack; // stores the minimum value on each push
    public:
    void push(int data) {
        // if initially stack is empty, then push whatever data is sent
        if(st.empty()) {
            minStack.push(data);
        }
        // else if stack is non empty
        else {
            // compare the topmost element of min to the data, and check which is smaller
            if(data < minStack.top()) {
                minStack.push(data);
            }
            else {
                minStack.push(minStack.top());
            }
        }
        // push the data to the stack
        st.push(data);
    }
    // pop the topmost element from the stack as well as minStack
    void pop() {
        st.pop();
        minStack.pop();
    }
    // function that returns the minimum element in the stack
    int min() {
        return minStack.top();
    }
    // function that returns the topmost element in the stack
    int top() {
        return st.top();
    }
};

int main() {
    CustomStack st;
    st.push(-121);
    st.push(256);
    st.push(312);
    st.push(144);
    st.push(1080);
    st.push(1920);
    st.push(-1980);
    st.push(42);

    cout<<"Minimum element in the stack = "<<st.min()<<endl;

    st.pop();
    st.pop();

    cout<<"Minimum element in the stack = "<<st.min()<<endl;


    return 0;
}