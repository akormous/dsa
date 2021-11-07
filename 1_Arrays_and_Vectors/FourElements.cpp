// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}// } Driver Code Ends


bool find4Numbers(int A[], int n, int X)  
{
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
        m[A[i]]++;
        
    for(int i = 0; i < n; ++i) {
        m[A[i]]--;
        for(int j = i + 1; j < n; ++j) {
            m[A[j]]--;
            for(int k = j + 1; k < n; k++) {
                m[A[k]]--;
                if(m.find(X - A[i] - A[j] - A[k]) != m.end() && m[X - A[i] - A[j] - A[k]] > 0)
                    return true;
                m[A[k]]++;
            }
            m[A[j]]++;
        }
        m[A[i]]++;
    }
    return false;
}