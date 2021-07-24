#include<bits/stdc++.h>
using namespace std;

/*
STACK - Last in first out...ez

TIME COMPLEXITY - Only top element can be accessed
    Access - O(1)
    Deletion - O(1)
    Insertion - O(1)
    Search - O(n)
*/

class CustomStack {
    vector<int> st; // used a vector for quicker implementation
    public:
    bool empty() {
        return (st.size() == 0);
    }
    int pop() {
        vector<int>::iterator it = (st.end() - 1);
        int tmp = *it;
        st.erase(it);
        return tmp;
    }
    void push(int val) {
        st.push_back(val);
        return;
    }
    int top() {
        return st[st.size() - 1];
    }
};

int main() {
    CustomStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<"Pushed 5 elements to the stack"<<endl;
    cout<<"Top element - "<<st.top()<<endl;
    cout<<"Popping 2 elements"<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<"Is stack empty ? - "<<st.empty()<<endl;
    cout<<"Top element - "<<st.top()<<endl;
    return 0;
}