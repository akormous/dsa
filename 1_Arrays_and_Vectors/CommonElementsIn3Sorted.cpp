// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:    
    unordered_set<int> intersection(int x[], int y[], int p, int q)
    {
        unordered_set<int> s;
        // two pointer approach to find the intersection
        int i = 0, j = 0;
        
        while(i < p && j < q)
        {
            if(x[i] == y[j] && s.find(x[i]) == s.end())
            {
                s.insert(x[i]);
                i++; j++;
            }
            else if(x[i] > y[j])
                j++;
            else
                i++;
        }
        return s;
    }
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            // approach
            /*
                find intersection of first two arrays,
                then find the common elements in the intersection and the third array
                also check for duplicates
            */
            vector<int> answer;
            unordered_set<int> ab = intersection(A, B, n1, n2);
            unordered_set<int> tracker;
            
            for(int i = 0; i < n3; i++)
            {
                if( ab.find(C[i]) != ab.end() && tracker.find(C[i]) == tracker.end())
                {
                    answer.push_back(C[i]);
                    tracker.insert(C[i]);
                }
            }
            return answer;
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends