/*
This is a codechef problem
Problem code - ARRT
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void printCSequence(int ans, vector<int> a, vector<int> b, int n) {
    int term = 0;
    for(int i = 0; i < n; i++) {
        term = (a[i] + b[ans]) % n;
        cout<<term<<" ";
        ans = (ans+1)%n;
    }
    cout<<endl;
}

vector<int> createCSequence(vector<int> a, vector<int> b, int id) {
    int n = a.size();
    vector<int> result;
    // index for array a
    int cnt = 0;
    // move from that id till n
    for(int i = id; i < n; i++) {
        result.push_back((a[cnt++] + b[i]) % n);
    }
    // move from 0th index till id - 1
    for(int i = 0; i < id; i++) {
        result.push_back((a[cnt++] + b[i]) % n);
    }
    return result;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin>>a[i];
        for(int i = 0; i < n; i++)
            cin>>b[i];
        /*
        Find the minimum 2 values in C[i],
        lets caint the starting index of these 2 sequences as p and q
        */
        int id1 = -1, id2  = -1;
        // traverse the array and find the minimum value of c
        int min_c = INT_MAX;
        for(int i = 0; i < n; i++) {
            min_c = min((a[0] + b[i]) % n, min_c);
        }
        // traverse one more time to track the index of minimum c values
        for(int i = 0; i < n; i++) {
            if((a[0] + b[i]) % n == min_c) {
                if(id1 == -1) {
                    id1 = i;
                }
                else {
                    id2 = i;
                    break;
                }
            }
        }
        // creating vectors for 2 sequences 
        vector<int> seq1, seq2;
        seq1 = createCSequence(a, b, id1);
        if(id2 != -1) {
            seq2 = createCSequence(a, b, id2);
            if(seq2 < seq1)
                swap(seq2, seq1);
        }
        // print seq 1
        for(int i = 0; i < n; i++) {
            cout<<seq1[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}